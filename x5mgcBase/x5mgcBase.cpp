// x5mgcBase.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "bSocket.h"
#include <iostream>
#include <Windows.h>
#include <plog/Log.h>
#include <string>
#include "x5MGCConnection.h"
#include "service.h"
#include "ActiveMain.h"
//#include <vld.h>
#include "MyRSA.h"



std::string GetProgramDir()
{
	char exeFullPath[MAX_PATH];
	std::string strPath = "";
	GetModuleFileNameA(NULL, exeFullPath, MAX_PATH);
	strPath = (std::string)exeFullPath;    // Get full path of the file
	int pos = strPath.find_last_of('\\', strPath.length());
	return strPath.substr(0, pos + 1);  // Return the directory without the file name   
}
void initPlog()
{
	std::string strExePath = GetProgramDir();
	strExePath += "x5MGCLog_";
	strExePath += std::to_string(time(NULL));
	strExePath += ".txt";
	plog::init(plog::debug, strExePath.c_str());
}

int main(int argc, char *argv[])
{
	//int lenreturn = 0;
	//MyRSA::encryptRSAbyPublickey("123456", &lenreturn);
	//return -1;
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != NO_ERROR) {
		return -1;
	}
	initPlog();
	TCHAR filePath[MAX_PATH] = { 0 };//程序当前路径
	GetModuleFileName(NULL, filePath, MAX_PATH);
	if (argc == 2)
	{
		
		if (!strcmp(argv[1], "-install"))
		{
			if (service::ServiceInstall(filePath) != TRUE) 
			{
				LOG_INFO << TEXT("ServiceInstall ERROR");
			}
		}
		else if (!strcmp(argv[1], "-unstall"))
		{
			if (service::ServiceUnstall(filePath) != TRUE)
			{
				LOG_INFO << TEXT("ServiceUnstall ERROR");
			}
		}
		else if (!strcmp(argv[1], "-test"))
		{
			ActiveMain main;
			main.run();
			int i = 0;
			i++;
		}
	}
	else 
	{
		SERVICE_TABLE_ENTRY serviceTable;
		serviceTable.lpServiceName = (PTCHAR)SERVICE_NAME;
		serviceTable.lpServiceProc = service::ServiceMain;
		StartServiceCtrlDispatcher(&serviceTable);
	}
	WSACleanup();
    std::cout << "Hello World!\n"; 
}
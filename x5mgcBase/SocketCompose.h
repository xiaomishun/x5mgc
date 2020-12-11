#pragma once
#include "MChar.h"
// 通用
typedef struct MSGCOMMON 
{
	size_t len;
	size_t checknum;
}*LPMSGCOMMON;

typedef struct FD_INFO 
{
	MChar pBuffer;
}*LPFD_INFO;

class SocketCompose
{
public:
	SocketCompose();
	~SocketCompose();
private:
	//处理分包
	int long_hBuffer(FD_INFO * arg, const char * pBuffer, size_t Size);
public:
	//处理时调用
	virtual int split_hBuffer(FD_INFO * arg,const char *pBuffer, size_t Size);
	virtual int complete_hBuffer(FD_INFO * arg,const char * pBuffer, size_t Size);
};


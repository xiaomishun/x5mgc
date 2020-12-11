#include "pch.h"
#include "SocketCompose.h"


SocketCompose::SocketCompose()
{
}


SocketCompose::~SocketCompose()
{
}

int SocketCompose::long_hBuffer(FD_INFO * arg, const char * pBuffer, size_t Size)
{
	size_t len_t = 0;
	do
	{
		LPMSGCOMMON pHead = (LPMSGCOMMON)(pBuffer + len_t);
		if (pHead->len < 12 && pHead->len>0x8000) 
			return -1;
		if ((len_t + pHead->len) > Size) break;
		int rVal = complete_hBuffer(arg, pBuffer + len_t, pHead->len + sizeof(MSGCOMMON));
		if (rVal == -1) return -1;
		len_t += pHead->len + sizeof(MSGCOMMON);
	} while (len_t < Size);
	if (len_t == Size) {
		arg->pBuffer.Zero(); return len_t;
	}
	else if (len_t < Size) {
		arg->pBuffer.LoadChar(pBuffer + len_t, Size - len_t);
	}
	return 0;
}

int SocketCompose::split_hBuffer(FD_INFO * arg,const char * pBuffer, size_t Size)
{
	LPMSGCOMMON pHead = (LPMSGCOMMON)pBuffer;
	if (pHead->len + sizeof(MSGCOMMON) == Size) 
	{
		if (arg->pBuffer.size() != 0) {
			arg->pBuffer.Zero();
			return -1;
		}
		return this->complete_hBuffer(arg, pBuffer, Size);
	}
	else
	{
		if (arg->pBuffer.size() == 0) {
			return long_hBuffer(arg, pBuffer, Size);
		}
		else {
			arg->pBuffer.AddChar(pBuffer, Size);
			return long_hBuffer(arg, arg->pBuffer.GetBuffer(), arg->pBuffer.size());
		}
	}
	return 0;
}

int SocketCompose::complete_hBuffer(FD_INFO * arg,const char * pBuffer, size_t Size)
{

	return 0;
}

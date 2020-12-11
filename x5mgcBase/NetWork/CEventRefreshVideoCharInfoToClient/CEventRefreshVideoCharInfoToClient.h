#pragma once
#include "../Utils.h"
#include "VideoCharInfo.h"
class CEventRefreshVideoCharInfoToClient :public ProtoBufSerializable
{
public:
	CEventRefreshVideoCharInfoToClient();
	~CEventRefreshVideoCharInfoToClient();
	virtual void * operator[](string name);
public:
	VideoCharInfo info;
private:

};


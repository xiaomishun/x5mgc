#pragma once
#include "../Utils.h"

class CEventGetVideoPlayerInfo :public ProtoBufSerializable
{
public:
	CEventGetVideoPlayerInfo();
	~CEventGetVideoPlayerInfo();
	virtual void * operator[](string name);
public:
	int64_t transid = 0;
private:

};


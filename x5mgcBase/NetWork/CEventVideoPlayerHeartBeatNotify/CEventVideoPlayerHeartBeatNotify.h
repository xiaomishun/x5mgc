#pragma once
#include "../Utils.h"
class CEventVideoPlayerHeartBeatNotify :public ProtoBufSerializable
{
public:
	CEventVideoPlayerHeartBeatNotify();
	~CEventVideoPlayerHeartBeatNotify();
	virtual void * operator[](string name);
public:
	int64_t trans_id = 0;
};


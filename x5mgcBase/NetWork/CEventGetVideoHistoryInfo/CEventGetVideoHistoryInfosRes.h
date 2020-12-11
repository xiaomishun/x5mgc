#pragma once
#include "../Utils.h"
#include "RoomListInfo.h"
class CEventGetVideoHistoryInfosRes : public ProtoBufSerializable
{
public:
	CEventGetVideoHistoryInfosRes();
	~CEventGetVideoHistoryInfosRes();
	void Reset();
	virtual void * operator[](string name);
public:
	int time_stamp = 0;
	std::vector<RoomListInfo *> room_proxy_infos;  //所选历史列表
};


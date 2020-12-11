#pragma once
#include "../Utils.h"
#include "CEventGetVideoRoomTagInfosRes.h"
#include "CEventVideoRoomInfo.h"
class CEventGetVideoMainInfosRes : public ProtoBufSerializable
{
public:
	CEventGetVideoMainInfosRes();
	~CEventGetVideoMainInfosRes();
	virtual void * operator[](string name);
	void Reset();
public:
	int f7250a = 0;
	vector<CEventVideoRoomInfo *> RoomList;
	vector<CEventGetVideoRoomTagInfosRes *> RoomTagList;
};


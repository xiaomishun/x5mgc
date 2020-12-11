#pragma once
#include "../Utils.h"
#include "VideoHomePageRoomInfo.h"
class CEventGetVideoRoomTagInfosRes : public ProtoBufSerializable
{
public:
	CEventGetVideoRoomTagInfosRes();
	~CEventGetVideoRoomTagInfosRes();
	virtual void * operator[](string name);
public:
	int f7261a = 0;
	int f7262b = 0;
	int f7263c = 0;
	std::vector<VideoHomePageRoomInfo *> HomePageInfo;
	int f7265e = 0;
	int f7266f = 0;
	std::string f7267g;
	int f7268h = 0;
};


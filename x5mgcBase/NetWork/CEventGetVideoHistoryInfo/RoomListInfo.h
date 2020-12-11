#pragma once
#include "../Utils.h"
class RoomListInfo : public ProtoBufSerializable
{
public:
	RoomListInfo();
	~RoomListInfo();
	virtual void * operator[](string name);
public:

	int64_t time_stamp = 0;
	std::string roomName;
	int level = 0;
	bool follow = 0;
	bool exp = 0;
	int roomID = 0;// ·¿¼äºÅID
	int video_money = 0;
	int vip_level = 0;
	std::string has_token;
	int  wage = 0;
	int  attached_wage = 0;
	int  attached_wage2 = 0;
};


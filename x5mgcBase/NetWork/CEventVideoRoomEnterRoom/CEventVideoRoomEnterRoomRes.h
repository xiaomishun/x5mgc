#pragma once
#include "../Utils.h"
#include "EnterVideoRoomInitInfo.h"
class CEventVideoRoomEnterRoomRes : public ProtoBufSerializable
{
public:
	CEventVideoRoomEnterRoomRes();
	~CEventVideoRoomEnterRoomRes();
	void Reset();
	virtual void * operator[](string name);
public:
	int room_id = 0;
	int result = 0;
	EnterVideoRoomInitInfo info;
	int cooldown = 0;
	int nest_count = 0;
	bool is_special_room = false;
	bool is_nest_room = false;
	int subject = 0;
	int tag = 0;
	int offset = 0;
	bool m_switch = false;
	std::string title;
	std::string description;
	std::string close_description;
	int left_bekicked_time = 0;
	std::string h5_url_profix;
	std::string pic_location;
	int concert_id = 0;
	//19
	int f9608t = 0;
	int f9609u = 0;
	std::string f9610v;
	int f9611w = 0;
	int f9612x = 0;
	int f9613y = 0;
	int f9614z = 0;
	int f9587A = 0;
	int f9588B = 0;
	int f9589C = 0;
};


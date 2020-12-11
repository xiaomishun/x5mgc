#pragma once
#include "../Utils.h"
class VideoToClientChatMessage :public ProtoBufSerializable
{
public:
	VideoToClientChatMessage();
	~VideoToClientChatMessage();
	virtual void * operator[](string name);
public:
	int64_t sender_ID = 0;
	int64_t receiver_ID = 0;
	std::string sender_name;
	std::string recver_name;
	std::string sender_zoneName;
	std::string recver_zoneName;
	std::string message;
	int type = 0;
	int is_purple = 0;
	int in_vip_seat = 0;
	int sender_type = 0;
	int receiver_type = 0;
	int roomid = 0;
	int sender_jacket = 0;
	int guard_level = 0;
	int vip_level = 0;
	bool is_free_whistle = false;
	int judge_type = 0;
	int64_t videoguild_id = 0;
	int sender_device_type = 0;
	int guard_level_new = 0;
	bool invisible = false;
	bool forbid_talk_all_room = false;
	bool nest_assistant = false;
	int credits_level = 0;
	int wealth_level = 0;
};


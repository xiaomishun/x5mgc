#pragma once
#include "../Utils.h"

class VideoCharInfo :public ProtoBufSerializable
{
public:
	VideoCharInfo();
	~VideoCharInfo();
	virtual void * operator[](string name);
public:
	int64_t pstid = 0;
	std::string card_signature_str;
	int last_logout_time = 0;
	int last_login_time = 0;
	int data_version = 0;
	int have_portrait = 0;
	int64_t video_room_wealth = 0;
	std::string nick_str;
	int free_gift_count = 0;
	int free_gift_gained = 0;
	int daily_update_time = 0;
	int gender = 0;
	int money = 0;
	int player_flags = 0;
	int64_t vgid = 0;
	int last_dianzan_t = 0;
	int anchor_pk_activity_id = 0;
	int anchor_pk_contribution = 0;
private:

};


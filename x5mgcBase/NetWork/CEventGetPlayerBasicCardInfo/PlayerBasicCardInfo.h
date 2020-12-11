#pragma once
#include "../Utils.h"
class PlayerBasicCardInfo : public ProtoBufSerializable
{
public:
	PlayerBasicCardInfo();
	~PlayerBasicCardInfo();
	virtual void * operator[](string name);
public:
	int64_t player_id = 0;
	std::string portrait_url;
	std::string player_name;
	int player_sex = 0;
	int player_level = 0;
	int wealth_level = 0;
	int64_t vip_attached_anchor_id = 0;
	int vip_level = 0;
	std::string vip_attached_anchor_name;
	int64_t vip_remaining_time = 0;
	std::string signature;
	int64_t wealth = 0;
	int diamond = 0;
	int video_money = 0;
	int followed_anchor_live_count = 0;
	bool has_taken_wage_today = false;
	int64_t daily_wage = 0;
	int64_t  attached_wage = 0;
};


#pragma once
#include "../Utils.h"
#include "AnchorData2.h"
class CEventVideoSendGiftResult :public ProtoBufSerializable
{
public:
	CEventVideoSendGiftResult();
	~CEventVideoSendGiftResult();
	virtual void * operator[](string name);
public:
	int result = 0;
	int64_t sender_id = 0;
	int gift_id = 0;
	int gift_count = 0;
	int room_id = 0;
	int zone_id = 0;
	unsigned int sender_qq = 0;
	unsigned int anchor_qq = 0;
	std::string zone_name;
	std::string sender_name;
	std::string sender_ip;
	std::string anchor_name;
	NetBuffer avatar;
	int sender_sex = 0;
	int sender_level = 0;
	bool has_avatar = 0;
	AnchorData2 anchor_data;
	std::string gift_name;
	int64_t videoguild_id = 0;
	int cost_member_score = 0;
	int price = 0;
	int starlight = 0;
	int vip_level = 0;
	int64_t trans_id = 0;
	int diamond_balance = 0;
	int res_ext = 0;
	std::string reason_ext;
	int support_degree_add = 0;
	bool invisible = false;
	int video_money = 0;
	int guard_level = 0;
	int nest_credit_level = 0;
	int continuous_send_gift_times = 0;
	int anchor_exp = 0;
	int wealth_level = 0;
	NetBuffer m_gift_ext_info;
	int source = 0;
private:

};


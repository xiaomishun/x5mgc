#include "CEventVideoSendGiftResult.h"

CEventVideoSendGiftResult::CEventVideoSendGiftResult():ProtoBufSerializable(this)
{
	registerField("result", "", Descriptor::Int32, 1);
	registerField("sender_id", "", Descriptor::Int64, 2);
	registerField("gift_id", "", Descriptor::Int32, 3);
	registerField("gift_count", "", Descriptor::Int32, 4);
	registerField("room_id", "", Descriptor::Int32, 5);
	registerField("zone_id", "", Descriptor::Int32, 6);
	registerField("sender_qq", "", Descriptor::Int32, 7);
	registerField("anchor_qq", "", Descriptor::Int32, 8);
	registerField("zone_name", "", Descriptor::TypeString, 9);
	registerField("sender_name", "", Descriptor::TypeString, 10);
	registerField("sender_ip", "", Descriptor::TypeString, 11);
	registerField("anchor_name", "", Descriptor::TypeString, 12);
	registerField("avatar", "", Descriptor::TypeNetBuffer, 13);
	registerField("sender_sex", "", Descriptor::Int32, 14);
	registerField("sender_level", "", Descriptor::Int32, 15);	
	registerField("has_avatar", "", Descriptor::TypeBoolean, 16);
	registerField("anchor_data", typeid(AnchorData2).name(), Descriptor::Compound, 17);
	registerField("gift_name", "", Descriptor::TypeString, 18);
	registerField("videoguild_id", "", Descriptor::Int64, 19);
	registerField("cost_member_score", "", Descriptor::Int32, 20);
	registerField("price", "", Descriptor::Int32, 21);
	registerField("starlight", "", Descriptor::Int32, 22);
	registerField("vip_level", "", Descriptor::Int32, 23);
	registerField("trans_id", "", Descriptor::Int64, 24);
	registerField("diamond_balance", "", Descriptor::Int32, 25);
	registerField("res_ext", "", Descriptor::Int32, 26);
	registerField("reason_ext", "", Descriptor::TypeString, 27);
	registerField("support_degree_add", "", Descriptor::Int32, 28);
	registerField("invisible", "", Descriptor::TypeBoolean, 29);
	registerField("video_money", "", Descriptor::Int32, 30);
	registerField("guard_level", "", Descriptor::Int32, 31);
	registerField("nest_credit_level", "", Descriptor::Int32, 32);
	registerField("continuous_send_gift_times", "", Descriptor::Int32, 33);
	registerField("anchor_exp", "", Descriptor::Int32, 34);
	registerField("wealth_level", "", Descriptor::Int32, 35);
	registerField("m_gift_ext_info", "", Descriptor::TypeNetBuffer, 36);
	registerField("source", "", Descriptor::Int32, 37);
}

CEventVideoSendGiftResult::~CEventVideoSendGiftResult()
{

}

void * CEventVideoSendGiftResult::operator[](string name)
{

	if (name == "result"){
		return &this->result;
	}
	else if (name == "sender_id") {
		return &this->sender_id;
	}
	else if (name == "gift_id") {
		return &this->gift_id;
	}
	else if (name == "gift_count") {
		return &this->gift_count;
	}
	else if (name == "room_id") {
		return &this->room_id;
	}
	else if (name == "zone_id") {
		return &this->zone_id;
	}
	else if (name == "sender_qq") {
		return &this->sender_qq;
	}
	else if (name == "anchor_qq") {
		return &this->anchor_qq;
	}
	else if (name == "zone_name") {
		return &this->zone_name;
	}
	else if (name == "sender_name") {
		return &this->sender_name;
	}
	else if (name == "sender_ip") {
		return &this->sender_ip;
	}
	else if (name == "anchor_name") {
		return &this->anchor_name;
	}
	else if (name == "avatar") {
		return &this->avatar;
	}
	else if (name == "sender_sex") {
		return &this->sender_sex;
	}
	else if (name == "sender_level") {
		return &this->sender_level;
	}
	else if (name == "has_avatar") {
		return &this->has_avatar;
	}
	else if (name == "anchor_data") {
		return &this->anchor_data;
	}
	else if (name == "gift_name") {
		return &this->gift_name;
	}
	else if (name == "videoguild_id") {
		return &this->videoguild_id;
	}
	else if (name == "cost_member_score") {
		return &this->cost_member_score;
	}
	else if (name == "price") {
		return &this->price;
	}
	else if (name == "starlight") {
		return &this->starlight;
	}
	else if (name == "vip_level") {
		return &this->vip_level;
	}
	else if (name == "trans_id") {
		return &this->trans_id;
	}
	else if (name == "diamond_balance") {
		return &this->diamond_balance;
	}
	else if (name == "res_ext") {
		return &this->res_ext;
	}
	else if (name == "reason_ext") {
		return &this->reason_ext;
	}
	else if (name == "support_degree_add") {
		return &this->support_degree_add;
	}
	else if (name == "invisible") {
		return &this->invisible;
	}
	else if (name == "video_money") {
		return &this->video_money;
	}
	else if (name == "guard_level") {
		return &this->guard_level;
	}
	else if (name == "nest_credit_level") {
		return &this->nest_credit_level;
	}
	else if (name == "continuous_send_gift_times") {
		return &this->continuous_send_gift_times;
	}
	else if (name == "anchor_exp") {
		return &this->anchor_exp;
	}
	else if (name == "wealth_level") {
		return &this->wealth_level;
	}
	else if (name == "m_gift_ext_info") {
		return &this->m_gift_ext_info;
	}
	else if (name == "source") {
		return &this->source;
	}
	return nullptr;
}

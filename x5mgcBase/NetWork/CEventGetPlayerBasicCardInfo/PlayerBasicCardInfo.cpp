#include "PlayerBasicCardInfo.h"



PlayerBasicCardInfo::PlayerBasicCardInfo():ProtoBufSerializable(this)
{
	registerField("player_id", "", Descriptor::Int64, 1);
	registerField("portrait_url", "", Descriptor::TypeString, 2);
	registerField("player_name", "", Descriptor::TypeString, 3);
	registerField("player_sex", "", Descriptor::Int32, 4);
	registerField("player_level", "", Descriptor::Int32, 5);
	registerField("wealth_level", "", Descriptor::Int32, 6);
	registerField("vip_attached_anchor_id", "", Descriptor::Int64, 7);
	registerField("vip_level", "", Descriptor::Int32, 8);
	registerField("vip_attached_anchor_name", "", Descriptor::TypeString, 9);
	registerField("vip_remaining_time", "", Descriptor::Int64, 10);
	registerField("signature", "", Descriptor::TypeString, 11);
	registerField("wealth", "", Descriptor::Int64, 12);
	registerField("diamond", "", Descriptor::Int32, 13);
	registerField("video_money", "", Descriptor::Int32, 14);
	registerField("followed_anchor_live_count", "", Descriptor::Int32, 15);
	registerField("has_taken_wage_today", "", Descriptor::TypeBoolean, 16);
	registerField("daily_wage", "", Descriptor::Int64, 17);
	registerField("attached_wage", "", Descriptor::Int64, 18);
}


PlayerBasicCardInfo::~PlayerBasicCardInfo()
{

}

void * PlayerBasicCardInfo::operator[](string name)
{
	if (name == "player_id") {
		return &this->player_id;
	}
	else if (name == "portrait_url") {
		return &this->portrait_url;
	}
	else if (name == "player_name") {
		return &this->player_name;
	}
	else if (name == "player_sex") {
		return &this->player_sex;
	}
	else if (name == "player_level") {
		return &this->player_level;
	}
	else if (name == "wealth_level") {
		return &this->wealth_level;
	}
	else if (name == "vip_attached_anchor_id") {
		return &this->vip_attached_anchor_id;
	}
	else if (name == "vip_level") {
		return &this->vip_level;
	}
	else if (name == "vip_attached_anchor_name") {
		return &this->vip_attached_anchor_name;
	}
	else if (name == "vip_remaining_time") {
		return &this->vip_remaining_time;
	}
	else if (name == "signature") {
		return &this->signature;
	}
	else if (name == "wealth") {
		return &this->wealth;
	}
	else if (name == "diamond") {
		return &this->diamond;
	}
	else if (name == "video_money") {
		return &this->video_money;
	}
	else if (name == "followed_anchor_live_count") {
		return &this->followed_anchor_live_count;
	}
	else if (name == "has_taken_wage_today") {
		return &this->has_taken_wage_today;
	}
	else if (name == "daily_wage") {
		return &this->daily_wage;
	}
	else if (name == "attached_wage") {
		return &this->attached_wage;
	}
	return nullptr;
}

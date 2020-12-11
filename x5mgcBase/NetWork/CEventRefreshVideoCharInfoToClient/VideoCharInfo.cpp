#include "VideoCharInfo.h"

VideoCharInfo::VideoCharInfo():ProtoBufSerializable(this)
{
	registerField("pstid", "", Descriptor::Int64, 1);
	registerField("card_signature_str", "", Descriptor::TypeString, 2);
	registerField("last_logout_time", "", Descriptor::Int32, 3);
	registerField("last_login_time", "", Descriptor::Int32, 4);
	registerField("data_version", "", Descriptor::Int32, 5);
	registerField("have_portrait", "", Descriptor::Int32, 6);
	registerField("video_room_wealth", "", Descriptor::Int64, 7);
	registerField("nick_str", "", Descriptor::TypeString, 8);
	registerField("free_gift_count", "", Descriptor::Int32, 9);
	registerField("free_gift_gained", "", Descriptor::Int32, 10);
	registerField("daily_update_time", "", Descriptor::Int32, 11);
	registerField("gender", "", Descriptor::Int32, 12);
	registerField("money", "", Descriptor::Int32, 13);
	registerField("player_flags", "", Descriptor::Int32, 14);
	registerField("vgid", "", Descriptor::Int64, 15);
	registerField("last_dianzan_t", "", Descriptor::Int32, 16);
	registerField("anchor_pk_activity_id", "", Descriptor::Int32, 17);
	registerField("anchor_pk_contribution", "", Descriptor::Int64, 18);
}

VideoCharInfo::~VideoCharInfo()
{

}

void * VideoCharInfo::operator[](string name)
{
	if (name == "pstid") {
		return &pstid;
	}
	else if (name == "card_signature_str") {
		return &card_signature_str;
	}
	else if (name == "last_logout_time") {
		return &last_logout_time;
	}
	else if (name == "last_login_time") {
		return &last_login_time;
	}
	else if (name == "data_version") {
		return &data_version;
	}
	else if (name == "have_portrait") {
		return &have_portrait;
	}
	else if (name == "video_room_wealth") {
		return &video_room_wealth;
	}
	else if (name == "nick_str") {
		return &nick_str;
	}
	else if (name == "free_gift_count") {
		return &free_gift_count;
	}
	else if (name == "free_gift_gained") {
		return &free_gift_gained;
	}
	else if (name == "daily_update_time") {
		return &daily_update_time;
	}
	else if (name == "gender") {
		return &gender;
	}
	else if (name == "money") {
		return &money;
	}
	else if (name == "player_flags") {
		return &player_flags;
	}
	else if (name == "vgid") {
		return &vgid;
	}
	else if (name == "last_dianzan_t") {
		return &last_dianzan_t;
	}
	else if (name == "anchor_pk_activity_id") {
		return &anchor_pk_activity_id;
	}
	else if (name == "anchor_pk_contribution") {
		return &anchor_pk_contribution;
	}
	return nullptr;
}

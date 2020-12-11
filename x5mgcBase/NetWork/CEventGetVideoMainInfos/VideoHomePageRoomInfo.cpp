#include "VideoHomePageRoomInfo.h"

VideoHomePageRoomInfo::VideoHomePageRoomInfo():ProtoBufSerializable(this)
{
	registerField("id", "", Descriptor::Int32, 1);
	registerField("type", "", Descriptor::Int32, 2);
	registerField("subject", "", Descriptor::Int32, 3);
	registerField("room_name", "", Descriptor::TypeString, 4);
	registerField("player_num", "", Descriptor::Int32, 5);
	registerField("state", "", Descriptor::Int32, 6);
	registerField("live_start_time", "", Descriptor::Int32, 7);
	registerField("anchor_pstid", "", Descriptor::Int64, 8);
	registerField("anchor_name", "", Descriptor::TypeString, 9);
	registerField("room_attribute_flag", "", Descriptor::Int32, 10);
	registerField("player_capcity", "", Descriptor::Int32, 11);
	registerField("room_pic_info", "", Descriptor::Int32, 12);
	registerField("is_closed", "", Descriptor::TypeBoolean, 13);
	registerField("is_nest", "", Descriptor::TypeBoolean, 14);
	registerField("attached_room_id", "", Descriptor::Int32, 15);
	registerField("large_anchor_posing_url", "", Descriptor::TypeString, 16);//摆拍大图
	registerField("small_anchor_posing_url", "", Descriptor::TypeString, 17);//摆拍小图
	registerField("is_anchor_pk_room", "", Descriptor::TypeBoolean, 18);
	registerField("is_special_room", "", Descriptor::TypeBoolean, 19);
	registerField("nest_owner", "", Descriptor::Int64, 20);
	registerField("nest_status", "", Descriptor::Int32, 21);
	registerField("anchor_level", "", Descriptor::Int32, 22);
	registerField("is_star_gift_champion", "", Descriptor::TypeBoolean, 23);
	registerField("anchor_badge", "", Descriptor::Int32, 24);	// 主播徽章
	registerField("qgame_anchor_posing_url", "", Descriptor::TypeString, 25);//QGame摆拍图片地址
	registerField("room_skin_level", "", Descriptor::Int32, 26);
	registerField("room_skin_id", "", Descriptor::Int32, 27);
	registerField("is_test_room", "", Descriptor::TypeBoolean, 28);
	registerField("tag_name", "", Descriptor::TypeString, 29);//房间开播标签名称：空为普通房间，非空为标签房间public var definition:int;
	registerField("week_star_grade", "", Descriptor::Int32, 30);//段位
	registerField("week_star_sub_level", "", Descriptor::Int32, 31);//段位等级
	registerField("is_use_mobile_anchor_posing", "", Descriptor::TypeBoolean, 32);//是否使用移动摆拍
	registerField("vertical_live", "", Descriptor::TypeBoolean, 33);//直播中截图屏幕朝向    1：横屏     2:竖屏
	registerField("is_in_nest_blacklist", "", Descriptor::TypeBoolean, 34);
	registerField("anchor_device_type", "", Descriptor::TypeBoolean, 35);
	registerField("f4206J", "", Descriptor::Int32, 36);
	registerField("f4207K", "", Descriptor::Int32, 37);
	registerFieldForDict("f4208L", "", Descriptor::TypeString, "", Descriptor::Int32, 38);
	registerField("f4209M", "", Descriptor::Int32, 39);
	registerField("f4210N", "", Descriptor::Int32, 40);
}

VideoHomePageRoomInfo::~VideoHomePageRoomInfo()
{
	std::map<std::string *, int *>::iterator  it;
	for (it = f4208L.begin(); it != f4208L.end(); it++)
	{
		delete it->first;
		delete it->second;
	}
	f4208L.clear();
}

void * VideoHomePageRoomInfo::operator[](string name)
{
	if (name == "id")
	{
		return &this->id;
	}
	else if (name == "type")
	{
		return &this->type;
	}
	else if (name == "subject")
	{
		return &this->subject;
	}
	else if (name == "room_name")
	{
		return &this->room_name;
	}
	else if (name == "player_num")
	{
		return &this->player_num;
	}
	else if (name == "state")
	{
		return &this->state;
	}
	else if (name == "live_start_time")
	{
		return &this->live_start_time;
	}
	else if (name == "anchor_pstid")
	{
		return &this->anchor_pstid;
	}
	else if (name == "anchor_name")
	{
		return &this->anchor_name;
	}
	else if (name == "room_attribute_flag")
	{
		return &this->room_attribute_flag;
	}
	else if (name == "player_capcity")
	{
		return &this->player_capcity;
	}
	else if (name == "room_pic_info")
	{
		return &this->room_pic_info;
	}
	else if (name == "is_closed")
	{
		return &this->is_closed;
	}
	else if (name == "is_nest")
	{
		return &this->is_nest;
	}
	else if (name == "attached_room_id")
	{
		return &this->attached_room_id;
	}
	else if (name == "large_anchor_posing_url")
	{
		return &this->large_anchor_posing_url;
	}
	else if (name == "small_anchor_posing_url")
	{
		return &this->small_anchor_posing_url;
	}
	else if (name == "is_anchor_pk_room")
	{
		return &this->is_anchor_pk_room;
	}
	else if (name == "is_special_room")
	{
		return &this->is_special_room;
	}
	else if (name == "nest_owner")
	{
		return &this->nest_owner;
	}
	else if (name == "nest_status")
	{
		return &this->nest_status;
	}
	else if (name == "anchor_level")
	{
		return &this->anchor_level;
	}
	else if (name == "is_star_gift_champion")
	{
		return &this->is_star_gift_champion;
	}
	else if (name == "anchor_badge")
	{
		return &this->anchor_badge;
	}
	else if (name == "qgame_anchor_posing_url")
	{
		return &this->qgame_anchor_posing_url;
	}
	else if (name == "room_skin_level")
	{
		return &this->room_skin_level;
	}
	else if (name == "room_skin_id")
	{
		return &this->room_skin_id;
	}
	else if (name == "is_test_room")
	{
		return &this->is_test_room;
	}
	else if (name == "tag_name")
	{
		return &this->tag_name;
	}
	else if (name == "week_star_grade")
	{
		return &this->week_star_grade;
	}
	else if (name == "week_star_sub_level")
	{
		return &this->week_star_sub_level;
	}
	else if (name == "is_use_mobile_anchor_posing")
	{
		return &this->is_use_mobile_anchor_posing;
	}
	else if (name == "vertical_live")
	{
		return &this->vertical_live;
	}
	else if (name == "is_in_nest_blacklist")
	{
		return &this->is_in_nest_blacklist;
	}
	else if (name == "anchor_device_type")
	{
		return &this->anchor_device_type;
	}
	else if (name == "f4206J")
	{
		return &this->f4206J;
	}
	else if (name == "f4207K")
	{
		return &this->f4207K;
	}
	else if (name == "f4208L")
	{
		return &this->f4208L;
	}
	else if (name == "f4209M")
	{
		return &this->f4209M;
	}
	else if (name == "f4210N")
	{
		return &this->f4210N;
	}
	return nullptr;
}

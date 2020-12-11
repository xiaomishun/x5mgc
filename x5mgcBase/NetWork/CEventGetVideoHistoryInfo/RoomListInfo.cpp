#include "RoomListInfo.h"



RoomListInfo::RoomListInfo():ProtoBufSerializable(this)
{
	registerField("time_stamp", "", Descriptor::Int64, 1);//time_stamp
	registerField("roomName", "", Descriptor::TypeString, 2);
	registerField("level", "", Descriptor::Int32, 3);
	registerField("follow", "", Descriptor::TypeBoolean, 4); //¹Ø×¢
	registerField("exp", "", Descriptor::TypeBoolean, 5);
	registerField("roomID", "", Descriptor::Int32, 6);
	registerField("video_money", "", Descriptor::Int32, 7);
	registerField("vip_level", "", Descriptor::Int32, 8);
	registerField("has_token", "", Descriptor::TypeString, 9);
	registerField("wage", "", Descriptor::Int32, 10);
	registerField("attached_wage", "", Descriptor::Int32, 11);
	registerField("attached_wage2", "", Descriptor::Int32, 12);
}


RoomListInfo::~RoomListInfo()
{
}

void * RoomListInfo::operator[](string name)
{
	if (name == "time_stamp") {
		return &this->time_stamp;
	}
	else if (name == "roomName") {
		return &this->roomName;
	}
	else if (name == "level") {
		return &this->level;
	}
	else if (name == "follow") {
		return &this->follow;
	}
	else if (name == "exp") {
		return &this->exp;
	}
	else if (name == "roomID") {
		return &this->roomID;
	}
	else if (name == "video_money") {
		return &this->video_money;
	}
	else if (name == "vip_level") {
		return &this->vip_level;
	}
	else if (name == "has_token") {
		return &this->has_token;
	}
	else if (name == "wage") {
		return &this->wage;
	}
	else if (name == "attached_wage") {
		return &this->attached_wage;
	}
	else if (name == "attached_wage2") {
		return &this->attached_wage2;
	}
	return nullptr;
}

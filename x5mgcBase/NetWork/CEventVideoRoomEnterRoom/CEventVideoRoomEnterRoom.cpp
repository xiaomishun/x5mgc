#include "CEventVideoRoomEnterRoom.h"



CEventVideoRoomEnterRoom::CEventVideoRoomEnterRoom():ProtoBufSerializable(this)
{
	registerField("room_id", "", Descriptor::Int32, 1);
	registerField("nick", "", Descriptor::TypeString, 2);
	registerField("gender", "", Descriptor::Int32, 3);
	registerField("level", "", Descriptor::Int32, 4);
	registerField("has_avatar", "", Descriptor::TypeBoolean, 5);
	registerField("avatar", "", Descriptor::TypeNetBuffer, 6);
	registerField("source", "", Descriptor::Int32, 7);
	registerField("invisible", "", Descriptor::TypeBoolean, 8);
	registerField("crowd_into", "", Descriptor::TypeBoolean, 9);

	
	registerField("tag", "", Descriptor::Int32, 9);

	registerField("subject", "", Descriptor::Int32, 11);
	
	registerField("offset", "", Descriptor::Int32, 12);
	registerField("module_type", "", Descriptor::Int32, 13);
	registerField("page_capacity", "", Descriptor::Int32, 14);
	registerField("room_list_pos", "", Descriptor::Int32, 15);
	registerField("room_temp", "", Descriptor::Int32, 16);
	registerFieldForList("room_index", typeid(int).name(), Descriptor::Int32, 17);
	registerField("token", "", Descriptor::TypeString, 18);
}


CEventVideoRoomEnterRoom::~CEventVideoRoomEnterRoom()
{

}

void * CEventVideoRoomEnterRoom::operator[](string name)
{
	if (name == "room_id") {
		return &this->room_id;
	}
	else if (name == "nick") {
		return &this->nick;
	}
	else if (name == "gender") {
		return &this->gender;
	}
	else if (name == "level") {
		return &this->level;
	}
	else if (name == "has_avatar") {
		return &this->has_avatar;
	}
	else if (name == "avatar") {
		return &this->avatar;
	}
	else if (name == "source") {
		return &this->source;
	}
	else if (name == "invisible") {
		return &this->invisible;
	}
	else if (name == "crowd_into") {
		return &this->crowd_into;
	}
	else if (name == "subject") {
		return &this->subject;
	}
	else if (name == "tag") {
		return &this->tag;
	}
	else if (name == "offset") {
		return &this->offset;
	}
	else if (name == "module_type") {
		return &this->module_type;
	}
	else if (name == "page_capacity") {
		return &this->page_capacity;
	}
	else if (name == "room_list_pos") {
		return &this->room_list_pos;
	}
	else if (name == "room_temp") {
		return &this->room_temp;
	}
	else if (name == "room_index") {
		return &this->room_index;
	}
	else if (name == "token") {
		return &this->token;
	}
	return nullptr;
}

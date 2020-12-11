#include "VideoToClientChatMessage.h"



VideoToClientChatMessage::VideoToClientChatMessage() :ProtoBufSerializable(this)
{
	registerField("sender_ID", "",Descriptor::Int64, 1);
	registerField("receiver_ID", "",Descriptor::Int64, 2);
	registerField("sender_name", "",Descriptor::TypeString, 3);
	registerField("recver_name", "",Descriptor::TypeString, 4);
	registerField("sender_zoneName", "",Descriptor::TypeString, 5);
	registerField("recver_zoneName", "",Descriptor::TypeString, 6);
	registerField("message", "",Descriptor::TypeString, 7);
	registerField("type", "",Descriptor::Int32, 8);
	registerField("is_purple", "",Descriptor::Int32, 9);
	registerField("in_vip_seat", "",Descriptor::Int32, 10);
	registerField("sender_type", "",Descriptor::Int32, 11);
	registerField("receiver_type", "",Descriptor::Int32, 12);
	registerField("roomid", "",Descriptor::Int32, 13);
	registerField("sender_jacket", "",Descriptor::Int32, 14);
	registerField("guard_level", "",Descriptor::Int32, 15);
	registerField("vip_level", "",Descriptor::Int32, 16);
	registerField("is_free_whistle", "",Descriptor::TypeBoolean, 17);
	registerField("judge_type", "",Descriptor::Int32, 18);
	registerField("videoguild_id", "",Descriptor::Int64, 19);
	registerField("sender_device_type", "",Descriptor::Int32, 20);
	registerField("guard_level_new", "",Descriptor::Int32, 21);
	registerField("invisible", "",Descriptor::TypeBoolean, 22);
	registerField("forbid_talk_all_room", "",Descriptor::TypeBoolean, 23);
	registerField("nest_assistant", "",Descriptor::TypeBoolean, 24);
	registerField("credits_level", "",Descriptor::Int32, 25);
	registerField("wealth_level", "",Descriptor::Int32, 26);
}

VideoToClientChatMessage::~VideoToClientChatMessage()
{

}

void * VideoToClientChatMessage::operator[](string name)
{
	if (name == "sender_ID") {
		return &this->sender_ID;
	}
	else if (name == "receiver_ID") {
		return &this->receiver_ID;
	}
	else if (name == "sender_name") {
		return &this->sender_name;
	}
	else if (name == "recver_name") {
		return &this->recver_name;
	}
	else if (name == "sender_zoneName") {
		return &this->sender_zoneName;
	}
	else if (name == "recver_zoneName") {
		return &this->recver_zoneName;
	}
	else if (name == "message") {
		return &this->message;
	}
	else if (name == "type") {
		return &this->type;
	}
	else if (name == "is_purple") {
		return &this->is_purple;
	}
	else if (name == "in_vip_seat") {
		return &this->in_vip_seat;
	}
	else if (name == "sender_type") {
		return &this->sender_type;
	}
	else if (name == "receiver_type") {
		return &this->receiver_type;
	}
	else if (name == "roomid") {
		return &this->roomid;
	}
	else if (name == "sender_jacket") {
		return &this->sender_jacket;
	}
	else if (name == "guard_level") {
		return &this->guard_level;
	}
	else if (name == "vip_level") {
		return &this->vip_level;
	}
	else if (name == "is_free_whistle") {
		return &this->is_free_whistle;
	}
	else if (name == "judge_type") {
		return &this->judge_type;
	}
	else if (name == "videoguild_id") {
		return &this->videoguild_id;
	}
	else if (name == "sender_device_type") {
		return &this->sender_device_type;
	}
	else if (name == "guard_level_new") {
		return &this->guard_level_new;
	}
	else if (name == "invisible") {
		return &this->invisible;
	}
	else if (name == "forbid_talk_all_room") {
		return &this->forbid_talk_all_room;
	}
	else if (name == "nest_assistant") {
		return &this->nest_assistant;
	}	
	else if (name == "credits_level") {
		return &this->credits_level;
	}
	else if (name == "wealth_level") {
		return &this->wealth_level;
	}
	return nullptr;
}

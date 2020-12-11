#include "CEventVideoToClientChatMessage.h"



CEventVideoToClientChatMessage::CEventVideoToClientChatMessage() :ProtoBufSerializable(this)
{
	registerField("message", typeid(VideoToClientChatMessage).name(), Descriptor::Compound, 1);
	registerField("anchor_id", "", Descriptor::Int32, 2);
	registerField("starlight", "", Descriptor::Int32, 3);
	registerField("popularity", "", Descriptor::Int32, 4);
	registerField("add_anchor_exp", "", Descriptor::Int32, 5);
}

CEventVideoToClientChatMessage::~CEventVideoToClientChatMessage()
{

}

void * CEventVideoToClientChatMessage::operator[](string name)
{
	if (name == "message") {
		return &this->message;
	}
	else if (name == "anchor_id") {
		return &this->anchor_id;
	}
	else if (name == "starlight") {
		return &this->starlight;
	}
	else if (name == "popularity") {
		return &this->popularity;
	}
	else if (name == "add_anchor_exp") {
		return &this->add_anchor_exp;
	}
	return nullptr;
}

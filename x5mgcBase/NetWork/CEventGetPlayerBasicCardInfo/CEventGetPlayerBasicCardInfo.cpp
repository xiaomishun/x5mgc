#include "CEventGetPlayerBasicCardInfo.h"



CEventGetPlayerBasicCardInfo::CEventGetPlayerBasicCardInfo():ProtoBufSerializable(this)
{
	registerField("player_id", "", Descriptor::Int64, 1);
	registerField("code", "", Descriptor::Int32, 2);
}


CEventGetPlayerBasicCardInfo::~CEventGetPlayerBasicCardInfo()
{

}

void * CEventGetPlayerBasicCardInfo::operator[](string name)
{
	if (name == "player_id") {
		return &this->player_id;
	}
	else if (name == "code") {
		return &this->code;
	}
	return nullptr;
}

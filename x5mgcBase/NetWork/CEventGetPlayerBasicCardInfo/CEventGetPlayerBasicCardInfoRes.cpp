#include "CEventGetPlayerBasicCardInfoRes.h"



CEventGetPlayerBasicCardInfoRes::CEventGetPlayerBasicCardInfoRes():ProtoBufSerializable(this)
{
	registerField("ret", "", Descriptor::Int32, 1);
	registerField("player_basic_card_info", typeid(PlayerBasicCardInfo).name(), Descriptor::Compound, 2);
	registerField("f8280c", "", Descriptor::Int32, 3);
}


CEventGetPlayerBasicCardInfoRes::~CEventGetPlayerBasicCardInfoRes()
{

}

void * CEventGetPlayerBasicCardInfoRes::operator[](string name)
{
	if (name == "ret") {
		return &this->ret;
	}
	else if (name == "player_basic_card_info") {
		return &this->player_basic_card_info;
	}
	else if (name == "f8280c") {
		return &this->f8280c;
	}
	return nullptr;
}

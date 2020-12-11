#include "CEventIgnoreFreeGift.h"



CEventIgnoreFreeGift::CEventIgnoreFreeGift() :ProtoBufSerializable(this)
{
	registerField("is_ignore", "", Descriptor::TypeBoolean, 1);
}

CEventIgnoreFreeGift::~CEventIgnoreFreeGift()
{

}

void * CEventIgnoreFreeGift::operator[](string name)
{
	if (name == "is_ignore") {
		return &this->is_ignore;
	}
	return nullptr;
}

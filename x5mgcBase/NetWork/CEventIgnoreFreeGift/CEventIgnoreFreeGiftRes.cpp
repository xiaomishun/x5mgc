#include "CEventIgnoreFreeGiftRes.h"



CEventIgnoreFreeGiftRes::CEventIgnoreFreeGiftRes() :ProtoBufSerializable(this)
{
	registerField("res", "", Descriptor::Int32, 1);
	registerField("is_ignore", "", Descriptor::TypeBoolean, 2);
}

CEventIgnoreFreeGiftRes::~CEventIgnoreFreeGiftRes()
{

}

void * CEventIgnoreFreeGiftRes::operator[](string name)
{
	if (name == "res") {
		return &this->res;
	}
	else if (name == "is_ignore") {
		return &this->is_ignore;
	}
	return nullptr;
}

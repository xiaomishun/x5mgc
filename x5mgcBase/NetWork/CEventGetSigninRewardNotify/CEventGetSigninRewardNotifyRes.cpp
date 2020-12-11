#include "CEventGetSigninRewardNotifyRes.h"



CEventGetSigninRewardNotifyRes::CEventGetSigninRewardNotifyRes():ProtoBufSerializable(this)
{
	registerField("status", "", Descriptor::TypeBoolean, 1);
	registerField("is_Daily", "", Descriptor::TypeBoolean, 2);
	registerField("is_Acc", "", Descriptor::TypeBoolean, 3);
	registerField("f11246d", "", Descriptor::TypeBoolean, 4);
}


CEventGetSigninRewardNotifyRes::~CEventGetSigninRewardNotifyRes()
{

}

void * CEventGetSigninRewardNotifyRes::operator[](string name)
{
	if (name == "status") {
		return &this->status;
	}
	else if (name == "is_Daily") {
		return &this->is_Daily;
	}
	else if (name == "is_Acc") {
		return &this->is_Acc;
	}
	else if (name == "f11246d") {
		return &this->f11246d;
	}
	return nullptr;
}

#include "UserIdentity.h"



UserIdentity::UserIdentity() :ProtoBufSerializable(this)
{
	registerField("account", "", Descriptor::Int64, 1);
	registerField("channel", "", Descriptor::Int32, 2);
	registerField("zoneid", "", Descriptor::Int32, 3);
}

UserIdentity::~UserIdentity()
{

}

void * UserIdentity::operator[](string name)
{
	if (name == "account") {
		return &this->account;
	}
	else if (name == "channel") {
		return &this->channel;
	}
	else if (name == "zoneid") {
		return &this->zoneid;
	}
	return nullptr;
}

#include "RoomProxyInfo.h"



RoomProxyInfo::RoomProxyInfo():ProtoBufSerializable(this)
{
	registerField("name", "", Descriptor::TypeString, 1);
	registerField("provider", "", Descriptor::TypeString, 2);
	registerField("group", "", Descriptor::TypeString, 3);
	registerField("recommend", "", Descriptor::TypeBoolean, 4);
	registerField("zoneid", "", Descriptor::Int32, 5);
	registerFieldForList("addresses", typeid(RoomProxyAddress).name(), Descriptor::Compound, 6);
	registerField("channel", "", Descriptor::Int32, 7);
}


RoomProxyInfo::~RoomProxyInfo()
{
	for (size_t i = 0; i < addresses.size(); i++)
	{
		delete addresses[i];
	}
	addresses.clear();
}

void * RoomProxyInfo::operator[](string name)
{
	if (name == "name") {
		return &this->name;
	}
	else if (name == "provider") {
		return &this->provider;
	}
	else if (name == "group") {
		return &this->group;
	}
	else if (name == "recommend") {
		return &this->recommend;
	}
	else if (name == "zoneid") {
		return &this->zoneid;
	}
	else if (name == "addresses") {
		return &this->addresses;
	}
	else if (name == "channel") {
		return &this->channel;
	}
	return nullptr;
}

#include "RoomProxyAddress.h"



RoomProxyAddress::RoomProxyAddress():ProtoBufSerializable(this)
{
	registerField("ip", "", Descriptor::TypeString, 1);
	registerField("port", "", Descriptor::Int32, 2);
}


RoomProxyAddress::~RoomProxyAddress()
{
}

void * RoomProxyAddress::operator[](string name)
{
	if (name == "ip") {
		return &this->ip;
	}
	else if (name == "port") {
		return &this->port;
	}
	return nullptr;
}

#include "CEventVideoInitConnectionRequest.h"



CEventVideoInitConnectionRequest::CEventVideoInitConnectionRequest() :ProtoBufSerializable(this)
{
	registerField("uid", typeid(UserIdentity).name(), Descriptor::Compound, 1);
	//registerField("account", "", Descriptor::Int32, 2);
	//registerField("channel", "", Descriptor::Int32, 3);
	//registerField("zoneid", "", Descriptor::Int32, 4);
	registerField("roomID", "", Descriptor::Int32, 2);
	registerField("trans_id", "", Descriptor::Int64, 3);
	registerField("client_device_type", "", Descriptor::Int32, 4);
	registerField("appid", "", Descriptor::Int32, 5);
	registerField("skey", "", Descriptor::TypeString, 6);
	registerField("mobile_version", "", Descriptor::TypeString, 7);
	registerField("m_open_id", "", Descriptor::TypeString, 8);
	registerField("logic_version", "", Descriptor::Int32, 9);
	registerField("android_md5", "", Descriptor::TypeString, 10);
}


CEventVideoInitConnectionRequest::~CEventVideoInitConnectionRequest()
{
}

void * CEventVideoInitConnectionRequest::operator[](string name)
{
	if (name == "uid") {
		return &uid;
	}
	else if (name == "account") {
		return &account;
	}
	else if (name == "channel") {
		return &channel;
	}
	else if (name == "zoneid") {
		return &zoneid;
	}
	else if (name == "roomID") {
		return &roomID;
	}
	else if (name == "trans_id") {
		return &trans_id;
	}
	else if (name == "client_device_type") {
		return &client_device_type;
	}
	else if (name == "appid") {
		return &appid;
	}
	else if (name == "skey") {
		return &skey;
	}
	else if (name == "mobile_version") {
		return &mobile_version;
	}
	else if (name == "m_open_id") {
		return &m_open_id;
	}
	else if (name == "logic_version") {
		return &logic_version;
	}
	else if (name == "android_md5") {
		return &android_md5;
	}
	return nullptr;
}

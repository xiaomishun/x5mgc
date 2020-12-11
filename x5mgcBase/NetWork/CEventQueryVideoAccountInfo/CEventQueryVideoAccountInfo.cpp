#include "CEventQueryVideoAccountInfo.h"



CEventQueryVideoAccountInfo::CEventQueryVideoAccountInfo():ProtoBufSerializable(this)
{
	registerField("time_stamp", "", Descriptor::UInt32, 1);
	registerField("device_type", "", Descriptor::Int32, 2);
	registerField("m_appid", "", Descriptor::UInt32, 3);
	registerField("m_skey", "", Descriptor::TypeString, 4);
	registerField("m_open_id", "", Descriptor::TypeString, 5);
}


CEventQueryVideoAccountInfo::~CEventQueryVideoAccountInfo()
{

}

void * CEventQueryVideoAccountInfo::operator[](string name)
{
	if (name == "time_stamp") {
		return &time_stamp;
	}
	else if (name == "device_type") {
		return &device_type;
	}
	else if (name == "m_appid") {
		return &m_appid;
	}
	else if (name == "m_skey") {
		return &m_skey;
	}
	else if (name == "m_open_id") {
		return &m_open_id;
	}
	return nullptr;
}

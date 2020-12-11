#include "CEventRoomProxyWrapEvent.h"



CEventRoomProxyWrapEvent::CEventRoomProxyWrapEvent() :ProtoBufSerializable(this)
{
	registerField("tunnel_id", "", Descriptor::UInt32, 1);
	registerField("uid", typeid(UserIdentity).name(), Descriptor::Compound, 2);
	registerField("serialID", "", Descriptor::Int32, 3);
	registerField("ip", "", Descriptor::Int32, 4);
	registerField("diamond_info", "", Descriptor::Int32, 5);
	//registerField("skey", "", Descriptor::TypeString, 5);
	registerField("payload", "", Descriptor::TypeNetBuffer, 6);
	registerField("client_device_type", "", Descriptor::Int32, 7);
	registerField("clsid", "", Descriptor::Int32, 8);
	registerField("client_version", "", Descriptor::Int32, 9);
	//payload.resize(20);
	//int payloadArr[5] = { 41501,0xACABDEAF,0x0,0x4,12345678 };
	//memcpy(payload.data(), payloadArr, 20);


}

//public function CEventRoomProxyWrapEvent()
//{
//	registerField("tunnel_id", "", Descriptor.UInt32, 1);
//	registerField("uid", getQualifiedClassName(UserIdentity), Descriptor.Compound, 2);
//	registerField("serialID", "", Descriptor.Int32, 3);
//	registerField("ip", "", Descriptor.Int32, 4);
//	registerField("diamond_info", "", Descriptor.UInt32, 5);
//	registerField("payload", "", Descriptor.TypeNetBuffer, 6);
//	registerField("client_device_type", "", Descriptor.Int32, 7);
//	registerField("clsid", "", Descriptor.Int32, 8);
//	registerField("client_version", "", Descriptor.Int32, 9);
//}



CEventRoomProxyWrapEvent::~CEventRoomProxyWrapEvent()
{

}

void * CEventRoomProxyWrapEvent::operator[](string name)
{
	if (name == "tunnel_id")
	{
		return &tunnel_id;
	}
	else if (name == "uid")
	{
		return &uid;
	}
	else if (name == "serialID")
	{
		return &serialID;
	}
	else if (name == "ip")
	{
		return &ip;
	}
	else if (name == "diamond_info")
	{
		return &diamond_info;
	}
	else if (name == "payload") {
		return &payload;
	}
	else if (name == "client_device_type")
	{
		return &client_device_type;
	}
	else if (name == "clsid")
	{
		return &clsid;
	}
	else if (name == "client_version")
	{
		return &client_version;
	}
	return 0;
}

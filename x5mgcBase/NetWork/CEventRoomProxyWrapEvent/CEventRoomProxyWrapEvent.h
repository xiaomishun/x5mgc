#pragma once
#include "../Utils.h"
#include "../CEventQueryVideoAccountInfo/UserIdentity.h"
class CEventRoomProxyWrapEvent : public ProtoBufSerializable
{
public:
	CEventRoomProxyWrapEvent();
	~CEventRoomProxyWrapEvent();
	virtual void * operator[](string name);
public:
	uint32_t tunnel_id = 0;
	UserIdentity uid;
	uint32_t serialID = 0;
	int ip = 0;
	int diamond_info = 0;
	//vector<char> payload;
	NetBuffer payload;
	int client_device_type = 0;
	int clsid = 0;
	int client_version = 0;
};


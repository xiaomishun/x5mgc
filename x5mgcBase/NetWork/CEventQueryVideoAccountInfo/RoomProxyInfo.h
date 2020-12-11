#pragma once
#include "../Utils.h"
#include "RoomProxyAddress.h"
class RoomProxyInfo : public ProtoBufSerializable
{
public:
	RoomProxyInfo();
	~RoomProxyInfo();
	

	virtual void * operator[](string name);

	string name = "";
	string provider = "";
	string group = "";
	bool recommend = false;
	int zoneid = 0;
	std::vector<RoomProxyAddress *> addresses;
	int channel = 0;

};


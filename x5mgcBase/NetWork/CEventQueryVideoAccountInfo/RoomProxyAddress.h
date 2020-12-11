#pragma once
#include "../Utils.h"
class RoomProxyAddress : public ProtoBufSerializable
{
public:
	RoomProxyAddress();
	~RoomProxyAddress();
	virtual void * operator[](string name);
public:
	std::string ip = "";
	int port;
};


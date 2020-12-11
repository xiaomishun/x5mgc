#pragma once
#include "../Utils.h"
class UserIdentity :public ProtoBufSerializable
{
public:
	UserIdentity();
	~UserIdentity();
	virtual void * operator[](string name);
	public:
	int64_t account = 0;
	unsigned int channel = 0;
	unsigned int zoneid = 0;
};


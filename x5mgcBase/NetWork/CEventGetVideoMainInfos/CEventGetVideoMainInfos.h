#pragma once
#include "../Utils.h"
class CEventGetVideoMainInfos : public ProtoBufSerializable
{
public:
	CEventGetVideoMainInfos();
	~CEventGetVideoMainInfos();
	virtual void * operator[](string name);
public:
	int f7245a = 1;
	int f7246b = 0;
	int f7247c = 20;//´ý¶¨28
	int f7248d = 1;
	int f7249e = 1;
};


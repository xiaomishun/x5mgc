#pragma once
#include "../Utils.h"
class CEventIgnoreFreeGift :public ProtoBufSerializable
{
public:
	CEventIgnoreFreeGift();
	~CEventIgnoreFreeGift();
	virtual void * operator[](string name);
public:
	bool is_ignore = true;
};


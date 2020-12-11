#pragma once
#include "../Utils.h"
class CEventIgnoreFreeGiftRes :public ProtoBufSerializable
{
public:
	CEventIgnoreFreeGiftRes();
	~CEventIgnoreFreeGiftRes();
	virtual void * operator[](string name);
public:
	int res = false;
	bool is_ignore = false;
};


#pragma once
#include "../Utils.h"
class CEventGetPlayerBasicCardInfo : public ProtoBufSerializable
{
public:
	CEventGetPlayerBasicCardInfo();
	~CEventGetPlayerBasicCardInfo();
	virtual void * operator[](string name);
public:
	int64_t player_id = 0;
	int code = 0;
};


#pragma once
#include "../Utils.h"
#include "PlayerBasicCardInfo.h"
class CEventGetPlayerBasicCardInfoRes : public ProtoBufSerializable
{
public:
	CEventGetPlayerBasicCardInfoRes();
	~CEventGetPlayerBasicCardInfoRes();
	virtual void * operator[](string name);
public:
	int ret = 0;
	PlayerBasicCardInfo player_basic_card_info;
	int f8280c = 0;
};


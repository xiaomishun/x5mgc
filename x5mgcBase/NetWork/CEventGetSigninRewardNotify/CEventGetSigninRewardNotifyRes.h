#pragma once
#include "../Utils.h"
class CEventGetSigninRewardNotifyRes : public ProtoBufSerializable
{
public:
	CEventGetSigninRewardNotifyRes();
	~CEventGetSigninRewardNotifyRes();
	virtual void * operator[](string name);
public:
	int status = 0;
	bool is_Daily = false;
	bool is_Acc = false;//´ý¶¨28
	bool f11246d = false;
};


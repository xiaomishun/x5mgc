#pragma once
#include "../Utils.h"
class CReward :public ProtoBufSerializable
{
public:
	CReward();
	~CReward();
	virtual void * operator[](string name);
public:
		int type;
		int male_data;
		int female_data;
		int count;
		int channel;
};


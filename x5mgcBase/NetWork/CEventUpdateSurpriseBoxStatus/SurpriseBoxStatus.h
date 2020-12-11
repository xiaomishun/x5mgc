#pragma once
#include "../Utils.h"
class SurpriseBoxStatus :public ProtoBufSerializable
{
public:
	SurpriseBoxStatus();
	~SurpriseBoxStatus();
	virtual void * operator[](string name);
public:
	bool active = false;
	int precent = 0;
	int cd_seconds = 0;
	int need_flower = 0;
	int left_open_times = 0;
	int total_cd_seconds = 0;
	int nest_left_open_times = 0;
};


#pragma once
#include "../Utils.h"
#include "SurpriseBoxStatus.h"
class CEventUpdateSurpriseBoxStatus :public ProtoBufSerializable
{
public:
	CEventUpdateSurpriseBoxStatus();
	~CEventUpdateSurpriseBoxStatus();
	virtual void * operator[](string name);
public:
	int activity_id = 0;
	SurpriseBoxStatus box_status;
};


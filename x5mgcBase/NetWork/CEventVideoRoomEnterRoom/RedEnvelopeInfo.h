#pragma once
#include "../Utils.h"
#include "RedEnvelopeGrabberInfo.h"

class RedEnvelopeInfo :public ProtoBufSerializable
{
public:
	RedEnvelopeInfo();
	~RedEnvelopeInfo();
	virtual void * operator[](string name);
public:
	int64_t publisher = 0;
	std::string nick;
	std::string zone;
	int publish_time = 0;
	int total_money = 0;
	int remain_money = 0;
	int divide_count = 0;
	std::vector<RedEnvelopeGrabberInfo *>grabbers;
	int64_t red_id = 0;
private:

};


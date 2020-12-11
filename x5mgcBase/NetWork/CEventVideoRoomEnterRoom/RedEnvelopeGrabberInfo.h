#pragma once
#include "../Utils.h"


class RedEnvelopeGrabberInfo :public ProtoBufSerializable
{
public:
	RedEnvelopeGrabberInfo();
	~RedEnvelopeGrabberInfo();
	virtual void * operator[](string name);
public:
	int64_t grabber = 0;
	std::string nick;
	std::string zone ;
	int grab_count = 0;
private:

};


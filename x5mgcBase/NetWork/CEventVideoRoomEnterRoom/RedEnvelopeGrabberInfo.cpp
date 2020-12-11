#include "RedEnvelopeGrabberInfo.h"

RedEnvelopeGrabberInfo::RedEnvelopeGrabberInfo():ProtoBufSerializable(this)
{
	registerField("grabber", "", Descriptor::Int64, 1);// 抢红包的人id
	registerField("nick", "", Descriptor::TypeString, 2);// 昵称
	registerField("zone", "", Descriptor::TypeString, 3);// 大区名
	registerField("grab_count", "", Descriptor::Int32, 4);// 抢到的数量
}

RedEnvelopeGrabberInfo::~RedEnvelopeGrabberInfo()
{

}

void * RedEnvelopeGrabberInfo::operator[](string name)
{
	if (name == "grabber"){
		return &this->grabber;
	}
	else if (name == "nick") {
		return &this->nick;
	}
	else if (name == "zone") {
		return &this->zone;
	}
	else if (name == "grab_count") {
		return &this->grab_count;
	}
	return nullptr;
}

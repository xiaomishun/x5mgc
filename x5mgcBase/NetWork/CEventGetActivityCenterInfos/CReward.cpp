#include "CReward.h"



CReward::CReward() :ProtoBufSerializable(this)
{
	registerField("type", "", Descriptor::Int32, 1);
	registerField("male_data", "", Descriptor::Int32, 2);
	registerField("female_data", "", Descriptor::Int32, 3);
	registerField("count", "", Descriptor::Int32, 4);
	registerField("channel", "", Descriptor::Int32, 5);
}

CReward::~CReward()
{

}

void * CReward::operator[](string name)
{
	if (name == "type") {
		return &this->type;
	}
	else if (name == "male_data") {
		return &this->male_data;
	}
	else if (name == "female_data") {
		return &this->female_data;
	}
	else if (name == "count") {
		return &this->count;
	}
	else if (name == "channel") {
		return &this->channel;
	}
	return nullptr;
}

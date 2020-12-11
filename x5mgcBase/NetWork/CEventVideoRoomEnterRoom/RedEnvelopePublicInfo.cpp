#include "RedEnvelopePublicInfo.h"

RedEnvelopePublicInfo::RedEnvelopePublicInfo():ProtoBufSerializable(this)
{
	registerField("publisher", "", Descriptor::Int64, 1);
	registerField("nick", "", Descriptor::TypeString, 2);
	registerField("zone", "", Descriptor::TypeString, 3);
	registerField("total_money", "", Descriptor::Int32, 4);
	registerField("divide_count", "", Descriptor::Int32, 5);
	registerField("red_id", "", Descriptor::Int64, 6);
	registerField("room_audience_count", "", Descriptor::Int32, 7);
	registerField("delay_audience_count", "", Descriptor::Int32, 8);
	registerField("red_envelope_duration", "", Descriptor::Int32, 9);
	registerField("small_red_envelope_duration", "", Descriptor::Int32, 10);
}

RedEnvelopePublicInfo::~RedEnvelopePublicInfo()
{

}

void * RedEnvelopePublicInfo::operator[](string name)
{
	if (name == "publisher"){
		return &this->publisher;
	}
	else if (name == "nick") {
		return &this->nick;
	}
	else if (name == "zone") {
		return &this->zone;
	}
	else if (name == "total_money") {
		return &this->total_money;
	}
	else if (name == "divide_count") {
		return &this->divide_count;
	}
	else if (name == "red_id") {
		return &this->red_id;
	}
	else if (name == "room_audience_count") {
		return &this->room_audience_count;
	}
	else if (name == "delay_audience_count") {
		return &this->delay_audience_count;
	}
	else if (name == "red_envelope_duration") {
		return &this->red_envelope_duration;
	}
	else if (name == "small_red_envelope_duration") {
		return &this->small_red_envelope_duration;
	}
	return nullptr;
}

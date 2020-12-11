#include "SurpriseBoxStatus.h"



SurpriseBoxStatus::SurpriseBoxStatus() :ProtoBufSerializable(this)
{
	registerField("active", "", Descriptor::TypeBoolean, 1);
	registerField("precent", "", Descriptor::Int32, 2);
	registerField("cd_seconds", "", Descriptor::Int32, 3);
	registerField("need_flower", "", Descriptor::Int32, 4);
	registerField("left_open_times", "", Descriptor::Int32, 5);
	registerField("total_cd_seconds", "", Descriptor::Int32, 6);
	registerField("nest_left_open_times", "", Descriptor::Int32, 7);
}

SurpriseBoxStatus::~SurpriseBoxStatus()
{

}

void * SurpriseBoxStatus::operator[](string name)
{
	if (name == "active") {
		return &this->active;
	}
	else if (name == "precent") {
		return &this->precent;
	}
	else if (name == "cd_seconds") {
		return &this->cd_seconds;
	}
	else if (name == "need_flower") {
		return &this->need_flower;
	}
	else if (name == "left_open_times") {
		return &this->left_open_times;
	}
	else if (name == "total_cd_seconds") {
		return &this->total_cd_seconds;
	}
	else if (name == "nest_left_open_times") {
		return &this->nest_left_open_times;
	}
	return nullptr;
}

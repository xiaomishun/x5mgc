#include "CEventUpdateSurpriseBoxStatus.h"



CEventUpdateSurpriseBoxStatus::CEventUpdateSurpriseBoxStatus() :ProtoBufSerializable(this)
{
	registerField("activity_id", "", Descriptor::Int32, 1);
	registerField("box_status", typeid(SurpriseBoxStatus).name(), Descriptor::Compound, 2);
}

CEventUpdateSurpriseBoxStatus::~CEventUpdateSurpriseBoxStatus()
{

}

void * CEventUpdateSurpriseBoxStatus::operator[](string name)
{
	if (name == "activity_id") {
		return &this->activity_id;
	}
	else if (name == "box_status") {
		return &this->box_status;
	}
	return nullptr;
}

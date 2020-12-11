#include "VideoActivityInfoToClient.h"



VideoActivityInfoToClient::VideoActivityInfoToClient():ProtoBufSerializable(this)
{
	registerField("id", "", Descriptor::Int32, 1);
	registerField("name", "", Descriptor::TypeString, 2);
	registerField("desc", "", Descriptor::TypeString, 3);
	registerField("begin_time", "", Descriptor::Int32, 4);
	registerField("end_time", "", Descriptor::Int32, 5);
	registerFieldForList("rewards", typeid(CReward).name(), Descriptor::Compound, 6);
	registerFieldForDict("completed_conditions", "", Descriptor::Int32, typeid(ProgressToClient).name(), Descriptor::Compound, 7);
	registerField("status", "", Descriptor::Int32, 8);
	registerField("tip", "", Descriptor::TypeString, 9);
}


VideoActivityInfoToClient::~VideoActivityInfoToClient()
{
	for (size_t i = 0; i < rewards.size(); i++)
	{
		delete rewards[i];
	}
	rewards.clear();
	map<int*, ProgressToClient *>::iterator it;
	for (it = completed_conditions.begin();  it != completed_conditions.end(); it++)
	{
		delete it->first;
		delete it->second;
	}
	completed_conditions.clear();
}

void * VideoActivityInfoToClient::operator[](string name)
{
	if (name == "id") {
		return &this->id;
	}
	else if (name == "name") {
		return &this->name;
	}
	else if (name == "desc") {
		return &this->desc;
	}
	else if (name == "begin_time") {
		return &this->begin_time;
	}
	else if (name == "end_time") {
		return &this->end_time;
	}
	else if (name == "rewards") {
		return &this->rewards;
	}
	else if (name == "status") {
		return &this->status;
	}
	else if (name == "tip") {
		return &this->tip;
	}
	else if (name == "completed_conditions") {
		return &this->completed_conditions;
	}
	return nullptr;
}

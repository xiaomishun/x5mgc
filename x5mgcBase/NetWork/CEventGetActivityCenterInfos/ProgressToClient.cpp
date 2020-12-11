#include "ProgressToClient.h"



ProgressToClient::ProgressToClient() :ProtoBufSerializable(this)
{
	registerField("need_progress", "", Descriptor::Int64, 1);
	registerField("cur_progress", "", Descriptor::Int64, 2);
}

ProgressToClient::~ProgressToClient()
{

}

void * ProgressToClient::operator[](string name)
{
	if (name == "need_progress") {
		return &this->need_progress;
	}
	else if (name == "cur_progress") {
		return &this->cur_progress;
	}
	return nullptr;
}

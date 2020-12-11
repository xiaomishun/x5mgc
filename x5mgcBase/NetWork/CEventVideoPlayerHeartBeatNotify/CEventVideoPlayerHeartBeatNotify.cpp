#include "CEventVideoPlayerHeartBeatNotify.h"

CEventVideoPlayerHeartBeatNotify::CEventVideoPlayerHeartBeatNotify():ProtoBufSerializable(this)
{
	registerField("trans_id", "", Descriptor::Int64, 1);
}

CEventVideoPlayerHeartBeatNotify::~CEventVideoPlayerHeartBeatNotify()
{

}

void * CEventVideoPlayerHeartBeatNotify::operator[](string name)
{
	if (name == "trans_id"){
		return &this->trans_id;
	}
	return nullptr;
}

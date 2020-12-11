#include "CEventGetVideoPlayerInfo.h"

CEventGetVideoPlayerInfo::CEventGetVideoPlayerInfo():ProtoBufSerializable(this)
{
	registerField("transid","", Descriptor::Int32, 1);
}

CEventGetVideoPlayerInfo::~CEventGetVideoPlayerInfo()
{

}

void * CEventGetVideoPlayerInfo::operator[](string name)
{
	if (name == "transid") {
		return &transid;
	}
	return nullptr;
}

#include "CEventGetVideoMainInfosRes.h"



CEventGetVideoMainInfosRes::CEventGetVideoMainInfosRes():ProtoBufSerializable(this)
{
	registerField("f7250a", "", Descriptor::Int32, 1);
	registerFieldForList("RoomList", typeid(CEventVideoRoomInfo).name(), Descriptor::Compound, 2);
	registerFieldForList("RoomTagList", typeid(CEventGetVideoRoomTagInfosRes).name(), Descriptor::Compound, 3);
}


CEventGetVideoMainInfosRes::~CEventGetVideoMainInfosRes()
{
	Reset();
}

void CEventGetVideoMainInfosRes::Reset()
{
	for (size_t i = 0; i < RoomList.size(); i++)
	{
		delete RoomList[i];
	}
	RoomList.clear();
	for (size_t i = 0; i < RoomTagList.size(); i++)
	{
		delete RoomTagList[i];
	}
	RoomTagList.clear();
}

void * CEventGetVideoMainInfosRes::operator[](string name)
{
	if (name == "f7250a") {
		return &this->f7250a;
	}
	else if (name == "RoomList") {
		return &this->RoomList;
	}
	else if (name == "RoomTagList") {
		return &this->RoomTagList;
	}
	return nullptr;
}



#include "CEventGetVideoHistoryInfosRes.h"



CEventGetVideoHistoryInfosRes::CEventGetVideoHistoryInfosRes():ProtoBufSerializable(this)
{
	registerField("time_stamp", "", Descriptor::Int32, 1); // «Î«Û ±º‰	
	registerFieldForList("room_proxy_infos", typeid(RoomListInfo).name(), Descriptor::Compound, 2);
}


CEventGetVideoHistoryInfosRes::~CEventGetVideoHistoryInfosRes()
{
	Reset();
}

void CEventGetVideoHistoryInfosRes::Reset()
{
	for (size_t i = 0; i < room_proxy_infos.size(); i++)
	{
		delete room_proxy_infos[i];
	}
	room_proxy_infos.clear();
}

void * CEventGetVideoHistoryInfosRes::operator[](string name)
{
	if (name == "time_stamp") {
		return &this->time_stamp;
	}
	else if (name == "room_proxy_infos") {
		return &this->room_proxy_infos;
	}
	return nullptr;
}

#include "CEventQueryVideoAccountInfoRes.h"



CEventQueryVideoAccountInfoRes::CEventQueryVideoAccountInfoRes():ProtoBufSerializable(this)
{
	registerField("time_stamp", "", Descriptor::Int32, 1); // 请求时间
	registerField("succ", "", Descriptor::TypeBoolean, 2);// 是否成功，返回false其他信息无效
	registerFieldForList("room_proxy_infos", typeid(RoomProxyInfo).name(), Descriptor::Compound, 3);//所选择大区room_proxy信息
	registerFieldForList("account_infos", typeid(UserIdentity).name(), Descriptor::Compound, 4);// 视频角色信息
	registerField("err_code", "", Descriptor::Int32, 5);// 错误代码
	registerField("last_login_acc", typeid(UserIdentity).name(), Descriptor::Compound, 6);// 错误代码
	
}


CEventQueryVideoAccountInfoRes::~CEventQueryVideoAccountInfoRes()
{
	Reset();
}

void CEventQueryVideoAccountInfoRes::Reset()
{

	for (size_t i = 0; i < room_proxy_infos.size(); i++)
	{
		delete room_proxy_infos[i];
	}
	room_proxy_infos.clear();
	for (size_t i = 0; i < account_infos.size(); i++)
	{
		delete account_infos[i];
	}
	account_infos.clear();
}

void * CEventQueryVideoAccountInfoRes::operator[](string name)
{
	if (name == "time_stamp") {
		return &this->time_stamp;
	}
	else if (name == "succ") {
		return &this->succ;
	}
	else if (name == "room_proxy_infos") {
		return &this->room_proxy_infos;
	}
	else if (name == "account_infos") {
		return &this->account_infos;
	}
	else if (name == "err_code") {
		return &this->err_code;
	}
	else if (name == "last_login_acc") {
		return &this->last_login_acc;
	}
	return nullptr;
}

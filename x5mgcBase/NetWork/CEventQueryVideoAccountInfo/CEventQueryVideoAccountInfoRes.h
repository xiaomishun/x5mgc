#pragma once
#include "../Utils.h"
#include "RoomProxyInfo.h"
#include "UserIdentity.h"
class CEventQueryVideoAccountInfoRes : public ProtoBufSerializable
{
public:
	CEventQueryVideoAccountInfoRes();
	~CEventQueryVideoAccountInfoRes();
	void Reset();
	virtual void * operator[](string name);
public:
	int time_stamp = 1;// 请求时间
	bool succ = false;//是否成功，返回false其它所有信息无效
	std::vector<RoomProxyInfo *> room_proxy_infos;  //所选大区room_proxy信息
	std::vector<UserIdentity *> account_infos; //视频角色信息
	int err_code = 0;//错误码
	UserIdentity last_login_acc;//上次登录的角色
};


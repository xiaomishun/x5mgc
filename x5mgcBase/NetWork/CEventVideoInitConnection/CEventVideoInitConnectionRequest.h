#pragma once
#include "..//Utils.h"
#include "..//CEventQueryVideoAccountInfo/UserIdentity.h"
class CEventVideoInitConnectionRequest : public ProtoBufSerializable
{
public:
	CEventVideoInitConnectionRequest();
	~CEventVideoInitConnectionRequest();
	virtual void * operator[](string name);
public:
	UserIdentity uid;
	int account = 0;
	int channel = 0;
	int zoneid = 0;
	int roomID = 0;
	int64_t trans_id = 0;
	int client_device_type = 1;
	int appid = 0;
	std::string skey;
	std::string mobile_version;
	std::string m_open_id;
	int logic_version = 0;
	std::string android_md5;
};


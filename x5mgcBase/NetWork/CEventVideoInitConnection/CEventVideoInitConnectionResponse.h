#pragma once
#include "..//Utils.h"
class CEventVideoInitConnectionResponse :public ProtoBufSerializable
{
public:
	CEventVideoInitConnectionResponse();
	~CEventVideoInitConnectionResponse();
	virtual void * operator[](string name);
public:
	int res = 0;
	int server_time = 0;
	int64_t trans_id = 0;
	int video_zone_id = 0;
	int proxy_id = 0;
	int tunnel_id = 0;
};


#include "CEventVideoInitConnectionResponse.h"



CEventVideoInitConnectionResponse::CEventVideoInitConnectionResponse():ProtoBufSerializable(this)
{
	registerField("res", "", Descriptor::Int32, 1);
	registerField("server_time", "", Descriptor::Int32, 2);
	registerField("trans_id", "", Descriptor::Int64, 3);
	registerField("video_zone_id", "", Descriptor::Int32, 4);
	registerField("proxy_id", "", Descriptor::Int32, 5);
	registerField("tunnel_id", "", Descriptor::Int32, 6);
}


CEventVideoInitConnectionResponse::~CEventVideoInitConnectionResponse()
{
}

void * CEventVideoInitConnectionResponse::operator[](string name)
{
	if (name == "res") {
		return &res;
	}
	else if (name == "server_time") {
		return &server_time;
	}
	else if (name == "trans_id") {
		return &trans_id;
	}
	else if (name == "video_zone_id") {
		return &video_zone_id;
	}
	else if (name == "proxy_id") {
		return &proxy_id;
	}
	else if (name == "tunnel_id") {
		return &tunnel_id;
	}
	return nullptr;
}

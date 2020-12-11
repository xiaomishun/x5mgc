#pragma once
#include "../Utils.h"
class CEventQueryVideoAccountInfo : public ProtoBufSerializable
{
public:
	CEventQueryVideoAccountInfo();
	~CEventQueryVideoAccountInfo();
	virtual void * operator[](string name);
public :
	//3B7603B4D4300529776ECF8B507BA111
	//A41A71DC7954E74D2BD5A6CE56C50BA0
	uint32_t time_stamp = 0;
	uint32_t device_type = 1;
	uint32_t m_appid = 1105583531;
	//34397AA3549AE6FD847F6470FD0DDDA5
	//FE8F2B766F049D3620145D7D998DC846
	string m_skey = "34397AA3549AE6FD847F6470FD0DDDA5";
	string m_open_id = "FE8F2B766F049D3620145D7D998DC846";
};


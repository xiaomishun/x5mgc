#pragma once
#include "../Utils.h"
class CEventVideoRoomInfo :public ProtoBufSerializable
{
public:
	CEventVideoRoomInfo();
	~CEventVideoRoomInfo();
	virtual void * operator[](string name);
public:
	//std::vector<>

	int a = 0;
	int b = 0;
	int c = 0;
	std::string d;
	std::string e;

private:

};


#pragma once
#include "../Utils.h"
class AnchorData2 :public ProtoBufSerializable
{
public:
	AnchorData2();
	~AnchorData2();
	virtual void * operator[](string name);
public:
	int64_t pstid = 0;
	int level = 0;
	int starlight = 0;
	int popularity = 0;
	int followed = 0;
};


#pragma once
#include "../Utils.h"
class AnchorImpressionData :public ProtoBufSerializable
{
public:
	AnchorImpressionData();
	~AnchorImpressionData();
	virtual void * operator[](string name);
public:
	int count = 0;
	int impression_id = 0;
private:

};


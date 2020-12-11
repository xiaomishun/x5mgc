#pragma once
#include "../Utils.h"
#include "AnchorImpressionData.h"
class AnchorImpressionDataServer :public ProtoBufSerializable
{
public:
	AnchorImpressionDataServer();
	~AnchorImpressionDataServer();
	void Reset();
	virtual void * operator[](string name);
public:
	//std::vector<>
	std::vector<AnchorImpressionData *> impressions;
	int total_count = 0;
	int player_count = 0;
private:

};


#include "AnchorImpressionDataServer.h"

AnchorImpressionDataServer::AnchorImpressionDataServer():ProtoBufSerializable(this)
{
	registerFieldForList("impressions", typeid(AnchorImpressionData).name(), Descriptor::Compound, 1);
	registerField("total_count", "", Descriptor::Int32, 2);
	registerField("player_count", "", Descriptor::Int32, 3);
}

AnchorImpressionDataServer::~AnchorImpressionDataServer()
{
	Reset();
}

void AnchorImpressionDataServer::Reset()
{
	for (size_t i = 0; i < impressions.size(); i++)
	{
		delete impressions[i];
	}
	impressions.clear();
}

void * AnchorImpressionDataServer::operator[](string name)
{
	if (name == "impressions"){
		return &this->impressions;
	}
	else if (name == "total_count"){
		return &this->total_count;
	}
	else if (name == "player_count"){
		return &this->player_count;
	}
	return nullptr;
}

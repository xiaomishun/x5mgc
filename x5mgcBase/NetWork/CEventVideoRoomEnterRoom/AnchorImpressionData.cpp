#include "AnchorImpressionData.h"

AnchorImpressionData::AnchorImpressionData():ProtoBufSerializable(this)
{
	registerField("count", "", Descriptor::Int32, 1);
	registerField("impression_id", "", Descriptor::Int32, 2);
}

AnchorImpressionData::~AnchorImpressionData()
{

}

void * AnchorImpressionData::operator[](string name)
{
	if (name == "count"){
		return &this->count;
	}
	else if (name == "impression_id"){
		return &this->impression_id;
	}
	return nullptr;
}

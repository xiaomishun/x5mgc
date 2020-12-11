#include "AnchorData2.h"



AnchorData2::AnchorData2() :ProtoBufSerializable(this)
{
	registerField("pstid", "", Descriptor::Int64, 1);
	registerField("level", "", Descriptor::Int32, 2);
	registerField("starlight", "", Descriptor::Int32, 3);
	registerField("popularity", "", Descriptor::Int32, 4);
	registerField("followed", "", Descriptor::Int32, 5);
}

AnchorData2::~AnchorData2()
{

}

void * AnchorData2::operator[](string name)
{
	if (name == "pstid") {
		return &this->pstid;
	}
	else if (name == "level") {
		return &this->level;
	}
	else if (name == "starlight") {
		return &this->starlight;
	}
	else if (name == "popularity") {
		return &this->popularity;
	}
	else if (name == "followed") {
		return &this->followed;
	}
	return nullptr;
}

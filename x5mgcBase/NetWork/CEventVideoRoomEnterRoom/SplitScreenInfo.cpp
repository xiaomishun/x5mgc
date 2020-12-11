#include "SplitScreenInfo.h"

SplitScreenInfo::SplitScreenInfo():ProtoBufSerializable(this)
{
	registerField("status", "", Descriptor::Int32, 1);
	
	registerField("anchorName", "", Descriptor::TypeString, 2);
	registerField("anchorId", "", Descriptor::Int64, 3);
	registerField("vid", "", Descriptor::Int32, 4);
	registerField("f4001e", "", Descriptor::TypeString, 5);
}

SplitScreenInfo::~SplitScreenInfo()
{

}

void * SplitScreenInfo::operator[](string name)
{
	if (name == "status"){
		return &this->status;
	}
	else if (name == "vid"){
		return &this->vid;
	}
	else if (name == "anchorName"){
		return &this->anchorName;
	}
	else if (name == "anchorId"){
		return &this->anchorId;
	}
	else if (name == "f4001e"){
		return &this->f4001e;
	}
	return nullptr;
}

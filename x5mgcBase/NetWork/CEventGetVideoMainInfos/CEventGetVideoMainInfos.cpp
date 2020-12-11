#include "CEventGetVideoMainInfos.h"



CEventGetVideoMainInfos::CEventGetVideoMainInfos():ProtoBufSerializable(this)
{
	registerField("f7245a", "", Descriptor::Int32, 1);
	registerField("f7246b", "", Descriptor::Int32, 2); 
	registerField("f7247c", "", Descriptor::Int32, 3);
	registerField("f7248d", "", Descriptor::Int32, 4);
	registerField("f7249e", "", Descriptor::Int32, 5);
}


CEventGetVideoMainInfos::~CEventGetVideoMainInfos()
{

}

void * CEventGetVideoMainInfos::operator[](string name)
{
	if (name == "f7245a") {
		return &this->f7245a;
	}
	else if (name == "f7246b") {
		return &this->f7246b;
	}
	else if (name == "f7247c") {
		return &this->f7247c;
	}
	else if (name == "f7248d") {
		return &this->f7248d;
	}
	else if (name == "f7249e") {
		return &this->f7249e;
	}
	return nullptr;
}

#include "CEventGetVideoRoomTagInfosRes.h"



CEventGetVideoRoomTagInfosRes::CEventGetVideoRoomTagInfosRes():ProtoBufSerializable(this)
{
	registerField("f7261a", "", Descriptor::Int32, 1);
	registerField("f7262b", "", Descriptor::Int32, 2);
	registerField("f7263c", "", Descriptor::Int32, 3);
	registerFieldForList("HomePageInfo", typeid(VideoHomePageRoomInfo).name(), Descriptor::Compound, 4);
	registerField("f7265e", "", Descriptor::Int32, 5);
	registerField("f7266f", "", Descriptor::Int32, 6);
	//registerField("f7267g", "", Descriptor::Int32, 7);
	//registerField("f7268h", "", Descriptor::Int32, 8);
}


CEventGetVideoRoomTagInfosRes::~CEventGetVideoRoomTagInfosRes()
{
	for (size_t i = 0; i < HomePageInfo.size(); i++)
	{
		delete HomePageInfo[i];
	}
	HomePageInfo.clear();
}

void * CEventGetVideoRoomTagInfosRes::operator[](string name)
{
	if (name == "f7261a") {
		return &this->f7261a;
	}
	else if (name == "f7262b") {
		return &this->f7262b;
	}
	else if (name == "f7263c") {
		return &this->f7263c;
	}
	else if (name == "HomePageInfo") {
		return &this->HomePageInfo;
	}
	else if (name == "f7265e") {
		return &this->f7265e;
	}
	else if (name == "f7266f") {
		return &this->f7266f;
	}
	else if (name == "f7267g") {
		return &this->f7267g;
	}
	else if (name == "f7268h") {
		return &this->f7268h;
	}
	return nullptr;
}

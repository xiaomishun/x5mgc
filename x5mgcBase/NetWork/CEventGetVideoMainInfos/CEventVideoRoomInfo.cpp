#include "CEventVideoRoomInfo.h"

CEventVideoRoomInfo::CEventVideoRoomInfo():ProtoBufSerializable(this)
{
	registerField("m_a", "", Descriptor::Int32, 1);
	registerField("m_b", "", Descriptor::Int32, 2);
	registerField("m_c", "", Descriptor::Int32, 3);
	registerField("m_d", "", Descriptor::TypeString, 4);
	registerField("m_e", "", Descriptor::TypeString, 5);
}

CEventVideoRoomInfo::~CEventVideoRoomInfo()
{

}

void * CEventVideoRoomInfo::operator[](string name)
{
	if (name == "m_a")
	{
		return &this->a;
	}
	else if (name == "m_b")
	{
		return &this->b;
	}
	else if (name == "m_c")
	{
		return &this->c;
	}
	else if (name == "m_d")
	{
		return &this->d;
	}
	else if (name == "m_e")
	{
		return &this->e;
	}
	return nullptr;
}

#include "VideoResolution.h"

VideoResolution::VideoResolution():ProtoBufSerializable(this)
{
	registerField("m_width", "", Descriptor::Int32, 1);
	registerField("m_height", "", Descriptor::Int32, 2);
}

VideoResolution::~VideoResolution()
{

}

void * VideoResolution::operator[](string name)
{
	if (name == "m_width")
	{
		return &this->m_width;
	}
	else if (name == "m_height")
	{
		return &this->m_height;
	}

	return nullptr;
}

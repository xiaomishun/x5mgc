#include "VideoVoteEntry.h"

VideoVoteEntry::VideoVoteEntry():ProtoBufSerializable(this)
{
	registerField("content", "", Descriptor::TypeString, 1);
	registerField("curr_count", "", Descriptor::Int32, 2);
}

VideoVoteEntry::~VideoVoteEntry()
{

}

void * VideoVoteEntry::operator[](string name)
{
	if (name == "content"){
		return &this->content;
	}
	else if (name == "curr_count") {
		return &this->curr_count;
	}
	return nullptr;
}

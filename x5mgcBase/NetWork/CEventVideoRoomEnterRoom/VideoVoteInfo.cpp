#include "VideoVoteInfo.h"

VideoVoteInfo::VideoVoteInfo():ProtoBufSerializable(this)
{
	registerField("vote_id", "", Descriptor::Int64, 1);
	registerField("vote_topic", "", Descriptor::TypeString, 2);
	registerField("anchor", "", Descriptor::Int64, 3);
	registerField("anchor_name", "", Descriptor::TypeString, 4);
	registerField("start_voting_time", "", Descriptor::Int32, 5);
	registerField("end_voting_time", "", Descriptor::Int32, 6);
	registerField("optional_max_count", "", Descriptor::Int32, 7);
	registerFieldForList("vote_entries", typeid(VideoVoteEntry).name(), Descriptor::Compound, 8);
}

VideoVoteInfo::~VideoVoteInfo()
{
	Reset();
}

void VideoVoteInfo::Reset()
{
	for (size_t i = 0; i < vote_entries.size(); i++)
	{
		delete vote_entries[i];
	}
	vote_entries.clear();
}

void * VideoVoteInfo::operator[](string name)
{
	if (name == "vote_id"){
		return &this->vote_id;
	}
	else if (name == "vote_topic") {
		return &this->vote_topic;
	}
	else if (name == "anchor") {
		return &this->anchor;
	}
	else if (name == "anchor_name") {
		return &this->anchor_name;
	}
	else if (name == "start_voting_time") {
		return &this->start_voting_time;
	}
	else if (name == "end_voting_time") {
		return &this->end_voting_time;
	}
	else if (name == "optional_max_count") {
		return &this->optional_max_count;
	}
	else if (name == "vote_entries") {
		return &this->vote_entries;
	}
	return nullptr;
}

#pragma once
#include "../Utils.h"
#include "VideoVoteEntry.h"


class VideoVoteInfo :public ProtoBufSerializable
{
public:
	VideoVoteInfo();
	~VideoVoteInfo();
	void Reset();
	virtual void * operator[](string name);
public:
	int64_t vote_id = 0;
	std::string vote_topic;
	int64_t anchor = 0;
	std::string anchor_name;
	int start_voting_time = 0;
	int end_voting_time = 0;
	int optional_max_count = 0;
	std::vector<VideoVoteEntry*> vote_entries;
private:

};


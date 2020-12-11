#pragma once
#include "../Utils.h"


class VideoVoteEntry :public ProtoBufSerializable
{
public:
	VideoVoteEntry();
	~VideoVoteEntry();
	virtual void * operator[](string name);
public:
	std::string content;
	int curr_count = 0;
private:

};


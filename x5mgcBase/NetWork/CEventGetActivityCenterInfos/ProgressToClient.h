#pragma once
#include "../Utils.h"
class ProgressToClient :public ProtoBufSerializable
{
public:
	ProgressToClient();
	~ProgressToClient();
	virtual void * operator[](string name);
public:
	int64_t need_progress = 0;
	int64_t cur_progress = 0;
};


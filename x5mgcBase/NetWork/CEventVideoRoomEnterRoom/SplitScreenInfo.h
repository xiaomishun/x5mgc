#pragma once
#include "../Utils.h"



class SplitScreenInfo :public ProtoBufSerializable
{
public:
	SplitScreenInfo();
	~SplitScreenInfo();
	virtual void * operator[](string name);
public:
	enum SplitScreenStatus
	{
		SSS_Close = 0,
		SSS_Open = 1,
		SSS_Living = 2
	};
public:
	//std::vector<>

	int status = SplitScreenStatus::SSS_Close;
	//
	std::string anchorName;
	int64_t anchorId = 0;
	int vid = 0;
	std::string f4001e;



private:

};


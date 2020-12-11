#pragma once
#include "../Utils.h"
class VideoResolution :public ProtoBufSerializable
{
public:
	VideoResolution();
	~VideoResolution();
	virtual void * operator[](string name);
public:
	//std::vector<>

	int m_width = 0;
	int m_height = 0;
private:

};


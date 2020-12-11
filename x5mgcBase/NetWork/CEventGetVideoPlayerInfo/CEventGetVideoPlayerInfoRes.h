#pragma once
#include "../Utils.h"
#include "../CEventRefreshVideoCharInfoToClient/VideoCharInfo.h"
class CEventGetVideoPlayerInfoRes :public ProtoBufSerializable
{
public:
	CEventGetVideoPlayerInfoRes();
	~CEventGetVideoPlayerInfoRes();
	void Reset();
	virtual void * operator[](string name);
public:
	VideoCharInfo char_info;
	std::vector<int *> followed_anchors;
	bool succ = false;
	int64_t transid = 0;
private:

};


#pragma once
#include "../Utils.h"
#include "VideoToClientChatMessage.h"
class CEventVideoToClientChatMessage :public ProtoBufSerializable
{
public:
	CEventVideoToClientChatMessage();
	~CEventVideoToClientChatMessage();
	virtual void * operator[](string name);
public:
	VideoToClientChatMessage message;
	int anchor_id = 0;
	int starlight = 0;
	int popularity = 0;
	int add_anchor_exp = 0;
};


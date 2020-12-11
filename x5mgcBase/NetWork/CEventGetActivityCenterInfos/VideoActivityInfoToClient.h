#pragma once
#include "../Utils.h"
#include "CReward.h"
#include "ProgressToClient.h"
#include <map>
class VideoActivityInfoToClient : public ProtoBufSerializable
{
public:
	VideoActivityInfoToClient();
	~VideoActivityInfoToClient();
	virtual void * operator[](string name);
public:
	int id = 0;
	string name;
	string desc;
	string tip;
	int begin_time = 0;
	int end_time = 0;
	vector<CReward *>rewards;
	map<int*, ProgressToClient *>completed_conditions;
	//public var completed_conditions : Dictionary = new Dictionary;
	int status = 0;//0 未完成 1 完成未领奖 2 已领奖
};


#pragma once
#include "../Utils.h"
#include "VideoActivityInfoToClient.h"
class CEventGetActivityCenterInfosRes :public ProtoBufSerializable
{
public:
	CEventGetActivityCenterInfosRes();
	~CEventGetActivityCenterInfosRes();
	void Reset();
	virtual void * operator[](string name);
public:
	//std::vector<>


	int succ = 0;
	int level = 0;
	int exp = 0;
	int levelup_exp = 0;// 升下一级经验为0代表已经满级
	int video_money = 0;
	int vip_level = 0;
	bool has_taken_wage_today = 0;
	int  wage = 0;
	int  attached_wage = 0;
	std::vector<VideoActivityInfoToClient*>activity_infos;
	std::vector<VideoActivityInfoToClient*>daily_activity_infos;
	std::vector<VideoActivityInfoToClient*>activity_infos_web;
	std::vector<VideoActivityInfoToClient*>dev_activity;
	std::vector<VideoActivityInfoToClient*>add_activity;
	//public var activity_infos : Array = new Array;
	//public var daily_activity_infos : Array = new Array;
	//public var activity_infos_web : Array = new Array;
	//public var dev_activity : Array = new Array;
private:

};


#include "CEventGetActivityCenterInfosRes.h"

CEventGetActivityCenterInfosRes::CEventGetActivityCenterInfosRes():ProtoBufSerializable(this)
{
	registerField("succ", "", Descriptor::Int32, 1);
	registerField("level", "", Descriptor::Int32, 2);
	registerField("exp", "", Descriptor::Int32, 3);//¹Ø×¢
	registerField("levelup_exp", "", Descriptor::Int32, 4);
	registerField("video_money", "", Descriptor::Int32, 5);
	registerField("vip_level", "", Descriptor::Int32, 6);
	registerField("has_taken_wage_today", "", Descriptor::TypeBoolean, 7);
	registerField("wage", "", Descriptor::Int32, 8);
	registerField("attached_wage", "", Descriptor::Int32, 9);
	registerFieldForList("activity_infos", typeid(VideoActivityInfoToClient).name(), Descriptor::Compound, 10);
	registerFieldForList("daily_activity_infos", typeid(VideoActivityInfoToClient).name(), Descriptor::Compound, 11);
	registerFieldForList("activity_infos_web", typeid(VideoActivityInfoToClient).name(), Descriptor::Compound, 12);
	registerFieldForList("dev_activity", typeid(VideoActivityInfoToClient).name(), Descriptor::Compound, 13);
	registerFieldForList("add_activity", typeid(VideoActivityInfoToClient).name(), Descriptor::Compound, 14);
}

CEventGetActivityCenterInfosRes::~CEventGetActivityCenterInfosRes()
{
	Reset();
}

void CEventGetActivityCenterInfosRes::Reset()
{
	for (size_t i = 0; i < activity_infos.size(); i++)
	{
		delete activity_infos[i];
	}
	activity_infos.clear();
	for (size_t i = 0; i < daily_activity_infos.size(); i++)
	{
		delete daily_activity_infos[i];
	}
	daily_activity_infos.clear();
	for (size_t i = 0; i < activity_infos_web.size(); i++)
	{
		delete activity_infos_web[i];
	}
	activity_infos_web.clear();
	for (size_t i = 0; i < dev_activity.size(); i++)
	{
		delete dev_activity[i];
	}
	dev_activity.clear();
	for (size_t i = 0; i < add_activity.size(); i++)
	{
		delete add_activity[i];
	}
	add_activity.clear();
}


void * CEventGetActivityCenterInfosRes::operator[](string name)
{
	if (name == "succ")
	{
		return &succ;
	}
	else if (name == "level")
	{
		return &level;
	}
	else if (name == "exp")
	{
		return &exp;
	}
	else if (name == "levelup_exp")
	{
		return &levelup_exp;
	}
	else if (name == "video_money")
	{
		return &video_money;
	}
	else if (name == "vip_level")
	{
		return &vip_level;
	}
	else if (name == "has_taken_wage_today")
	{
		return &has_taken_wage_today;
	}
	else if (name == "wage")
	{
		return &wage;
	}
	else if (name == "attached_wage")
	{
		return &attached_wage;
	}
	else if (name == "activity_infos")
	{
		return &activity_infos;
	}
	else if (name == "daily_activity_infos")
	{
		return &daily_activity_infos;
	}
	else if (name == "activity_infos_web")
	{
		return &daily_activity_infos;
	}
	else if (name == "dev_activity")
	{
		return &dev_activity;
	}
	else if (name == "add_activity")
	{
		return &dev_activity;
	}
	return nullptr;
}

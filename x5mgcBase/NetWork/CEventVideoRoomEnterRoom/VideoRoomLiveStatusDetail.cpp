#include "VideoRoomLiveStatusDetail.h"



VideoRoomLiveStatusDetail::VideoRoomLiveStatusDetail() :ProtoBufSerializable(this)
{
	registerField("vid", "", Descriptor::TypeString, 1);
	registerField("anchor_pstid", "", Descriptor::Int64, 2);
	registerField("start_time", "", Descriptor::Int32, 3);
	registerField("sex", "", Descriptor::Int32, 4);
	registerField("name", "", Descriptor::TypeString, 5);
	registerField("description", "", Descriptor::TypeString, 6);
	registerField("popularity", "", Descriptor::Int32, 7);
	registerField("startlight", "", Descriptor::Int32, 8);
	registerField("place", "", Descriptor::TypeString, 9);
	registerField("followed", "", Descriptor::Int32, 10);
	registerField("deputy_anchor_name", "", Descriptor::TypeString, 11);
	registerField("deputy_anchor_zone_name", "", Descriptor::TypeString, 12);
	registerField("deputy_anchor_id", "", Descriptor::Int64, 13);
	registerField("talent_show_rank", "", Descriptor::Int32, 14);
	registerField("star_anchor", "", Descriptor::TypeBoolean, 15);
	registerField("pk_winner_order", "", Descriptor::Int32, 16);
	registerField("vid2", "", Descriptor::Int32, 17);
	registerField("starlight_needed", "", Descriptor::Int32, 18);
	registerField("impression", typeid(AnchorImpressionDataServer).name(), Descriptor::Compound, 19);
	registerField("twoweek_starlight", "", Descriptor::Int32, 20);
	registerField("anchor_type", "", Descriptor::Int32, 21);
	registerField("level", "", Descriptor::Int32, 22);
	registerField("server_id", "", Descriptor::Int32, 23);
	registerFieldForDict("extra_vid", "", Descriptor::Int32, "", Descriptor::TypeString, 24);
	registerField("m_anchor_url", "", Descriptor::TypeString, 25);
	registerField("f4440z", "", Descriptor::TypeBoolean, 26);
	registerField("f4393A", "", Descriptor::Int32, 27);
	registerField("split_screen_info", typeid(SplitScreenInfo).name(), Descriptor::Compound, 28);
	registerField("is_anchor_pk_anchor", "", Descriptor::TypeBoolean, 29);
	registerField("anchor_level", "", Descriptor::Int32, 30);
	registerField("anchor_exp", "", Descriptor::Int32, 31);
	registerField("anchor_levelup_exp", "", Descriptor::Int32, 32);
	registerField("is_bottleneck", "", Descriptor::TypeBoolean, 33);
	registerField("bottleneck_count", "", Descriptor::Int32, 34);
	registerField("bottleneck_need_count", "", Descriptor::Int32, 35);
	registerField("bottleneck_gift_id", "", Descriptor::Int32, 36);
	registerField("buff_percent", "", Descriptor::Int32, 37);
	registerField("starlight_rest_exp_today", "", Descriptor::Int32, 38);
	registerField("dream_gift_rest_exp_today", "", Descriptor::Int32, 39);
	registerField("anchor_badge", "", Descriptor::Int32, 40);
	registerField("lucky_draw_rest_exp_tody", "", Descriptor::Int32, 41);
	registerFieldForDict("vid_resolutions", "", Descriptor::Int32, typeid(VideoResolution).name(), Descriptor::Compound, 42);
	registerField("fps", "", Descriptor::Int32, 43);
	registerField("anchor_device_type", "", Descriptor::Int32, 44);
	registerField("is_vertical_live", "", Descriptor::TypeBoolean, 45);
	registerField("f4412T", "", Descriptor::Int32, 46);
	registerField("f4413U", "", Descriptor::Int32, 47);
	registerField("f4414V", "", Descriptor::TypeBoolean, 48);
}

VideoRoomLiveStatusDetail::~VideoRoomLiveStatusDetail()
{
	Reset();
}

void VideoRoomLiveStatusDetail::Reset()
{
	impression.Reset();

	map<int*, std::string*>::iterator it;
	for (it= extra_vid.begin(); it!= extra_vid.end(); it++)
	{
		delete it->first;
		delete it->second;
	}
	extra_vid.clear();
	std::map<int *, VideoResolution *>::iterator it2;
	for (it2 = vid_resolutions.begin(); it2 != vid_resolutions.end(); it2++)
	{
		delete it2->first;
		delete it2->second;
	}
	vid_resolutions.clear();


}

void * VideoRoomLiveStatusDetail::operator[](string name)
{
	if (name == "vid") {
		return &this->vid;
	}
	else if (name == "anchor_pstid") {
		return &this->anchor_pstid;
	}
	else if (name == "start_time") {
		return &this->start_time;
	}
	else if (name == "sex") {
		return &this->sex;
	}
	else if (name == "name") {
		return &this->name;
	}
	else if (name == "description") {
		return &this->description;
	}
	else if (name == "popularity") {
		return &this->popularity;
	}
	else if (name == "startlight") {
		return &this->startlight;
	}
	else if (name == "place") {
		return &this->place;
	}
	else if (name == "followed") {
		return &this->followed;
	}
	else if (name == "deputy_anchor_name") {
		return &this->deputy_anchor_name;
	}
	else if (name == "deputy_anchor_zone_name") {
		return &this->deputy_anchor_zone_name;
	}
	else if (name == "deputy_anchor_id") {
		return &this->deputy_anchor_id;
	}
	else if (name == "talent_show_rank") {
		return &this->talent_show_rank;
	}
	else if (name == "star_anchor") {
		return &this->star_anchor;
	}
	else if (name == "pk_winner_order") {
		return &this->pk_winner_order;
	}
	else if (name == "vid2") {
		return &this->vid2;
	}
	else if (name == "starlight_needed") {
		return &this->starlight_needed;
	}
	else if (name == "impression") {
		return &this->impression;
	}
	else if (name == "twoweek_starlight") {
		return &this->twoweek_starlight;
	}
	else if (name == "anchor_type") {
		return &this->anchor_type;
	}
	else if (name == "level") {
		return &this->level;
	}
	else if (name == "server_id") {
		return &this->server_id;
	}
	else if (name == "extra_vid") {
		return &this->extra_vid;
	}
	else if (name == "m_anchor_url") {
		return &this->m_anchor_url;
	}
	else if (name == "split_screen_info") {
		return &this->split_screen_info;
	}
	else if (name == "is_anchor_pk_anchor") {
		return &this->is_anchor_pk_anchor;
	}
	else if (name == "anchor_level") {
		return &this->anchor_level;
	}
	else if (name == "anchor_exp") {
		return &this->anchor_exp;
	}
	else if (name == "anchor_levelup_exp") {
		return &this->anchor_levelup_exp;
	}
	else if (name == "is_bottleneck") {
		return &this->is_bottleneck;
	}
	else if (name == "bottleneck_count") {
		return &this->bottleneck_count;
	}
	else if (name == "bottleneck_need_count") {
		return &this->bottleneck_need_count;
	}
	else if (name == "bottleneck_gift_id") {
		return &this->bottleneck_gift_id;
	}
	else if (name == "buff_percent") {
		return &this->buff_percent;
	}
	else if (name == "starlight_rest_exp_today") {
		return &this->starlight_rest_exp_today;
	}
	else if (name == "dream_gift_rest_exp_today") {
		return &this->dream_gift_rest_exp_today;
	}
	else if (name == "anchor_badge") {
		return &this->anchor_badge;
	}
	else if (name == "lucky_draw_rest_exp_tody") {
		return &this->lucky_draw_rest_exp_tody;
	}
	else if (name == "vid_resolutions") {
		return &this->vid_resolutions;
	}
	else if (name == "fps") {
		return &this->fps;
	}
	else if (name == "anchor_device_type") {
		return &this->anchor_device_type;
	}
	else if (name == "is_vertical_live") {
		return &this->is_vertical_live;
	}
	else if (name == "f4412T") {
		return &this->f4412T;
	}
	else if (name == "f4413U") {
		return &this->f4413U;
	}
	else if (name == "f4414V") {
		return &this->f4414V;
	}


	else if (name == "f4440z") {
		return &this->f4440z;
	}
	else if (name == "f4393A") {
		return &this->f4393A;
	}
	return nullptr;
}

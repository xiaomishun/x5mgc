#include "EnterVideoRoomInitInfo.h"



EnterVideoRoomInitInfo::EnterVideoRoomInitInfo() :ProtoBufSerializable(this)
//, live_detail(new VideoRoomLiveStatusDetail()),vote_info(new VideoVoteInfo), redenvelope_public(new RedEnvelopePublicInfo)
{
	registerField("status", "", Descriptor::Int32, 1);
	registerField("subject", "", Descriptor::Int32, 2);
	registerField("room_name", "", Descriptor::TypeString, 3);
	registerField("audience_count", "", Descriptor::Int32, 4);
	registerField("room_pic_info", "", Descriptor::Int32, 5);
	registerField("cur_giftpool_height", "", Descriptor::Int32, 6);
	registerField("max_giftpool_height", "", Descriptor::Int32, 7);
	registerField("live_detail", typeid(VideoRoomLiveStatusDetail).name(), Descriptor::Compound, 8);
	registerField("forbid_public_chat", "", Descriptor::TypeBoolean, 9);
	registerField("open_chat_cd_check", "", Descriptor::TypeBoolean, 10);
	registerField("chat_cd_time", "", Descriptor::Int32, 11);
	registerField("player_capacity", "", Descriptor::Int32, 12);
	registerField("vote_info", typeid(VideoVoteInfo).name(), Descriptor::Compound, 13);
	registerFieldForList("vote_selects", "", Descriptor::Int32, 14);
	registerField("vip_level", "", Descriptor::Int32, 15);
	registerField("vip_expire", "", Descriptor::Int32, 16);
	registerField("free_whistle_left", "", Descriptor::Int32, 17);
	registerField("vip_notify", "", Descriptor::Int32, 18);
	registerField("taken_vip_daily_reward_time", "", Descriptor::Int32, 19);
	registerField("talent_show_state", "", Descriptor::Int32, 20);

	registerField("judge_type", "", Descriptor::Int32, 21);
	registerField("talent_show_id", "", Descriptor::Int32, 22);
	registerField("video_guild_id", "", Descriptor::Int64, 23);
	registerField("notify_vg_name", "", Descriptor::TypeString, 24);
	registerField("low_video_uploadspeed", "", Descriptor::Int32, 25);
	registerField("normal_video_uploadspeed", "", Descriptor::Int32, 26);
	registerField("offline_become_member", "", Descriptor::TypeBoolean, 27);
	registerField("activity_type", "", Descriptor::Int32, 28);
	registerField("free_super_star_horn_left", "", Descriptor::Int32, 29);
	registerField("type", "", Descriptor::Int32, 30);

	registerField("public_chat_cd_on_enter", "", Descriptor::Int32, 31);
	registerField("flags", "", Descriptor::Int32, 32);
	registerField("vg_sp_anchor", "", Descriptor::Int64, 33);
	registerFieldForList("anchor_pk_rooms", "", Descriptor::Int32, 34);
	registerField("remain_crowdroom_count", "", Descriptor::Int32, 35);
	registerField("invisible", "", Descriptor::TypeBoolean, 36);
	registerFieldForList("redenvelopes", typeid(RedEnvelopeInfo).name(), Descriptor::Compound, 37); //房间内是否已发出红包
	registerField("taken_vip_weekly_reward_time", "", Descriptor::Int32, 38);
	registerField("is_nest_room", "", Descriptor::TypeBoolean, 39); //是否为小窝房间
	registerField("is_assistant", "", Descriptor::TypeBoolean, 40);

	registerField("attached_room", "", Descriptor::Int32, 41);
	registerField("attached_anchor", "", Descriptor::TypeString, 42);
	registerField("is_concert", "", Descriptor::TypeBoolean, 43);
	registerField("has_concert_ticket", "", Descriptor::TypeBoolean, 44);
	registerField("concert_is_open", "", Descriptor::TypeBoolean, 45);

	registerField("f4869T", "", Descriptor::TypeString, 46);
	registerField("f4870U", "", Descriptor::Int32, 47);

	registerField("attached_room_name", "", Descriptor::TypeString, 48);
	registerField("is_closed_by_admin", "", Descriptor::TypeBoolean, 49);
	registerField("redenvelope_public", typeid(RedEnvelopePublicInfo).name(), Descriptor::Compound, 50);

	registerField("free_times", "", Descriptor::Int32, 51);
	registerField("seat_price_reset_notice", "", Descriptor::Int32, 52);
	registerField("can_punch_in_room", "", Descriptor::TypeBoolean, 53);
	registerField("room_skin_id", "", Descriptor::Int32, 54);
	registerField("room_skin_level", "", Descriptor::Int32, 55);
	registerField("video_definition", "", Descriptor::Int32, 56);// 视频清晰度
	registerField("free_barrage_left", "", Descriptor::Int32, 57);//免费弹幕数量
	registerField("room_close_player_count", "", Descriptor::Int32, 58);// 房间关闭时最后的在线人数
	registerField("edu_flag", "", Descriptor::Int32, 59);//通知玩家教学标记信息

	registerField("f4884ah", "", Descriptor::TypeBoolean, 60);
	registerField("f4885ai", "", Descriptor::TypeBoolean, 61);
	registerField("f4886aj", "", Descriptor::TypeBoolean, 62);
	registerField("f4887ak", "", Descriptor::TypeString, 63);
	registerField("f4888al", "", Descriptor::TypeBoolean, 64);
	registerField("f4889am", "", Descriptor::TypeBoolean, 65);
	registerField("f4890an", "", Descriptor::Int32, 66);
	registerField("f4891ao", "", Descriptor::TypeBoolean, 67);
	registerField("f4892ap", "", Descriptor::Int32, 68);
	registerField("f4893aq", "", Descriptor::TypeString, 69);
	registerField("f4894ar", "", Descriptor::TypeString, 70);
	registerField("f4895as", "", Descriptor::TypeBoolean, 71);
	registerField("f4896at", "", Descriptor::TypeBoolean, 72);
	registerFieldForList("f4897au", "", Descriptor::TypeString, 73);
	registerField("f4898av", "", Descriptor::Int32, 74);
	registerField("f4899aw", "", Descriptor::Int32, 75);
	registerField("f4900ax", "", Descriptor::TypeBoolean, 76);




}


EnterVideoRoomInitInfo::~EnterVideoRoomInitInfo()
{
	//delete live_detail;
	//delete vote_info;
	//delete redenvelope_public;

	
	Reset();
}

void EnterVideoRoomInitInfo::Reset()
{
	for (size_t i = 0; i < vote_selects.size(); i++)
	{
		delete vote_selects[i];
	}
	vote_selects.clear();

	for (size_t i = 0; i < anchor_pk_rooms.size(); i++)
	{
		delete anchor_pk_rooms[i];
	}
	anchor_pk_rooms.clear();


	for (size_t i = 0; i < redenvelopes.size(); i++)
	{
		delete redenvelopes[i];
	}
	redenvelopes.clear();
	for (size_t i = 0; i < f4897au.size(); i++)
	{
		delete f4897au[i];
	}
	f4897au.clear();
	live_detail.Reset();
	vote_info.Reset();
}

void * EnterVideoRoomInitInfo::operator[](string name)
{
	if (name == "status") {
		return &this->status;
	}
	else if (name == "subject") {
		return &this->subject;
	}
	else if (name == "room_name") {
		return &this->room_name;
	}
	else if (name == "audience_count") {
		return &this->audience_count;
	}
	else if (name == "room_pic_info") {
		return &this->room_pic_info;
	}
	else if (name == "cur_giftpool_height") {
		return &this->cur_giftpool_height;
	}
	else if (name == "max_giftpool_height") {
		return &this->max_giftpool_height;
	}
	else if (name == "live_detail") {
		return &this->live_detail;
	}
	else if (name == "forbid_public_chat") {
		return &this->forbid_public_chat;
	}
	else if (name == "open_chat_cd_check") {
		return &this->open_chat_cd_check;
	}
	else if (name == "chat_cd_time") {
		return &this->chat_cd_time;
	}
	else if (name == "player_capacity") {
		return &this->player_capacity;
	}
	else if (name == "vote_info") {
		return &this->vote_info;
	}
	else if (name == "vote_selects") {
		return &this->vote_selects;
	}
	else if (name == "vip_level") {
		return &this->vip_level;
	}
	else if (name == "vip_expire") {
		return &this->vip_expire;
	}
	else if (name == "free_whistle_left") {
		return &this->free_whistle_left;
	}
	else if (name == "vip_notify") {
		return &this->vip_notify;
	}
	else if (name == "taken_vip_daily_reward_time") {
		return &this->taken_vip_daily_reward_time;
	}
	else if (name == "talent_show_state") {
		return &this->talent_show_state;
	}
	else if (name == "judge_type") {
		return &this->judge_type;
	}
	else if (name == "talent_show_id") {
		return &this->talent_show_id;
	}
	else if (name == "video_guild_id") {
		return &this->video_guild_id;
	}
	else if (name == "notify_vg_name") {
		return &this->notify_vg_name;
	}
	else if (name == "low_video_uploadspeed") {
		return &this->low_video_uploadspeed;
	}
	else if (name == "normal_video_uploadspeed") {
		return &this->normal_video_uploadspeed;
	}
	else if (name == "offline_become_member") {
		return &this->offline_become_member;
	}
	else if (name == "activity_type") {
		return &this->activity_type;
	}
	else if (name == "free_super_star_horn_left") {
		return &this->free_super_star_horn_left;
	}
	else if (name == "type") {
		return &this->type;
	}
	else if (name == "public_chat_cd_on_enter") {
		return &this->public_chat_cd_on_enter;
	}
	else if (name == "flags") {
		return &this->flags;
	}
	else if (name == "vg_sp_anchor") {
		return &this->vg_sp_anchor;
	}
	else if (name == "anchor_pk_rooms") {
		return &this->anchor_pk_rooms;
	}
	else if (name == "remain_crowdroom_count") {
		return &this->remain_crowdroom_count;
	}
	else if (name == "invisible") {
		return &this->invisible;
	}
	else if (name == "redenvelopes") {
		return &this->redenvelopes;
	}
	else if (name == "taken_vip_weekly_reward_time") {
		return &this->taken_vip_weekly_reward_time;
	}
	else if (name == "is_nest_room") {
		return &this->is_nest_room;
	}
	else if (name == "is_assistant") {
		return &this->is_assistant;
	}
	else if (name == "attached_room") {
		return &this->attached_room;
	}
	else if (name == "attached_anchor") {
		return &this->attached_anchor;
	}
	else if (name == "is_concert") {
		return &this->is_concert;
	}
	else if (name == "has_concert_ticket") {
		return &this->has_concert_ticket;
	}
	else if (name == "concert_is_open") { //45
		return &this->concert_is_open;
	}
	else if (name == "f4869T") { 
		return &this->f4869T;
	}
	else if (name == "f4870U") {
		return &this->f4870U;
	}
	else if (name == "attached_room_name") { //48
		return &this->attached_room_name;
	}
	else if (name == "is_closed_by_admin") {
		return &this->is_closed_by_admin;
	}
	else if (name == "redenvelope_public") {
		return &this->redenvelope_public;
	}
	else if (name == "free_times") {
		return &this->free_times;
	}
	else if (name == "seat_price_reset_notice") {
		return &this->seat_price_reset_notice;
	}
	else if (name == "can_punch_in_room") {
		return &this->can_punch_in_room;
	}
	else if (name == "room_skin_id") {
		return &this->room_skin_id;
	}
	else if (name == "room_skin_level") {
		return &this->room_skin_level;
	}
	else if (name == "video_definition") {
		return &this->video_definition;
	}
	else if (name == "free_barrage_left") {
		return &this->free_barrage_left;
	}
	else if (name == "room_close_player_count") {
		return &this->room_close_player_count;
	}
	else if (name == "edu_flag") {
		return &this->edu_flag;
	}
	else if (name == "f4884ah") {
		return &this->f4884ah;
	}
	else if (name == "f4885ai") {
		return &this->f4885ai;
	}
	else if (name == "f4886aj") {
		return &this->f4886aj;
	}
	else if (name == "f4887ak") {
		return &this->f4887ak;
	}
	else if (name == "f4888al") {
		return &this->f4888al;
	}
	else if (name == "f4889am") {
		return &this->f4889am;
	}
	else if (name == "f4890an") {
		return &this->f4890an;
	}
	else if (name == "f4891ao") {
		return &this->f4891ao;
	}
	else if (name == "f4892ap") {
		return &this->f4892ap;
	}
	else if (name == "f4893aq") {
		return &this->f4893aq;
	}
	else if (name == "f4894ar") {
		return &this->f4894ar;
	}
	else if (name == "f4895as") {
		return &this->f4895as;
	}
	else if (name == "f4896at") {
		return &this->f4896at;
	}
	else if (name == "f4897au") {
		return &this->f4897au;
	}
	else if (name == "f4898av") {
		return &this->f4898av;
	}
	else if (name == "f4899aw") {
		return &this->f4899aw;
	}
	else if (name == "f4900ax") {
		return &this->f4900ax;
	}


	return nullptr;
}

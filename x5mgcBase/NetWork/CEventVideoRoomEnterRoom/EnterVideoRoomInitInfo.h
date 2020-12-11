#pragma once
#include "../Utils.h"
#include "VideoRoomLiveStatusDetail.h"
#include "VideoVoteInfo.h"
#include "RedEnvelopeInfo.h"
#include "RedEnvelopePublicInfo.h"
class EnterVideoRoomInitInfo :public ProtoBufSerializable
{
public:
	EnterVideoRoomInitInfo();
	~EnterVideoRoomInitInfo();
	void Reset();
	virtual void * operator[](string name);
public:
	int status = 0;
	int subject = 0;
	std::string room_name;
	int audience_count = 0;
	int room_pic_info = 0;
	int cur_giftpool_height = 0;
	int max_giftpool_height = 0;
	VideoRoomLiveStatusDetail live_detail;	
	bool forbid_public_chat = 0;
	bool open_chat_cd_check = 0;
	int chat_cd_time = 0;
	int player_capacity = 0;
	VideoVoteInfo vote_info;
	std::vector<int*> vote_selects;
	int vip_level = 0;
	int vip_expire = 0;
	int free_whistle_left = 0;
	int vip_notify = 0;
	int taken_vip_daily_reward_time = 0;
	int talent_show_state = 0;
	int judge_type = 0;
	int talent_show_id = 0;
	int64_t video_guild_id = 0;
	std::string notify_vg_name;
	int low_video_uploadspeed = 0;
	int normal_video_uploadspeed = 0;
	bool offline_become_member = 0;
	int activity_type = 0;
	int free_super_star_horn_left = 0;
	int type = 0;
	int public_chat_cd_on_enter = 0;
	int flags = 0;
	int64_t vg_sp_anchor = 0;
	std::vector<int*> anchor_pk_rooms;
	int remain_crowdroom_count = 0;
	bool invisible = 0;
	std::vector<RedEnvelopeInfo*> redenvelopes;//房间内是否已发出红包
	int taken_vip_weekly_reward_time = 0;
	bool is_nest_room = false;//是否为小窝房间
	bool is_assistant = false;
	//int attached_room = 0;
	//int attached_anchor = 0;
	//bool is_concert = 0;
	//bool has_concert_ticket = false; //40
	int attached_room = 0;
	std::string attached_anchor;
	bool is_concert = false;
	bool has_concert_ticket = false;
	bool concert_is_open = false; //45

	std::string f4869T;
	int f4870U = 0;

	std::string attached_room_name; //48
	bool is_closed_by_admin = false;
	RedEnvelopePublicInfo redenvelope_public;
	int free_times = 0;
	int seat_price_reset_notice = 0;
	bool can_punch_in_room = false;
	int room_skin_id = 0;
	int room_skin_level = 0;
	int video_definition = 0;;// 视频清晰度
	int free_barrage_left = 0;//免费弹幕数量
	int room_close_player_count = 0;// 房间关闭时最后的在线人数
	int edu_flag = 0;





	bool f4884ah = false;
	bool f4885ai = false;
	bool f4886aj = false;
	std::string f4887ak;
	bool f4888al = false;
	bool f4889am = false;
	int f4890an = 0;
	bool f4891ao = 0;
	int f4892ap = 0;
	std::string f4893aq;
	std::string f4894ar;
	bool f4895as = false;
	bool f4896at = false;
	std::vector<std::string *> f4897au;
	int f4898av = 0;
	int f4899aw = 0;	bool f4900ax = false;

};


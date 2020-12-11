#pragma once
#include "../Utils.h"
#include <map>
class VideoHomePageRoomInfo :public ProtoBufSerializable
{
public:
	VideoHomePageRoomInfo();
	~VideoHomePageRoomInfo();
	virtual void * operator[](string name);
public:
	//std::vector<>

	int id = 0;
	int type = 0;
	int subject = 0;
	std::string room_name;
	int player_num = 0;
	//5
	int state = 0;
	int live_start_time = 0;
	int64_t anchor_pstid;
	std::string anchor_name;
	int room_attribute_flag = 0;
	//10
	int player_capcity = 0;
	int room_pic_info = 0;
	bool is_closed = false;
	bool is_nest = false;
	int attached_room_id = 0;
	//15
	std::string large_anchor_posing_url;
	std::string small_anchor_posing_url;
	bool is_anchor_pk_room  = false;//是否主播pk房间	 
	bool is_special_room =false;//是否官方活动房间
	int64_t nest_owner = 0;//小窝主人qq，这个用来拼摆拍图片（个人直播间，主播未正在直播）
	//20
	int nest_status = 0;//小窝的冻结状态
	int anchor_level = 0;//主播等级
	bool is_star_gift_champion = 0;
	int anchor_badge = 0;
	std::string qgame_anchor_posing_url ;
	//25
	int room_skin_level = 0;
	int room_skin_id = 0;
	bool is_test_room = false;
	std::string tag_name;   
	int week_star_grade = 0;
	//30
	int week_star_sub_level = 0;
	bool is_use_mobile_anchor_posing = false;
	bool vertical_live = false;
	//34
	bool is_in_nest_blacklist = 0;
	//35
	int anchor_device_type = 0;
	//36
	int f4206J = 0;
	//37
	bool f4207K = 0;
	//38
	std::map<std::string * , int *> f4208L;
	//39
	int f4209M = 0; 
	//40
	int f4210N = 0;
private:

};


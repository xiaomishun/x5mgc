#pragma once
#include "../Utils.h"

class CEventVideoRoomEnterRoom : public ProtoBufSerializable
{
public:
	CEventVideoRoomEnterRoom();
	~CEventVideoRoomEnterRoom();
	virtual void * operator[](string name);
public:
	int room_id = 0;
	string nick;
	int gender = 0;
	int level = 0;
	bool has_avatar = false;
	NetBuffer avatar;
	int source = 0;
	bool invisible = false;
	bool crowd_into = false;//9
	int room_temp = 0;
	int subject = -1; // 页签的类别 //11
	int tag = 0;// 自定义页签id
	int offset = 0;// 快速进房偏移量
	int module_type = 0;// 热门推荐房间模块类别， 0:无模块	1:推荐模块1	2:推荐模块2	3:演唱会模块
	int page_capacity = 0;// 每页多少条
	int room_list_pos = 0;//15 // 房间在总列表上的位置
	vector<int> room_index; //17
	string token;//18
};


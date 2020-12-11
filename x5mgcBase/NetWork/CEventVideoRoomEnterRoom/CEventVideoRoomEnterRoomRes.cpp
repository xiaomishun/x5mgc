#include "CEventVideoRoomEnterRoomRes.h"



CEventVideoRoomEnterRoomRes::CEventVideoRoomEnterRoomRes():ProtoBufSerializable(this)//,info(new EnterVideoRoomInitInfo)
{
	registerField("room_id", "", Descriptor::Int32, 1);
	registerField("result", "", Descriptor::Int32, 2);
	registerField("info", typeid(EnterVideoRoomInitInfo).name(), Descriptor::Compound, 3);
	registerField("cooldown", "", Descriptor::Int32, 3);
	//registerField("f11246d", "", Descriptor::TypeBoolean, 4);
	registerField("cooldown", "", Descriptor::Int32, 4);
	registerField("nest_count", "", Descriptor::Int32, 5);
	registerField("is_special_room", "", Descriptor::TypeBoolean, 6);
	registerField("is_nest_room", "", Descriptor::TypeBoolean, 7);
	registerField("subject", "", Descriptor::Int32, 8);// 页签的类别
	registerField("tag", "", Descriptor::Int32, 9);// 自定义页签id
	registerField("offset", "", Descriptor::Int32, 10);// 快速切房偏移量
	registerField("m_switch", "", Descriptor::TypeBoolean, 11);//ios开关
	registerField("title", "", Descriptor::TypeString, 12);
	registerField("description", "", Descriptor::TypeString, 13);
	registerField("close_description", "", Descriptor::TypeString, 14);
	registerField("left_bekicked_time", "", Descriptor::Int32, 15);// 被踢出房间后，剩余可以进入房间的时间
	registerField("h5_url_profix", "", Descriptor::TypeString, 16);//h5分享页面url固定部分
	registerField("pic_location", "", Descriptor::TypeString, 17);//房间内 贵族、守护、财富值的图标显示位置 如"1.2.3"
	registerField("concert_id", "", Descriptor::Int32, 18);// 演唱会ID（新增）

	registerField("f9608t", "", Descriptor::Int32, 19);
	registerField("f9609u", "", Descriptor::Int32, 20);
	registerField("f9610v", "", Descriptor::TypeString, 21);
	registerField("f9611w", "", Descriptor::Int32, 22);
	registerField("f9612x", "", Descriptor::Int32, 23);
	registerField("f9613y", "", Descriptor::Int32, 24);
	registerField("f9614z", "", Descriptor::Int32, 25);
	registerField("f9587A", "", Descriptor::Int32, 26);
	registerField("f9588B", "", Descriptor::Int32, 27);
	registerField("f9589C", "", Descriptor::Int32, 28);
	//int f9608t = 0;
	//int f9609u = 0;
	//std::string f9610v;
	//int f9611w = 0;
	//int f9612x = 0;
	//int f9613y = 0;
	//int f9614z = 0;
	//int f9587A = 0;
	//int f9588B = 0;
	//int f9589C = 0;

}


CEventVideoRoomEnterRoomRes::~CEventVideoRoomEnterRoomRes()
{
}

void CEventVideoRoomEnterRoomRes::Reset()
{
	//info.Reset();
}

void * CEventVideoRoomEnterRoomRes::operator[](string name)
{
	if (name == "room_id") {
		return &this->room_id;
	}
	else if (name == "result") {
		return &this->result;
	}
	else if (name == "info") {
		return &this->info;
	}
	else if (name == "cooldown") {
		return &this->cooldown;
	}
	else if (name == "nest_count") {
		return &this->nest_count;
	}
	else if (name == "is_special_room") {
		return &this->is_special_room;
	}
	else if (name == "is_nest_room") {
		return &this->is_nest_room;
	}
	else if (name == "subject") {
		return &this->subject;
	}
	else if (name == "tag") {
		return &this->tag;
	}
	else if (name == "offset") {
		return &this->offset;
	}
	else if (name == "m_switch") {
		return &this->m_switch;
	}
	else if (name == "title") {
		return &this->title;
	}
	else if (name == "description") {
		return &this->description;
	}
	else if (name == "close_description") {
		return &this->close_description;
	}
	else if (name == "left_bekicked_time") {
		return &this->left_bekicked_time;
	}
	else if (name == "h5_url_profix") {
		return &this->h5_url_profix;
	}
	else if (name == "pic_location") {
		return &this->pic_location;
	}
	else if (name == "concert_id") {
		return &this->concert_id;
	}
	else if (name == "f9608t") {
		return &this->f9608t;
	}
	else if (name == "f9609u") {
		return &this->f9609u;
	}
	else if (name == "f9610v") {
		return &this->f9610v;
	}
	else if (name == "f9611w") {
		return &this->f9611w;
	}
	else if (name == "f9612x") {
		return &this->f9612x;
	}
	else if (name == "f9613y") {
		return &this->f9613y;
	}
	else if (name == "f9614z") {
		return &this->f9614z;
	}
	else if (name == "f9587A") {
		return &this->f9587A;
	}
	else if (name == "f9588B") {
		return &this->f9588B;
	}
	else if (name == "f9589C") {
		return &this->f9589C;
	}
	return nullptr;
}

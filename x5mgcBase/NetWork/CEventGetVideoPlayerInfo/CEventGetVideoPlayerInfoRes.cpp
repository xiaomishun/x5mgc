#include "CEventGetVideoPlayerInfoRes.h"

CEventGetVideoPlayerInfoRes::CEventGetVideoPlayerInfoRes():ProtoBufSerializable(this)
{
	registerField("char_info", typeid(VideoCharInfo).name(), Descriptor::Compound, 1);
	registerFieldForList("followed_anchors", "", Descriptor::Int32, 2);
	registerField("succ", "", Descriptor::TypeBoolean, 3);
	registerField("transid", "", Descriptor::Int64, 4);
}

CEventGetVideoPlayerInfoRes::~CEventGetVideoPlayerInfoRes()
{

}

void CEventGetVideoPlayerInfoRes::Reset()
{
	for (size_t i = 0; i < followed_anchors.size(); i++)
	{
		delete followed_anchors[i];
	}
	followed_anchors.clear();
}

void * CEventGetVideoPlayerInfoRes::operator[](string name)
{
	if (name == "char_info") {
		return &char_info;
	}
	else if (name == "followed_anchors") {
		return &followed_anchors;
	}
	else if (name == "succ") {
		return &succ;
	}
	else if (name == "transid") {
		return &transid;
	}
	return nullptr;
}

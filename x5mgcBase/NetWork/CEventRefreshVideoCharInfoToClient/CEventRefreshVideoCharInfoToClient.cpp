#include "CEventRefreshVideoCharInfoToClient.h"

CEventRefreshVideoCharInfoToClient::CEventRefreshVideoCharInfoToClient():ProtoBufSerializable(this)
{
	registerField("info", typeid(VideoCharInfo).name(), Descriptor::Compound, 1);
}

CEventRefreshVideoCharInfoToClient::~CEventRefreshVideoCharInfoToClient()
{

}

void * CEventRefreshVideoCharInfoToClient::operator[](string name)
{
	if (name == "info") {
		return &info;
	}
	return nullptr;
}

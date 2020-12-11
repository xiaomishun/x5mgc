#pragma once
#include "GlobalClass.h"


extern ProtoBufSerializable * GetDefinitionByname(std::string &name)
{

	if (name == typeid(RoomProxyInfo).name()) {
		return new RoomProxyInfo();
	}
	else if (name == typeid(UserIdentity).name())
	{
		return new UserIdentity();
	}
	else if (name == typeid(RoomProxyAddress).name())
	{
		return new RoomProxyAddress();
	}
	else if (name == typeid(VideoActivityInfoToClient).name())
	{
		return new VideoActivityInfoToClient();
	}
	else if (name == typeid(CReward).name())
	{
		return new CReward();
	}
	else if (name == typeid(ProgressToClient).name())
	{
		return new ProgressToClient();
	}
	else if (name == typeid(RoomListInfo).name())
	{
		return new RoomListInfo();
	}
	else if (name == typeid(CEventGetVideoRoomTagInfosRes).name())
	{
		return new CEventGetVideoRoomTagInfosRes();
	}
	else if (name == typeid(CEventVideoRoomInfo).name())
	{
		return new CEventVideoRoomInfo();
	}
	else if (name == typeid(VideoHomePageRoomInfo).name())
	{
		return new VideoHomePageRoomInfo();
	}
	else if (name == typeid(CEventQueryVideoAccountInfo).name())
	{
		return new CEventQueryVideoAccountInfo();
	}
	else if (name == typeid(EnterVideoRoomInitInfo).name())
	{
		return new EnterVideoRoomInitInfo();
	}
	else if (name == typeid(AnchorImpressionDataServer).name())
	{
		return new AnchorImpressionDataServer();
	}
	else if (name == typeid(AnchorImpressionData).name())
	{
		return new AnchorImpressionData();
	}
	else if (name == typeid(VideoRoomLiveStatusDetail).name()) {
		return new VideoRoomLiveStatusDetail();
	}
	else if (name == typeid(SplitScreenInfo).name()) {
		return new SplitScreenInfo();
	}
	else if (name == typeid(VideoResolution).name()) {
		return new VideoResolution();
	}
	else if (name == typeid(VideoVoteEntry).name()) {
		return new VideoVoteEntry();
	}
	else if (name == typeid(VideoVoteInfo).name()) {
		return new VideoVoteInfo();
	}
	else if (name == typeid(RedEnvelopeInfo).name()) {
		return new RedEnvelopeInfo();
	}
	return nullptr;
}
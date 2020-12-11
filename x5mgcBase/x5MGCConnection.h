#pragma once
#include "bSocket.h"
#include "SocketCompose.h"
#include <map>
#include "NetWork/GlobalClass.h"
#include "NetWork/GlobalDefine.h"
#include "EasyWsClient.h"
#include <shared_mutex>
#define GAME_HOST "101.227.160.124"
#define GAME_PORT 31000

typedef int(*Netcallback)(ProtoBufSerializable * p, void * argv);
#define nPointer_Initialization()  \
		auto * pThis = (x5MGCConnection *)argv;
struct IMessage
{
	Netcallback callback;
	ProtoBufSerializable * protoBuf;
	void * argv;
};
struct Packet_01
{
	char sha256[32];
	char Decrypt[8];
};
class x5MGCConnection : public bSocket,SocketCompose
{
public:
	x5MGCConnection();
	x5MGCConnection(update_user *user, std::vector<int> * roomlist, int room);
	~x5MGCConnection();
	void run(easywsclient::WebSocket::pointer &ws, std::shared_timed_mutex &mutex);
	virtual void Receipt(int Mod, int Error);
	virtual bool SendTo(const char  FAR * buf, _In_ int len, bool nFlags = true);
	virtual int hBuffer(SOCKET s, char * Buffer, uint32_t Size);
	virtual int complete_hBuffer(FD_INFO * arg, const char * pBuffer, size_t Size);
	virtual void AddMessage(int clsid, Netcallback callback, ProtoBufSerializable * protoBuf, void * argv);
//websocket消息发送
	virtual void wsSend(std::string &message);
// 主要功能回调实现;
	bool handlePacket(NetBuffer * _read_buffer);
// 心跳功能回调实现;
	virtual void handleSpare();
//发送protobuf数据
	int Send_message(ProtoBufSerializable * IMessage, int clsid);
	bool RoomProxyWrapEvent(int clsid, ProtoBufSerializable *msg = 0);
	int GetSerialID();
// 注册回调
	void regsiterPlugin();

// 外部设置时间
	void setCurrentTime(int time);
	void setState(int state);
	int getState();
// 发送当前当前账号状态;
	void setUserStateInfo(std::string s,int stateCode = 0);
private:
// 派发回调
	static int onHandle_initialize(ProtoBufSerializable * p, void * argv);
	static int onHandle_initializeUser(ProtoBufSerializable * p, void * argv);
	static int onHandle_initializeLogin(ProtoBufSerializable * p, void * argv);
	static int onHandle_VideoAccountInfoRes(ProtoBufSerializable *p, void *argv);
	static int onHandle_VideoInitConnectionRes(ProtoBufSerializable *p, void *argv);
	static int onHanlde_RoomProxyWrapEvent(ProtoBufSerializable *p, void *argv);
	static int onHandle_GetPlayerBasicCardInfoRes(ProtoBufSerializable *p, void *argv);
	static int onHanlde_CEventGetVideoPlayerInfoRes(ProtoBufSerializable *p, void *argv);
	static int onHanlde_RefreshVideoCharInfoToClient(ProtoBufSerializable *p, void *argv);
	static int onHandle_GetActivityCenterInfosRes(ProtoBufSerializable *p, void *argv);
	static int onHandle_GetSigninRewardNotifyRes(ProtoBufSerializable *p, void *argv);
	static int onHandle_GetVideoHistoryInfoRes(ProtoBufSerializable *p, void *argv);
	static int onHandle_GetVideoMainInfosRes(ProtoBufSerializable *p, void *argv);
	static int onHandle_CEventVideoRoomEnterRoomRes(ProtoBufSerializable *p, void *argv);
	static int onHandle_VideoSendGiftResult(ProtoBufSerializable *p, void *argv);
	static int onHandle_VideoSurpriseBoxEventIDStart(ProtoBufSerializable *p, void *argv);
	static int onHandle_VideoToClientChatMessage(ProtoBufSerializable *p, void *argv);
	static int onHandle_CEventIgnoreFreeGiftRes(ProtoBufSerializable *p, void *argv);
	static int onHandle_CEventVideoPlayerHeartBeatNotify(ProtoBufSerializable *p, void *argv);
private:
	FD_INFO pInfo;
	std::map<int, IMessage> arrMessage;
	ProtoBufSerializable * nInitialize;
private:
	//用户账号信息
	UINT m_QQUser = 0; //2992369448;
	std::string m_szQQUser;
	std::string m_skey; //= "34397AA3549AE6FD847F6470FD0DDDA5";
	std::string m_open_id; //= "FE8F2B766F049D3620145D7D998DC846";
	std::string m_mobile_version = "1.3.7";
	UINT m_zone_id = 0;//132; //上号大区
	std::string m_androidMD5; //= "4992204900e8f5818264bf3b5a7f3621";
	std::string m_mac_id;
	//int64_t m_mac_id;
	int m_serialID = 0;
	int EnterRoomID = 191;
	int state = 0; // 0正在上号 1当前在房间 2更新登录 -1 上号失败 -2 线程已经退出 -3密码错误
	int last_time = 0;
	easywsclient::WebSocket::pointer ws;
	std::shared_timed_mutex *mutex;
	std::vector<int> * roomlist;
private:
	CEventQueryVideoAccountInfoRes * AccountInfoRes = nullptr;
	CEventVideoInitConnectionResponse * InitConnectionRes = nullptr;
	CEventRoomProxyWrapEvent * RoomProxyWrap = nullptr;
	CEventGetPlayerBasicCardInfoRes * PlayerBasicCardInfoRes = nullptr;
	CEventGetActivityCenterInfosRes * ActivityCenterInfos = nullptr;
	CEventGetSigninRewardNotifyRes * SigninRewardNotify = nullptr;
	CEventGetVideoHistoryInfosRes * VideoHistoryInfo = nullptr;
	CEventGetVideoMainInfosRes * VideoMainInfos = nullptr;
	CEventVideoRoomEnterRoomRes * VideoRoomEnterRoomRes = nullptr;
	CEventVideoSendGiftResult * VideoSendGiftResult = nullptr;
	CEventUpdateSurpriseBoxStatus * VideoSurpriseBoxEventIDStart = nullptr;
	CEventRefreshVideoCharInfoToClient * videoCharInfo = nullptr;
	CEventGetVideoPlayerInfoRes * VideoPlayerInfoRes = nullptr;
	CEventVideoToClientChatMessage * VideoToClientChatMessageRes = nullptr;
	CEventIgnoreFreeGiftRes * IgnoreFreeGiftRes = nullptr;
	CEventVideoPlayerHeartBeatNotify * VideoPlayerHeartBeatNotify = nullptr;
};


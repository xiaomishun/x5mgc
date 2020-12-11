#include "pch.h"
#include "x5MGCConnection.h"
#include "sha256.h"
#include "brains.h"
#include <iostream>
#include "MyRSA.h"
#include "MyBASE64.h"
#include <time.h>
#include <plog/Log.h>
#include "nlohmann/json.hpp"
#include "hCode.h"
#include <psapi.h>
using json = nlohmann::json;
x5MGCConnection::x5MGCConnection()
{

}

x5MGCConnection::x5MGCConnection(update_user *user, std::vector<int> * roomlist,int room)
{
	this->roomlist = roomlist;
	this->EnterRoomID = room;
	m_QQUser = user->user;
	m_skey = user->msky;
	m_open_id = user->open_id;
	m_androidMD5 = user->androidMd5;
	m_zone_id = user->zone_id;
	m_mobile_version = user->mobile_version;
	m_mac_id = user->mac_id;
}


x5MGCConnection::~x5MGCConnection()
{
	delete AccountInfoRes;
	delete InitConnectionRes;
	delete RoomProxyWrap;
	delete PlayerBasicCardInfoRes;
	delete ActivityCenterInfos;
	delete SigninRewardNotify;
	delete VideoHistoryInfo;
	delete VideoMainInfos;
	delete VideoRoomEnterRoomRes;
	delete VideoSendGiftResult;
	delete VideoSurpriseBoxEventIDStart;
	delete videoCharInfo;
	delete VideoPlayerInfoRes;
	delete VideoToClientChatMessageRes;
	delete IgnoreFreeGiftRes;
	delete VideoPlayerHeartBeatNotify;
}

void x5MGCConnection::run(easywsclient::WebSocket::pointer &ws,std::shared_timed_mutex &mutex)
{
	this->ws = ws;
	this->mutex = &mutex;
	//wsSend(std::string("开始登录了"));
	setUserStateInfo("收到账号信息开始登录账号.");
	setState(0);
	//开始->
	connectTo(GAME_HOST, GAME_PORT);
	RecvReplace();
	std::cout << "结束时间:" << time(NULL) - start_time << std::endl;
	LOG_INFO << "结束时间:" << time(NULL) - start_time << std::endl;
	//重上 发用户ID过去?

	int state = getState();
	if (state == -2) 
	{
		json obj;
		obj["code"] = 200;
		obj["msg"] = 102;//账号掉线了;发给服务器重连接
		obj["mac_id"] = m_mac_id;
		std::string send_str = obj.dump();
		wsSend(send_str);
	}


	//wsSend()
	//int state = getState();
	//while (state == 2)
	//{
	//	//Sleep(3000);
	//	connectTo(GAME_HOST, GAME_PORT);
	//	RecvReplace();
	//	state = getState();
	//	std::cout << "结束1111111111111" << std::endl;
	//}
	//结束->
}

void x5MGCConnection::Receipt(int Mod, int Error)
{
	//int i = 0;
	//i++;
	if (Mod == BSOCKET_SUCESS)  // Socket连接成功
	{
		setState(0);
		this->regsiterPlugin();
		int start_buf[5] = { 9,0 };
		SendTo((const char *)start_buf, sizeof(start_buf));
	}
	else
	{
		if(getState() != -3) setState(-2);
		
	}
}

bool x5MGCConnection::SendTo(const char * buf, int len, bool nFlags)
{
	if (nFlags) 
	{
		//119
		int buffer[2] = { len, 0 };
		this->Send((const char *)buffer, sizeof(buffer));
		this->Send(buf, len);
	}
	else
	{
		this->Send(buf, len);
	}
	return false;
}

int x5MGCConnection::hBuffer(SOCKET s, char * Buffer, uint32_t Size)
{
	this->handleSpare();
	return split_hBuffer(&pInfo,Buffer, Size);
}

int x5MGCConnection::complete_hBuffer(FD_INFO * arg, const char * pBuffer, size_t Size)
{
	//分包处理过后的包;
	NetBuffer recvPacket(pBuffer + sizeof(MSGCOMMON), Size - sizeof(MSGCOMMON));
	this->handlePacket(&recvPacket);
	return 0;
}

void x5MGCConnection::AddMessage(int clsid, Netcallback callback, ProtoBufSerializable * protoBuf, void * argv)
{
	arrMessage[clsid] = { callback ,protoBuf ,argv };
}

void x5MGCConnection::wsSend(std::string & message)
{
	std::lock_guard<std::shared_timed_mutex> sbguard(*mutex);
	ws->send(message);
	//ws->poll();
	//mutex->unlock();
}

bool x5MGCConnection::handlePacket(NetBuffer * _read_buffer)
{
	int clsid = _read_buffer->getInt();
	IMessage  message = arrMessage[clsid];
	std::cout << std::to_string(clsid) << std::endl;
	//39783 进入房间解析
	if(message.callback) 
	{
		LOG_INFO << "QQ号:" << m_QQUser << "" << "clsid:" << clsid;
		//wsSend(std::to_string(clsid));
		if (message.protoBuf == nullptr) {
			message.callback((ProtoBufSerializable *)_read_buffer, message.argv);
		}
		else
		{
			ProtoBufSerializer::FromStream(message.protoBuf, _read_buffer);
			message.callback(message.protoBuf, message.argv);
		}
	}
	else
	{
		return false;
	}
	return true;
}

void x5MGCConnection::handleSpare()
{
	//int i = 0;
	//i++;
	Sleep(100);
	int state = getState();



	if (state == 1)
	{
		//int temp_time = time(NULL);
		//if (temp_time > last_time + 5)
		//{
		//	last_time = temp_time;
		//	CEventVideoPlayerHeartBeatNotify PlayerHeartBeatNotify;
		//	RoomProxyWrapEvent(CLSID_CEventVideoPlayerHeartBeatNotify, &PlayerHeartBeatNotify);
		//}
	}
	else if(state == 2)
	{
		// close();
	}
	//当前号已经不在列表了
	mutex->lock();
	//std::lock_guard<std::shared_timed_mutex> sbguard(*mutex);
	for (size_t i = 0; i < roomlist->size(); i++)
	{
		if (roomlist->at(i) == EnterRoomID)
		{
			mutex->unlock();
			return;
		}
	}
	mutex->unlock();
	close();

	//mutex->unlock();

}

int x5MGCConnection::Send_message(ProtoBufSerializable * IMessage, int clsid)
{


	NetBuffer * buffer = new NetBuffer();
	buffer->putInt(clsid);  // CLSID 发送事件ID
	ProtoBufSerializer::ToStream(IMessage, buffer);
	SendTo(buffer->buffer(), buffer->length());
	delete buffer;

	//Sleep(500);
	return 0;
}

bool x5MGCConnection::RoomProxyWrapEvent(int clsid, ProtoBufSerializable * msg)
{
	CEventRoomProxyWrapEvent RoomProxyWrap;
	RoomProxyWrap.serialID = this->GetSerialID();
	RoomProxyWrap.uid.account = this->m_QQUser;
	RoomProxyWrap.uid.zoneid = this->m_zone_id;
	RoomProxyWrap.clsid = clsid;//CLSID_CEventVideoReconnectVerifyRequest;//CLSID_CEventVideoReconnectVerifyRequest;//62199
	RoomProxyWrap.payload.putInt(RoomProxyWrap.clsid);
	ProtoBufSerializable send_msg(msg);
	auto saveDescriptors = send_msg.fieldDescriptors;
	if (msg)
	{
		send_msg.fieldDescriptors = msg->fieldDescriptors;
	}
	ProtoBufSerializer::ToStream(&send_msg, &RoomProxyWrap.payload);
	send_msg.fieldDescriptors = saveDescriptors;
	int result = Send_message(&RoomProxyWrap, CLSID_CEventRoomProxyWrapEvent);
	return result;
}

int x5MGCConnection::GetSerialID()
{
	return m_serialID++;
}

void x5MGCConnection::regsiterPlugin()
{
	AddMessage(1, &onHandle_initialize, nullptr,this);
	AddMessage(3, &onHandle_initializeUser, nullptr, this);
	AddMessage(7, &onHandle_initializeLogin, nullptr, this);
	if(!AccountInfoRes)AccountInfoRes = new CEventQueryVideoAccountInfoRes();
	else AccountInfoRes->Reset();
	//// 07 登录过后返回验证包
	AddMessage(CLSID_CEventQueryVideoAccountInfoRes, onHandle_VideoAccountInfoRes, AccountInfoRes, this);
	if(!InitConnectionRes) InitConnectionRes = new CEventVideoInitConnectionResponse();
	AddMessage(CLSID_CEventVideoInitConnectionResponse, onHandle_VideoInitConnectionRes, InitConnectionRes, this);

	if (!RoomProxyWrap) RoomProxyWrap = new CEventRoomProxyWrapEvent();
	//else RoomProxyWrap->~CEventRoomProxyWrapEvent();
	AddMessage(CLSID_CEventRoomProxyWrapEvent, onHanlde_RoomProxyWrapEvent, RoomProxyWrap, this);
	// 獲取用戶信息回調
	if (!PlayerBasicCardInfoRes) PlayerBasicCardInfoRes = new CEventGetPlayerBasicCardInfoRes();
	//////else PlayerBasicCardInfoRes->~CEventGetPlayerBasicCardInfoRes();
	AddMessage(CLSID_CEventGetPlayerBasicCardInfoRes, onHandle_GetPlayerBasicCardInfoRes, PlayerBasicCardInfoRes, this);
	////// 獲取用戶信息回調
	if(!videoCharInfo) videoCharInfo = new CEventRefreshVideoCharInfoToClient();
	//////else videoCharInfo->~CEventRefreshVideoCharInfoToClient();
	AddMessage(CLSID_CEventRefreshVideoCharInfoToClient, onHanlde_RefreshVideoCharInfoToClient, videoCharInfo, this);

	////任務回調

	if(!VideoPlayerInfoRes) VideoPlayerInfoRes =  new CEventGetVideoPlayerInfoRes();
	else VideoPlayerInfoRes->Reset();
	AddMessage(CLSID_CEventGetVideoPlayerInfoRes, onHanlde_CEventGetVideoPlayerInfoRes, VideoPlayerInfoRes, this);

	if(!ActivityCenterInfos) ActivityCenterInfos = new CEventGetActivityCenterInfosRes();
	else ActivityCenterInfos->Reset();
	AddMessage(CLSID_CEventGetActivityCenterInfosRes, onHandle_GetActivityCenterInfosRes, ActivityCenterInfos, this);

	if(!SigninRewardNotify) SigninRewardNotify = new CEventGetSigninRewardNotifyRes();
	//else SigninRewardNotify->~CEventGetSigninRewardNotifyRes();
	AddMessage(CLSID_CEventGetSigninRewardNotifyRes, onHandle_GetSigninRewardNotifyRes, SigninRewardNotify, this);
	if(!VideoHistoryInfo ) VideoHistoryInfo =  new CEventGetVideoHistoryInfosRes();
	else VideoHistoryInfo->Reset();
	AddMessage(CLSID_CEventGetVideoHistoryInfoRes, onHandle_GetVideoHistoryInfoRes, VideoHistoryInfo, this);
	if(!VideoMainInfos) VideoMainInfos = new CEventGetVideoMainInfosRes();
	else VideoMainInfos->Reset();
	AddMessage(CLSID_CEventGetVideoMainInfosRes, onHandle_GetVideoMainInfosRes, VideoMainInfos, this);

	if(!VideoRoomEnterRoomRes) VideoRoomEnterRoomRes = new CEventVideoRoomEnterRoomRes();
	else VideoRoomEnterRoomRes->Reset();
	AddMessage(CLSID_CEventVideoRoomEnterRoomRes, onHandle_CEventVideoRoomEnterRoomRes , VideoRoomEnterRoomRes, this);


	if(!VideoSendGiftResult) VideoSendGiftResult = new CEventVideoSendGiftResult();
	//else VideoSendGiftResult->~CEventVideoSendGiftResult();
	AddMessage(CLSID_CEventVideoSendGiftResult, onHandle_VideoSendGiftResult, VideoSendGiftResult, this);

	if(!VideoSurpriseBoxEventIDStart) VideoSurpriseBoxEventIDStart = new CEventUpdateSurpriseBoxStatus();
	//else VideoSurpriseBoxEventIDStart->~CEventUpdateSurpriseBoxStatus();
	AddMessage(CLSID_VideoSurpriseBoxEventIDStart, onHandle_VideoSurpriseBoxEventIDStart, VideoSurpriseBoxEventIDStart,this);


	if(!VideoToClientChatMessageRes) VideoToClientChatMessageRes =  new CEventVideoToClientChatMessage();
	//else VideoToClientChatMessageRes->~CEventVideoToClientChatMessage();
	AddMessage(CLSID_CEventVideoToClientChatMessage, onHandle_VideoToClientChatMessage, VideoToClientChatMessageRes, this);

	if(!IgnoreFreeGiftRes)IgnoreFreeGiftRes = new CEventIgnoreFreeGiftRes();
	//else IgnoreFreeGiftRes->~CEventIgnoreFreeGiftRes();
	AddMessage(CLSID_CEventIgnoreFreeGiftRes, onHandle_CEventIgnoreFreeGiftRes, IgnoreFreeGiftRes, this);

	if(!VideoPlayerHeartBeatNotify)VideoPlayerHeartBeatNotify =  new CEventVideoPlayerHeartBeatNotify();
	//else VideoPlayerHeartBeatNotify->~CEventVideoPlayerHeartBeatNotify();
	AddMessage(CLSID_CEventVideoPlayerHeartBeatNotify, onHandle_CEventVideoPlayerHeartBeatNotify,VideoPlayerHeartBeatNotify, this);

}

void x5MGCConnection::setCurrentTime(int time)
{
	this->last_time = time;
}

void x5MGCConnection::setState(int state)
{
	std::lock_guard<std::shared_timed_mutex> sbguard(*mutex);
	this->state = state;
}

int x5MGCConnection::getState()
{
	std::lock_guard<std::shared_timed_mutex> sbguard(*mutex);
	return this->state;
}

void x5MGCConnection::setUserStateInfo(std::string msg, int stateCode)
{
	auto send_remark = AsciiToUtf8(msg);
	json sobj;
	sobj["code"] = 200;
	sobj["msg"] = 104;
	sobj["mac_id"] = m_mac_id;
	sobj["state"] = stateCode;
	sobj["remark"] = send_remark;
	auto send_msg = sobj.dump();
	wsSend(send_msg);
}

int x5MGCConnection::onHandle_initialize(ProtoBufSerializable * p, void * argv)
{
	nPointer_Initialization();
	NetBuffer * recvBuf = (NetBuffer *)p;
	const char * shabuf = recvBuf->buffer();
	Packet_01 * shaPacket = (Packet_01*)(shabuf + 4);
	int * pDec = (int *)shaPacket->Decrypt;
	auto seviceSha256 = shaPacket->sha256;
	for (size_t i = 0; i < 0x10000; i++)
	{
		hash_state hash;
		sha256_init(&hash);
		sha256_process(&hash, (const unsigned char *)pDec, 8);
		unsigned char outByte[32] = { 0x0 };
		sha256_done(&hash, outByte);
		if (memcmp(seviceSha256, outByte, 32) == 0)
		{
			//算出服务器需要的has值
			int send_02[] = { 0x2,pDec[0],pDec[1] };
			pThis->SendTo((const char *)send_02, sizeof(send_02));
			break;
		}
		++*pDec;
	}
	
	int i = 0;
	return 0;
}

int x5MGCConnection::onHandle_initializeUser(ProtoBufSerializable * p, void * argv)
{
	nPointer_Initialization();
	NetBuffer * recvBuf = (NetBuffer *)p;
	pThis->m_szQQUser = std::to_string(pThis->m_QQUser);
	int Packet_05_header[2] = { 5,pThis->m_szQQUser.size() }; //0A密码长度
	brains<char> buffer((char *)Packet_05_header, 8);
	buffer += brains<char>(pThis->m_szQQUser.data(), Packet_05_header[1] + 1);
	int _buffer[2] = { buffer.getLength(),0 };
	pThis->Send((const char *)_buffer, 8);
	unsigned int Buffer2[6] = { 0x32c,0,0x6,0xc8,0x0, pThis->m_QQUser};
	buffer += brains<char>((char*)Buffer2, sizeof(Buffer2));
	char zerofill[796] = { 0x0 };
	buffer += brains<char>(zerofill, sizeof(zerofill));
	pThis->Send(buffer.getBuffer(),buffer.getSize());
	return 0;
}

int x5MGCConnection::onHandle_initializeLogin(ProtoBufSerializable * p, void * argv)
{
	nPointer_Initialization();
	CEventQueryVideoAccountInfo AccountInfo;
	AccountInfo.m_skey = pThis->m_skey;
	AccountInfo.m_open_id = pThis->m_open_id;
	pThis->Send_message(&AccountInfo, CLSID_CEventQueryVideoAccountInfo);
	return 0;
}

int x5MGCConnection::onHandle_VideoAccountInfoRes(ProtoBufSerializable * p, void * argv)
{
	nPointer_Initialization();
	auto VideoAccountInfoRes = (CEventQueryVideoAccountInfoRes *)p;
	CEventVideoInitConnectionRequest InitConnecionReq; //登录包
	InitConnecionReq.uid.account = pThis->m_QQUser;
	InitConnecionReq.uid.channel = 0;
	InitConnecionReq.uid.zoneid = pThis->m_zone_id;
	InitConnecionReq.skey = pThis->m_skey;
	InitConnecionReq.m_open_id = pThis->m_open_id;
	InitConnecionReq.mobile_version = pThis->m_mobile_version;
	InitConnecionReq.logic_version = 28;
	InitConnecionReq.android_md5 = pThis->m_androidMD5;// "4992204900e8f5818264bf3b5a7f362a";
	InitConnecionReq.roomID = 0;
	InitConnecionReq.trans_id = 0;
	InitConnecionReq.client_device_type = 1;
	InitConnecionReq.appid = 1105583531;
	pThis->Send_message(&InitConnecionReq, CLSID_CEventVideoInitConnectionRequest);
	return 0;
}

int x5MGCConnection::onHandle_VideoInitConnectionRes(ProtoBufSerializable * p, void * argv)
{
	nPointer_Initialization();
	auto InitConnectionRes = (CEventVideoInitConnectionResponse *)p;


	CEventGetVideoPlayerInfo playerInfo;
	playerInfo.transid = InitConnectionRes->trans_id;
	pThis->RoomProxyWrapEvent(CLSID_CEventGetVideoPlayerInfo, &playerInfo); //获取任务信息

	return 0;
}

int x5MGCConnection::onHanlde_RoomProxyWrapEvent(ProtoBufSerializable * p, void * argv)
{
	nPointer_Initialization();
	auto RoomProxyWrapEvent = (CEventRoomProxyWrapEvent *)p;
	pThis->handlePacket(&RoomProxyWrapEvent->payload);
	return 0;
}

int x5MGCConnection::onHandle_GetPlayerBasicCardInfoRes(ProtoBufSerializable * p, void * argv)
{
	nPointer_Initialization();
	auto PlayerBasicCardInfoRes = (CEventGetPlayerBasicCardInfoRes *)p;
	pThis->RoomProxyWrapEvent(CLSID_CEventGetActivityCenterInfos);
	return 0;
}

int x5MGCConnection::onHanlde_CEventGetVideoPlayerInfoRes(ProtoBufSerializable * p, void * argv)
{
	nPointer_Initialization();
	auto VideoPlayerInfoRes = (CEventGetVideoPlayerInfoRes *)p;
	CEventGetPlayerBasicCardInfo playerBasicInfo;
	playerBasicInfo.player_id = pThis->VideoPlayerInfoRes->char_info.pstid;
	pThis->RoomProxyWrapEvent(CLSID_CEventGetPlayerBasicCardInfo, &playerBasicInfo);
	return 0;
}

int x5MGCConnection::onHanlde_RefreshVideoCharInfoToClient(ProtoBufSerializable * p, void * argv)
{
	auto videoCharInfo = (CEventRefreshVideoCharInfoToClient *)p;

	return 0;
}

int x5MGCConnection::onHandle_GetActivityCenterInfosRes(ProtoBufSerializable * p, void * argv)
{
	nPointer_Initialization();
	auto ActivityCenterInfosRes = (CEventGetActivityCenterInfosRes *)p;
	pThis->RoomProxyWrapEvent(CLSID_CEventGetSigninRewardNotify);
	return 0;
}

int x5MGCConnection::onHandle_GetSigninRewardNotifyRes(ProtoBufSerializable * p, void * argv)
{
	nPointer_Initialization();
	auto SigninRewardNotifyRes = (CEventGetSigninRewardNotifyRes *)p;
	pThis->RoomProxyWrapEvent(CLSID_CEventGetVideoHistoryInfo);
	return 0;
}

int x5MGCConnection::onHandle_GetVideoHistoryInfoRes(ProtoBufSerializable * p, void * argv)
{
	nPointer_Initialization();
	auto VideoHistoryInfoRes = (CEventGetVideoHistoryInfosRes *)p;
	CEventGetVideoMainInfos VideoMainInfo;
	pThis->RoomProxyWrapEvent(CLSID_CEventGetVideoMainInfos, &VideoMainInfo); //获取主页列表
	return 0;
}

int x5MGCConnection::onHandle_GetVideoMainInfosRes(ProtoBufSerializable * p, void * argv)
{
	nPointer_Initialization();
	//return 0;
	auto videoMainInfosRes = (CEventGetVideoMainInfosRes *)p;
	CEventVideoRoomEnterRoom videoRoomEnter;
	videoRoomEnter.room_id = pThis->EnterRoomID; //进房房间号
	videoRoomEnter.nick = pThis->PlayerBasicCardInfoRes->player_basic_card_info.player_name; //我的昵称
	videoRoomEnter.gender = pThis->PlayerBasicCardInfoRes->player_basic_card_info.player_sex;//pThis->videoCharInfo->info.gender;//性别
	videoRoomEnter.level = pThis->PlayerBasicCardInfoRes->player_basic_card_info.player_level;
	videoRoomEnter.source = 14;
	videoRoomEnter.page_capacity = 20;
	std::string strData = std::to_string(pThis->EnterRoomID);
	strData += std::string("#mgc%(joke)#");
	strData += std::to_string(pThis->PlayerBasicCardInfoRes->player_basic_card_info.player_sex);
	strData += std::string("#");
	strData += std::to_string(pThis->PlayerBasicCardInfoRes->player_basic_card_info.player_level);
	int len = 0;
	std::string out = MyRSA::encryptRSAbyPublickey(strData, &len);
	std::string base64code = MyBASE64::base64_encodestring(out);
	int findPos = 0;
	do
	{
		findPos = base64code.find('\xA');
		if (findPos <= 0) break;
		base64code.erase(findPos, 1);
	} while (findPos > 0);
	videoRoomEnter.token = base64code;
	 pThis->RoomProxyWrapEvent(CLSID_CEventVideoRoomEnterRoom, &videoRoomEnter);
	return 0;
}

int x5MGCConnection::onHandle_CEventVideoRoomEnterRoomRes(ProtoBufSerializable * p, void * argv)
{
	nPointer_Initialization();
	auto videoRoomEnterRoomRes = (CEventVideoRoomEnterRoomRes *)p;
	//int roomid = videoRoomEnterRoomRes->room_id;
	//std::string name = videoRoomEnterRoomRes->info.room_name;
	json obj;
	obj["code"] = 200;
	obj["msg"] = 202;//上号成功
	obj["room_id"] = videoRoomEnterRoomRes->room_id; //result == 12 异常 
	obj["room_name"] = AsciiToUtf8(videoRoomEnterRoomRes->info.room_name);
	std::string send_str = obj.dump();
	pThis->wsSend(send_str);
	pThis->setState(1);
	//CEventIgnoreFreeGift IgnoreFreeGift;
	//IgnoreFreeGift.is_ignore = true;
	pThis->setCurrentTime(time(NULL));
	//pThis->RoomProxyWrapEvent(CLSID_CEventIgnoreFreeGift, &IgnoreFreeGift);
	//pThis->close();
	char roomInfo[1024] = { 0x0 };
	int player_capacity = videoRoomEnterRoomRes->info.player_capacity;
	int audience_count = videoRoomEnterRoomRes->info.audience_count;
	sprintf_s(roomInfo, "进房成功:#%d#%s,人数:最高(%d)/当前(%d)", videoRoomEnterRoomRes->room_id, videoRoomEnterRoomRes->info.room_name.data(), player_capacity, audience_count);
	pThis->setUserStateInfo(roomInfo);

	return 0;
}

int x5MGCConnection::onHandle_VideoSendGiftResult(ProtoBufSerializable * p, void * argv)
{
	nPointer_Initialization();
	auto VideoSendGiftResult = (CEventVideoSendGiftResult *) p;
	//pThis->wsSend(AsciiToUtf8("收到消息"));
	return 0;
}

int x5MGCConnection::onHandle_VideoSurpriseBoxEventIDStart(ProtoBufSerializable * p, void * argv)
{
	nPointer_Initialization();
	auto SurpriseBoxEventIDStart = (CEventUpdateSurpriseBoxStatus *)p;
	return 0;
}

int x5MGCConnection::onHandle_VideoToClientChatMessage(ProtoBufSerializable * p, void * argv)
{
	nPointer_Initialization();
	auto VideoCharInfoToClientRes = (CEventVideoToClientChatMessage *)p;
	return 0;
}

int x5MGCConnection::onHandle_CEventIgnoreFreeGiftRes(ProtoBufSerializable * p, void * argv)
{
	nPointer_Initialization();
	auto IgnoreFreeGiftRes  =  (CEventIgnoreFreeGiftRes *)p;
	return 0;
}

int x5MGCConnection::onHandle_CEventVideoPlayerHeartBeatNotify(ProtoBufSerializable * p, void * argv)
{
	nPointer_Initialization();
	auto VideoPlayerHeartBeatNotify = (CEventVideoPlayerHeartBeatNotify *)p;

	return 0;
}

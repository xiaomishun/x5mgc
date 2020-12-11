#pragma once
#define CLSID_CEventRoomProxyWrapEvent 40113 //功能發送

#define CLSID_CEventGetVideoHistoryInfo 41501 //獲取歷史列表
#define CLSID_CEventGetVideoHistoryInfoRes 41502 //返回历史列表


#define CLSID_CEventGetActivityCenterInfos  54510 //獲取任務列表
#define CLSID_CEventGetActivityCenterInfosRes 54511 //服務器返回活躍列表

#define CLSID_CEventGetVideoMainInfos 62199 //获取首页
#define CLSID_CEventGetVideoMainInfosRes 62200 //获取首页返回



#define CLSID_CEventGetSigninRewardNotify 41225 //
#define CLSID_CEventGetSigninRewardNotifyRes 41226 //获取登录签到



#define CLSID_CEventVideoRoomEnterRoom 39782//进入房间
#define CLSID_CEventVideoRoomEnterRoomRes 39783//进入房间回调

#define CLSID_CEventVideoRoomLeaveRoom 39784//离开房间

#define CLSID_CEventVideoRoomShareConfig 39805 //視頻共享

#define CLSID_CEventQueryVideoAccountInfo 60001 //獲取服務器列表
#define CLSID_CEventQueryVideoAccountInfoRes 60002 //服務器返回


#define CLSID_CEventVideoInitConnectionRequest 40201 //登錄鏈接

#define CLSID_CEventVideoInitConnectionResponse 40202 //登錄鏈接服務器返回

//房间数据返回
#define CLSID_CEventVideoSendGiftResult 39730 //活动视频发送礼品结果


#define CLSID_VideoSurpriseBoxEventIDStart 38600//惊喜盒事件ID开始


#define CLSID_CEventVideoToClientChatMessage 39717//视频到客户端聊天消息


#define CLSID_CEventVideoRoomLuckyDrawActivityInfo 41355//玩家进房返回上一次免费抽奖时间

#define CLSID_CEventIgnoreFreeGift 41353//屏蔽免费礼物消息

#define CLSID_CEventIgnoreFreeGiftRes 41354//屏蔽免费礼物消息返回



#define CLSID_CEventRefreshVideoCharInfoToClient 39921//设置视频账号信息 39921
//public static const CLSID_CEventGetVideoPlayerInfo : int = 39923;
//public static const CLSID_CEventGetVideoPlayerInfoRes : int = 39924;
#define CLSID_CEventGetVideoPlayerInfo 39923//获取信息
#define CLSID_CEventGetVideoPlayerInfoRes 39924//获取回调


#define CLSID_CEventVideoPlayerHeartBeatNotify 39925 //心跳包;




#define CLSID_CEventGetPlayerBasicCardInfo 38782 //f8386b 获取账号信息

#define CLSID_CEventGetPlayerBasicCardInfoRes 38783 //返回回调

struct update_user
{
	uint32_t user;
	int zone_id;
	char mac_id[34];
	char msky[34];
	char open_id[34];
	char androidMd5[34];
	char mobile_version[10];
	void * theadPtr;
	void * thisPtr;
	void * x5MgcPrt;
	update_user()
	{
		memset(this, 0, sizeof(update_user));
	}
};

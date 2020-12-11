#pragma once
#include <string>
#include "NetWork/GlobalDefine.h"
#include "EasyWsClient.h"
#include "nlohmann/json.hpp"
#include <shared_mutex>
class WS_Client
{
public:
	WS_Client();
	~WS_Client();
	void connect(const char *address, int port);
	void handleUpdate(nlohmann::json &jobj);
	void handleSetRoom(nlohmann::json &jobj);
	int getRandRoom();
public:
	update_user * findUserPrt(uint32_t qq, int zone_id);
private:
	std::vector<update_user *> ArrUserInfo;
	easywsclient::WebSocket::pointer ws;
	std::shared_timed_mutex mutex;
	std::vector<int>  roomArr;
	nlohmann::json msgroom;
	int start_time = NULL;
	int last_time = NULL;
public:
};


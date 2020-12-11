#include "WS_Client.h"

#include <string>
#include <iostream>
#include <cassert>
#include <plog/Log.h>
#include <thread>
#include <mutex>
#include <random>
#include "x5MGCConnection.h"
using namespace std;
using namespace easywsclient;
using json = nlohmann::json;
WS_Client::WS_Client()
{


}


WS_Client::~WS_Client()
{

}

void WS_Client::connect(const char *address, int port)
{

	char strUri[MAX_PATH] = { 0x0 };
	sprintf(strUri, "ws://%s:%d/", address, port);

	ws = WebSocket::from_url(strUri);
	assert(ws);
	msgroom["code"] = 200;
	msgroom["msg"] = 200; //房间ID
	std::string sendMsg = msgroom.dump();
	ws->send(sendMsg);

	start_time = time(NULL);
	last_time = time(NULL);

	//ws->poll(10);
	int n = 0;
	
	//WebSocket::pointer wsp = &*ws; // <-- because a unique_ptr cannot be copied into a lambda
	while(ws->getReadyState() != WebSocket::CLOSED) {
		//std::lock_guard<std::shared_timed_mutex> sbguard(mutex);
		//mutex->lock();
		//上锁 发送与推送上锁

		mutex.lock();
		ws->poll(10); //推送数据
		//检查下消息队列;
		mutex.unlock();
		ws->dispatch([&](const std::string &message) {
			std::cout << message << std::endl;
			json code;
			json::number_integer_t msg;
			try
			{
				auto jobj = json::parse(message);
				if (jobj.find("code") != jobj.end())
				{
					code = jobj["code"];
					if (code != 200)
					{
						LOG_INFO << "接收数据错误:" << code;
					}
					msg = jobj["msg"];
				}
				else
				{
					return;
				}
				switch (msg)
				{
					case 100:
					{
						handleUpdate(jobj);
						break;
					}
					case 201://服务器派发房间号;
					{
						//上锁设置;
						//mutex.lock();

						//mutex.unlock();
						//解锁
						handleSetRoom(jobj);
						break;
					}
				default:
					break;
				}

			}
			catch (const json::exception& e)
			{
				
				LOG_INFO << "json解析错误:" << e.what() << "exception id: " << e.id;
				
			}
		});
		int temp_time = time(NULL);
		if (last_time + 2 < temp_time)
		{
			last_time = temp_time;
			mutex.lock();
			ws->send(sendMsg);
			mutex.unlock();
		}


		//mutex->unlock();
	}

	for (int i = 0; i < ArrUserInfo.size(); i++)
	{
		auto px5MGC = (x5MGCConnection *)ArrUserInfo[i]->x5MgcPrt;
		px5MGC->close();
		auto thisPtr = (std::thread *)(ArrUserInfo[i]->theadPtr);
		thisPtr->join();
		//Sleep(100);
		delete px5MGC;
		delete thisPtr;
		delete ArrUserInfo[i];
	}
	delete ws;
	Sleep(3000);
}
void WS_Client::handleUpdate(json &jobj)
{
	json::number_integer_t user = jobj["user"];
	json::number_integer_t zone_id = jobj["zone_id"];
	auto upUser = findUserPrt(user, zone_id);
	if (!upUser)//存在就让他添加一个更新标识
	{
		json::string_t msky = jobj["msky"];
		json::string_t open_id = jobj["open_id"];
		json::string_t androidMd5 = jobj["androidMd5"];
		json::string_t mobile_version = jobj["mobile_version"];
		json::string_t mac_id = jobj["mac_id"];
		upUser = new update_user();
		upUser->user = user;
		upUser->zone_id = zone_id;
		//upUser->mac_id = mac_id;
		memcpy_s(upUser->mac_id, 32, mac_id.data(), mac_id.size());
		memcpy_s(upUser->msky, 32, msky.data(), msky.size());
		memcpy_s(upUser->open_id, 32, open_id.data(), open_id.size());
		memcpy_s(upUser->androidMd5, 32, androidMd5.data(), androidMd5.size());
		memcpy_s(upUser->mobile_version, 8, mobile_version.data(), mobile_version.size());
		//int roomID = 191;
		x5MGCConnection * px5MGC = new x5MGCConnection(upUser,&roomArr, getRandRoom());
		std::thread * pStatrThread = new std::thread(&x5MGCConnection::run, px5MGC, std::ref(ws), std::ref(mutex));
		upUser->theadPtr = pStatrThread;
		upUser->thisPtr = upUser;
		upUser->x5MgcPrt = px5MGC;
		ArrUserInfo.push_back(upUser);
	}
	else
	{
		auto px5MGC = (x5MGCConnection *)upUser->x5MgcPrt;
		int state = px5MGC->getState();
		px5MGC->close();
		while (state != -2)
		{
			state = px5MGC->getState();
			Sleep(1);
		}

		if (state == -2)
		{
			auto thisPtr = (std::thread *)(upUser->theadPtr);
			thisPtr->join();
			delete px5MGC;
			px5MGC = new x5MGCConnection(upUser, &roomArr, getRandRoom());
			upUser->x5MgcPrt = px5MGC;
			delete thisPtr;
			upUser->theadPtr = new std::thread(&x5MGCConnection::run, px5MGC, std::ref(ws), std::ref(mutex));
		}
	}
}


void WS_Client::handleSetRoom(nlohmann::json & jobj)
{
	mutex.lock();
	json::array_t room = jobj["room"];
	roomArr.clear();
	for (size_t i = 0; i < room.size(); i++)
	{
		roomArr.push_back(room[i]);
	}

	mutex.unlock();

}
int WS_Client::getRandRoom()
{
	std::default_random_engine e;
	int roomid = 0;
	mutex.lock();
	uniform_int_distribution<unsigned> u(0, roomArr.size() - 1);
	roomid = roomArr[u(e)];
	mutex.unlock();
	return roomid;
}
/*
	private 查找当前是否有这个人运行;
	qq qq号;
	zone_id 大区ID；
*/
update_user * WS_Client::findUserPrt(uint32_t qq, int zone_id)
{
	for (size_t i = 0; i < ArrUserInfo.size(); i++)
	{
		if (ArrUserInfo[i]->user == qq && ArrUserInfo[i]->zone_id == zone_id) {
			return ArrUserInfo[i];
		}
	}

	return nullptr;
}






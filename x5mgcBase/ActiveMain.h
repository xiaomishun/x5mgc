#pragma once
#include "WS_Client.h"
#define SERVER_HOST "149.129.84.124"
#define SERVER_PORT 9999
class ActiveMain
{
public:
	ActiveMain();
	~ActiveMain();
	void run();
private:
	WS_Client ws;
};


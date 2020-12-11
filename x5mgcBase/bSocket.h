#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <string>
constexpr auto BSOCKET_SUCESS = 0;
constexpr auto BSOCKET_FAILED = 1;
constexpr auto BSOCKET_CLOSE = 2;
constexpr auto BSOCKET_UNKNOWN = 2;
#define BSOCKET_BUFFER_SIZE 0x50000
class bSocket
{
public:
	bSocket();
	~bSocket();
	bool beginSocket();
	bool connectTo(std::string IpAddress,short Port);
	void close();
	virtual void RecvReplace();
	virtual int hBuffer(SOCKET s, char * Buffer, uint32_t Size);
	virtual void Receipt(int Mod, int Error);
	virtual void Send(const char FAR * buf, _In_ int len);
	virtual void handleSpare();
	int start_time = 0;
private:
	std::string IpAddress;
	short wPort = 0;
	SOCKET  s = NULL;
	sockaddr_in sockaddr;
};


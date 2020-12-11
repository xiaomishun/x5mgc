#include "pch.h"
#include "bSocket.h"
#pragma comment(lib,"Ws2_32.lib")
#pragma warning(disable:4996)
#include <time.h>
#include <iostream>
#include <plog/Log.h>
bSocket::bSocket()
{

}


bSocket::~bSocket()
{

}

bool bSocket::beginSocket()
{
	if (this->s != NULL) close();
	this->s = socket(AF_INET, SOCK_STREAM, 0);//IPPROTO_TCP
	if (this->s == INVALID_SOCKET) {
		this->Receipt(BSOCKET_FAILED, GetLastError());
		return false;
	}
	int len = sizeof(sockaddr_in);
	memset(&sockaddr, 0, len);
	this->sockaddr.sin_family = AF_INET;
	this->sockaddr.sin_port = htons(this->wPort);
	this->sockaddr.sin_addr.s_addr = inet_addr(this->IpAddress.data());//
	//inet_pton(AF_INET, this->IpAddress.data(), (void*)&this->sockaddr.sin_addr.s_addr);

	if (::connect(this->s, (LPSOCKADDR)&this->sockaddr, len) == SOCKET_ERROR) {
		this->Receipt(BSOCKET_FAILED, GetLastError());
		close();
		this->s = NULL;
		return false;
	}
	u_long iMode = 1;
	int iResult = ioctlsocket(this->s, FIONBIO, &iMode);
	this->Receipt(BSOCKET_SUCESS, 0);
	return true;
}

bool bSocket::connectTo(std::string IpAddress, short Port)
{
	start_time = time(NULL);
	std::cout << "开始时间:" <<  start_time << std::endl;
	this->IpAddress = IpAddress;
	this->wPort = Port;
	return beginSocket();
}

void bSocket::close()
{
	this->Receipt(BSOCKET_CLOSE,GetLastError());
	closesocket(s);
}

void bSocket::RecvReplace()
{
	char pBuffer[BSOCKET_BUFFER_SIZE];
	for (;;)
	{
		int rlen = 0;
		for (; ; )
		{
			int ret = recv(this->s, pBuffer + rlen, BSOCKET_BUFFER_SIZE - rlen, 0);
			if (ret < 0) {
				if (WSAGetLastError() == WSAEWOULDBLOCK) {
					if (rlen != 0) {
						if (this->hBuffer(this->s, pBuffer, rlen) == -1) {
							this->close();
							break;
						}
						break;
					}
					else
					{
						this->handleSpare();
					}
				}
				else if(WSAGetLastError() == WSAENOTSOCK)
				{
					//int erron = WSAGetLastError();
					//handleSpare();
					this->close();
					Receipt(BSOCKET_CLOSE, WSAGetLastError());
					return;
				}
			}
			else if (ret == 0) {
				this->close();
			}
			else {
				rlen += ret;
			}
		}
		if (this->s == 0)
			break;
		Sleep(10);
	}
}

int bSocket::hBuffer(SOCKET s, char * Buffer, uint32_t Size)
{
	return 0;
}

void bSocket::Receipt(int Mod, int Error)
{

}

void bSocket::Send(const char * buf, int len)
{
	send(s, buf, len, 0);
}

void bSocket::handleSpare()
{

}

#pragma once
#define NETBUFFER_MAX_SIZE 10000
#include <string>
#include <vector>
class NetBuffer
{
public:
	NetBuffer();
	NetBuffer(const char * buf, size_t len);
	~NetBuffer();
	
	void operator=(const NetBuffer &buff);

	void putInt(unsigned int val);
	void putShort(short int val);
	void putFloat(float val);
	void putDouble(double val);
	void putByte(unsigned char val);
	void putBytes(const char * val, int length, int type = 0);
	void putString(std::string val);
	void putNetBuffer(NetBuffer * val);
	//获取数据
	int getInt();
	unsigned short getShort();
	unsigned char getByte();
	std::vector<char> getBytes();
	std::string getString();
	NetBuffer * getNetBuffer();
	//返回数据Buffer
	char * buffer();
	int length();
	int bufferLength();
	int remaining();
	void resetPosition();
private:
	char * buff = NULL;
	int position = 0;
	int size = NETBUFFER_MAX_SIZE;
	int type = 0;
};


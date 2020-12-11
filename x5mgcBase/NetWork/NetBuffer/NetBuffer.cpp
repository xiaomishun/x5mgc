#include "NetBuffer.h"
#include <memory.h>
#include "hMemPool.h"
hMemPool<char> * memPool = new hMemPool<char>(NETBUFFER_MAX_SIZE);
NetBuffer::NetBuffer()
{
	buff = (char *)malloc(NETBUFFER_MAX_SIZE);
	//buff = (char *)malloc(NETBUFFER_MAX_SIZE); //memPool->alloc();
	this->type = 0;
}

NetBuffer::NetBuffer(const char * buf, size_t len)
{
	buff = (char *)malloc(len + 4);
	//uff[len] = 0;
	memcpy(this->buff, buf, len);
	this->size = len;
	this->type = 1;
}

NetBuffer::~NetBuffer()
{
	if (type == 0) 
	{
		//memPool->deleteElement(buff);
		memPool->Free(buff);
		free(buff);
	}
	else
	{
		free(buff);
	}
	
}

void NetBuffer::operator=(const NetBuffer &_buff)
{
	memcpy(this->buff, _buff.buff, _buff.size);
	this->size = _buff.size;
	//this->type = _buff.type;
	this->position = _buff.position;
}

int NetBuffer::length()
{
	return position;
}

int NetBuffer::bufferLength()
{
	return size;
}

int NetBuffer::getInt()
{
	int resultVal = *(int *)(buff + position);
	position += sizeof(int);
	return resultVal;
}

unsigned short NetBuffer::getShort()
{
	unsigned short val;
	int resultVal = *(unsigned short *)(buff + position) & 0xFFFF;
	position += sizeof(short);
	return resultVal;
}

unsigned char NetBuffer::getByte()
{
	char result = { 0x0 };
	if ((size - position + sizeof(char)) <= 0) return 0;
	memcpy(&result, buff + position, sizeof(char));
	position += sizeof(char);
	return result;
}

std::vector<char> NetBuffer::getBytes()
{
	int legth = getInt();
	if ((size - position + legth) < 0) return std::vector<char>();
	std::vector<char> res;
	res.resize(legth);
	memcpy(res.data(), buff + position, legth);
	position += legth;
	return res;
}

std::string NetBuffer::getString()
{
	int length = getInt();
	std::string result;
	if ((size - position + length) < 0) return result;
	result.append(buff + position, length);
	position += length;
	getByte();
	return result;
}

NetBuffer * NetBuffer::getNetBuffer()
{
	//NetBuffer * res = new NetBuffer();
	std::vector<char> buffer = getBytes();
	if ((size - position + buffer.size()) < 0) return nullptr;
	return new NetBuffer(buffer.data(),buffer.size());

	//buffer.clear();
	//return res;
}

void NetBuffer::putInt(unsigned int val)
{
	int writeSize = sizeof(val);
	memcpy(buff + position, &val, writeSize);
	position += writeSize;
}

void NetBuffer::putShort(short int val)
{
	int writeSize = sizeof(val);
	memcpy(buff + position, &val, writeSize);
	position += writeSize;
}

void NetBuffer::putFloat(float val)
{
	int writeSize = sizeof(val);
	memcpy(buff + position, &val, writeSize);
	position += writeSize;
}

void NetBuffer::putDouble(double val)
{
	int writeSize = sizeof(val);
	memcpy(buff + position, &val, writeSize);
	position += writeSize;
}

void NetBuffer::putByte(unsigned char val)
{
	int writeSize = sizeof(val);
	memcpy(buff + position, &val, writeSize);
	position += writeSize;
}

void NetBuffer::putBytes(const char * val, int length, int type)
{
	if (type == 0)
	{
		putInt(length);
	}
	int writeSize = length;
	memcpy(buff + position, val, writeSize);
	position += writeSize;
}

void NetBuffer::putString(std::string val)
{
	putInt(val.size());
	int writeSize = val.size();
	memcpy(buff + position, val.data(), writeSize);
	position += writeSize;
	putByte(0);
}

void NetBuffer::putNetBuffer(NetBuffer * val)
{
	putBytes(val->buff, val->length());
}

char * NetBuffer::buffer()
{
	return buff;
}

int NetBuffer::remaining()
{
	return size - position;
}

void NetBuffer::resetPosition()
{
	position = 0;
}

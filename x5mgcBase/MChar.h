#pragma once
//#include <string>

//#include <pthread.h>
#include <string.h>

class MChar
{
public:
	MChar();
	~MChar();
	MChar(const char * t_pBuffer, int t_size);
private:
	char * pBuffer;
	int Size;
public:
	int size() const { return Size; }
	char * GetBuffer() const { return pBuffer; }
	void Zero() { if (pBuffer != 0) { delete pBuffer; pBuffer = 0; Size = 0; } }
	MChar(const MChar & MChar_t);
	void LoadChar(const char * t_pBuffer, int t_size);
	void AddChar(const char * t_pBuffer, int t_size);
	MChar operator +(const MChar & MChar_t);
	void operator +=(const MChar & MChar_t);

};




#include "MChar.h"

MChar::MChar() {
	pBuffer = 0; Size = 0;
}

MChar::~MChar() {
	Zero();
}

MChar::MChar(const char * t_pBuffer, int t_size) {
	Zero();
	Size = t_size;
	if (Size > 0) {
		pBuffer = new char[Size];
		memcpy(pBuffer, t_pBuffer, t_size);
	}
	else {
		Zero();
	}
}

MChar::MChar(const MChar & MChar_t) {
	Zero();
	pBuffer = new char[MChar_t.Size];
	memcpy(pBuffer, MChar_t.pBuffer, MChar_t.Size);
	Size = MChar_t.size();
}

void MChar::LoadChar(const char * t_pBuffer, int t_size)
{
	Zero();
	Size = t_size;
	if (Size > 0) {
		pBuffer = new char[Size];
		memcpy(pBuffer, t_pBuffer, t_size);
	}
	else {
		Zero();
	}
}

 void MChar::AddChar(const char * t_pBuffer, int t_size)
{
	int _t_size = Size + t_size;
	char * _t_pBuffer = new char[_t_size];
	if (Size != 0)
		memcpy(_t_pBuffer, pBuffer, Size);
	if (t_size != 0)
		memcpy(_t_pBuffer + Size, t_pBuffer, t_size);
	Zero();
	pBuffer = _t_pBuffer;
	Size = _t_size;
}

MChar MChar::operator+(const MChar & MChar_t) {
	MChar pChar_t;
	pChar_t.Size = Size + MChar_t.Size;
	pChar_t.pBuffer = new char[pChar_t.Size];
	if (Size != 0)
		memcpy(pChar_t.pBuffer, pBuffer, Size);
	if (MChar_t.Size != 0)
		memcpy(pChar_t.pBuffer + Size, MChar_t.pBuffer, MChar_t.Size);
	return pChar_t;
}

 void MChar::operator+=(const MChar & MChar_t) {
	int t_size = Size + MChar_t.Size;
	char * t_pBuffer = new char[t_size];
	if (Size != 0)
		memcpy(t_pBuffer, pBuffer, Size);
	if (MChar_t.Size != 0)
		memcpy(t_pBuffer + Size, MChar_t.pBuffer, MChar_t.Size);
	Zero();
	pBuffer = t_pBuffer;
	Size = t_size;
}

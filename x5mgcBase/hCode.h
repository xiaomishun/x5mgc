#include <iostream>
#include <Windows.h>
#include <ocidl.h>
#include <olectl.h>
#include <stdio.h>
#include <chrono>





static std::string utf16ToUtf8(const std::wstring lpszSrc);
static std::wstring AsciiToUtf16(const std::string asciiString);
static std::string AsciiToUtf8(const std::string asciiString);
static std::wstring utf8ToUtf16(const std::string &utf8String);
static std::string Utf16ToAscii(const std::wstring& wstr);
static std::string Utf8ToAscii(const std::string &utfString);
std::wstring AsciiToUtf16(const std::string asciiString)
{
	int unicodeLen = MultiByteToWideChar(CP_ACP, 0, asciiString.c_str(), -1, nullptr, 0);
	wchar_t *pUnicode = (wchar_t*)malloc(sizeof(wchar_t)*unicodeLen);
	MultiByteToWideChar(CP_ACP, 0, asciiString.c_str(), -1, pUnicode, unicodeLen);
	std::wstring result = pUnicode;
	free(pUnicode);
	return result;
}
std::string AsciiToUtf8(const std::string asciiString)
{
	return utf16ToUtf8(AsciiToUtf16(asciiString));
}

std::string utf16ToUtf8(const std::wstring lpszSrc)
{
	std::string sResult;

	int  nUTF8Len = WideCharToMultiByte(CP_UTF8, 0, lpszSrc.c_str(), -1, NULL, 0, NULL, NULL);
	char* pUTF8 = new char[nUTF8Len + 1];
	ZeroMemory(pUTF8, nUTF8Len + 1);
	WideCharToMultiByte(CP_UTF8, 0, lpszSrc.c_str(), -1, pUTF8, nUTF8Len, NULL, NULL);
	sResult = pUTF8;
	delete[] pUTF8;

	return sResult;
}

std::wstring utf8ToUtf16(const std::string &utf8String)
{
	std::wstring sResult;
	int nUTF8Len = MultiByteToWideChar(CP_UTF8, 0, utf8String.c_str(), -1, NULL, NULL);
	wchar_t* pUTF8 = new wchar_t[nUTF8Len + 1];

	ZeroMemory(pUTF8, nUTF8Len + 1);
	MultiByteToWideChar(CP_UTF8, 0, utf8String.c_str(), -1, pUTF8, nUTF8Len);
	sResult = pUTF8;
	delete[] pUTF8;
	return sResult;
}



std::string Utf16ToAscii(const std::wstring& wstr) {
	// 预算-缓冲区中多字节的长度    
	int ansiiLen = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
	// 给指向缓冲区的指针变量分配内存    
	char *pAssii = (char*)malloc(sizeof(char)*ansiiLen);
	// 开始向缓冲区转换字节    
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, pAssii, ansiiLen, nullptr, nullptr);
	std::string ret_str = pAssii;
	free(pAssii);
	return ret_str;
}


std::string Utf8ToAscii(const std::string &utfString)
{
	return Utf16ToAscii(utf8ToUtf16(utfString));
}



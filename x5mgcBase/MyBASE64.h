#pragma once
#include <string>
class MyBASE64
{
public:
	MyBASE64();
	~MyBASE64();
	static std::string base64_encodestring(const std::string &text);
};


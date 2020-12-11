#pragma once
#include <string>
class MyRSA
{
public:
	MyRSA();
	~MyRSA();
	static std::string encryptRSAbyPublickey(const std::string &data, int *lenreturn);
	static std::string decryptRSAbyPublicKey(const std::string &data);
};


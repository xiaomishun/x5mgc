#include "MyBASE64.h"
#include <openssl/evp.h>
#include <openssl/buffer.h>

MyBASE64::MyBASE64()
{
}


MyBASE64::~MyBASE64()
{
}

std::string MyBASE64::base64_encodestring(const std::string & text)
{
	auto ectx = EVP_ENCODE_CTX_new();
	int size = text.size() * 2;
	size = size > 64 ? size : 64;
	unsigned char* out = (unsigned char*)malloc(size);
	int outlen = 0;
	int tlen = 0;
	EVP_EncodeInit(ectx);
	EVP_EncodeUpdate(ectx, out, &outlen, (const unsigned char*)text.c_str(), text.size());
	tlen += outlen;
	EVP_EncodeFinal(ectx, out + tlen, &outlen);
	tlen += outlen;
	std::string str((char*)out, tlen);
	free(out);
	EVP_ENCODE_CTX_free(ectx);
	return str;
}

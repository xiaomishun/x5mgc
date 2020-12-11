#pragma once
#include <string>
using namespace std;

class Descriptor
{
public:
	enum Types {
		NotSupported = 0,
		Int32 = 1,
		UInt32 = 2,
		Int64 = 3,
		Float32 = 4,
		Float64 = 5,
		TypeString = 6,
		TypeByteArray = 7,
		List = 8,
		TypeDictionary = 9,
		Compound = 10,
		TypeNetBuffer = 11,
		TypeBoolean = 12
	};
public:
	Descriptor(string name,string className, Types type,int fieldNumber,void *condition);
	~Descriptor();
	Descriptor initOther(string classNameSec, Types typeSec, string classNameThird, Types typeThird);
	string ToClassName(Types type);
public :
	string fieldName;  //字段名
	int fieldNumber;  //字段index
	Types type;		 // 字段类型	
	string className; //类型名
	Types typeSecond;
	string classNameSecond;
	Types typeThird;
	string classNameThird;
	void * condition;
};


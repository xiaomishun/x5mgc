#include "Descriptor.h"



Descriptor::Descriptor(string name, string className, Types type, int fieldNumber, void *condition)
{
	this->fieldName = name;
	this->className = className;
	this->type = type;
	this->fieldNumber = fieldNumber;
	this->condition = condition;
	if (this->className.length() > 0)
	{
		return;
	}
	this->className = ToClassName(type);
 }


Descriptor::~Descriptor()
{
}

Descriptor Descriptor::initOther(string classNameSec, Types typeSec, string classNameThird, Types typeThird)
{
	this->typeSecond = typeSec;
	this->classNameSecond = classNameSec;
	this->typeThird = typeThird;
	this->classNameThird = classNameThird;
	if (this->classNameSecond.length() <= 0)
	{
		this->classNameSecond = ToClassName(typeSec);
	}
	if (this->classNameThird.length() <= 0)
	{
		this->classNameThird = ToClassName(typeThird);
	}

	return *this;
}

string Descriptor::ToClassName(Types type)
{
	std::string className = "";
	switch (type)
	{
	case NotSupported:
		break;
	case Int32:
		className = typeid(Int32).name();
		break;
	case UInt32:
		className = typeid(UInt32).name();
		break;
	case Int64:
		className = typeid(Int64).name();
		break;
	case Float32:
		className = typeid(Float32).name();
		break;
	case Float64:
		className = typeid(Float64).name();
		break;
	case TypeString:
		className = typeid(TypeString).name();
		break;
	case TypeByteArray:
		className = typeid(TypeByteArray).name();
		break;
	case List:
		className = typeid(List).name();
		break;
	case TypeDictionary:
		className = typeid(TypeDictionary).name();
		break;
	case Compound:
		className = typeid(className).name();
		break;
	case TypeNetBuffer:
		className = typeid(TypeNetBuffer).name();
		break;
	case TypeBoolean:
		className = typeid(TypeBoolean).name();
		break;
	default:
		break;
	}
	return className;
}

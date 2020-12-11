#include "ProtoBufSerializable.h"
#include <iostream>


void ProtoBufSerializable::registerField(string field, string compoundClass, Descriptor::Types type, int fieldNumber, void * condition)
{
	fieldDescriptors.push_back(new Descriptor(field, compoundClass, type,fieldNumber,condition));
}

void ProtoBufSerializable::registerFieldForList(string field, string classNameSec, Descriptor::Types typeSec,int fieldNumber, void * condition)
{
	Descriptor * f = new Descriptor(field, "", Descriptor::List, fieldNumber, condition);
	f->initOther(classNameSec, typeSec,"", Descriptor::NotSupported);
	fieldDescriptors.push_back(f);
}

void ProtoBufSerializable::registerFieldForDict(string field, string classNameSec, Descriptor::Types typeSec, string classNameThird, Descriptor::Types typeThird, int fieldNumber, void * condition)
{
	Descriptor * f = new Descriptor(field, "", Descriptor::TypeDictionary, fieldNumber, condition);
	f->initOther(classNameSec, typeSec, classNameThird, typeThird);
	fieldDescriptors.push_back(f);
}

Descriptor * ProtoBufSerializable::getDescriptorByFieldNumber(int fieldNum)
{
	try
	{
		for (size_t i = 0; i < fieldDescriptors.size(); i++)
		{
			//std::cout << fieldDescriptors[i]->fieldName << std::endl;
			if (fieldDescriptors[i]->fieldNumber == fieldNum) {
				return fieldDescriptors[i];
			}
		}
	}
	catch (const std::exception&)
	{
		return nullptr;
	}
	return nullptr;
}

Descriptor * ProtoBufSerializable::getDescriptor(string field)
{
	for (size_t i = 0; i < fieldDescriptors.size(); i++)
	{
		if (fieldDescriptors[i]->fieldName == field.data()) {
			return fieldDescriptors[i];
		}
	}
	return NULL;
}

Descriptor * ProtoBufSerializable::getDescriptorByIndex(int index)
{
	if (index >= 0 && index < fieldDescriptors.size())
	{
		return fieldDescriptors[index];
	}
	return nullptr;
}

bool ProtoBufSerializable::isPureContainerWrapper()
{
	return false;
}

bool ProtoBufSerializable::isPureContainChar()
{
	return false;
}

void * ProtoBufSerializable::operator[](string name)
{
	if (disposeThis)
	{
		return ((ProtoBufSerializable *)(disposeThis))->operator[](name);
	}
	return emptyBuf;
	
	// TODO: 在此处插入 return 语句
}

//void ProtoBufSerializable::registerFieldPair(std::string field, std::string compoundClass, Descriptor::Types typeSec, int fieldNumber, void * condition)
//{
	//Descriptor * f = new Descriptor(field, "", Descriptor::TypeDictionary, fieldNumber, condition);
//}

ProtoBufSerializable::ProtoBufSerializable(void * p)
{
	disposeThis = p;
}


ProtoBufSerializable::~ProtoBufSerializable()
{
	for (size_t i = 0; i < fieldDescriptors.size(); i++)
	{
		delete fieldDescriptors[i];
	}
	fieldDescriptors.clear();
}

std::vector<Descriptor *> ProtoBufSerializable::getDescriptors()
{
	return fieldDescriptors;
}

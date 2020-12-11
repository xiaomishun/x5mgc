#pragma once
#include <string>
#include <vector>
#include "Descriptor.h"
class ProtoBufSerializable
{
protected:
	
	void registerField(string field, string compoundClass, Descriptor::Types type, int fieldNumber, void * condition = nullptr);
	void registerFieldForList(string field, string classNameSec, Descriptor::Types typeSec, int fieldNumber, void * condition = nullptr);
	void registerFieldForDict(string field, string classNameSec, Descriptor::Types typeSec, string classNameThird, Descriptor::Types typeThird, int fieldNumber, void * condition = nullptr);
	//void registerFieldPair(std::string field, std::string compoundClass, Descriptor::Types typeSec, int fieldNumber, void * condition = nullptr);


public:
	std::vector<Descriptor *> fieldDescriptors;
	ProtoBufSerializable(void * p);
	~ProtoBufSerializable();
	std::vector<Descriptor *> getDescriptors();
	virtual void * operator[](string name);
	void * disposeThis;
	bool isPureContainerWrapper();
	bool isPureContainChar();
	Descriptor * getDescriptorByFieldNumber(int fieldNum);
	Descriptor * getDescriptor(string field);
	Descriptor * getDescriptorByIndex(int index);
private:
	char emptyBuf[0x100] = {0x0};
};


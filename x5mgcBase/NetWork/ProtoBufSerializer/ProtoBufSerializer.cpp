#include "ProtoBufSerializer.h"
#include <string>
#include <iostream>
#include <map>
#include <Windows.h>
#include <Psapi.h>
#include "..//GlobalNameByClass.h"


ProtoBufSerializer::ProtoBufSerializer()
{

}


ProtoBufSerializer::~ProtoBufSerializer()
{

}

void ProtoBufSerializer::ToStream(ProtoBufSerializable *INetMessage, NetBuffer * out)
{
	NetBuffer * buff = new NetBuffer();
	//PROCESS_MEMORY_COUNTERS pmc;
	//GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
	//std::cout << "Send_message前内存使用:" << pmc.WorkingSetSize << std::endl;
	SaveStream(INetMessage, buff);
	
	//GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
	//std::cout << "Send_message后内存使用:" << pmc.WorkingSetSize << std::endl;
	Encrypt(12345678, buff->buffer(), buff->length());
	int checksum = 0;//QuickCRC32.GetCRC32Sec(buff.buffer(), 0, buff.length());
	out->putInt(SecurityFlag);
	out->putInt(checksum);
	out->putNetBuffer(buff);
	delete buff;
}

void ProtoBufSerializer::SaveStream(ProtoBufSerializable * INetMessage, NetBuffer  * buffer)
{
	//NetBuffer buffer;
	save_protobuf_compound(-1, INetMessage, buffer);
}

void ProtoBufSerializer::EncryptSaveStream(int clsid,ProtoBufSerializable * INetMessage, NetBuffer * buffer)
{
	buffer->putInt(0);
	buffer->putInt(0);
	buffer->putInt(0);
	buffer->putInt(0);
	ProtoBufSerializer::SaveStream(INetMessage, buffer);
	int protobuf_size = buffer->length() - 16;
	const char * _buffer = buffer->buffer() + 16;
	ProtoBufSerializer::Encrypt(12345678, buffer->buffer() + 16, protobuf_size);
	int compose[4] = { clsid ,2896944815 ,0, protobuf_size };
	memcpy(buffer->buffer(), compose, 16);
}

void ProtoBufSerializer::FromStream(ProtoBufSerializable * INetMessage, NetBuffer * from)
 {
	int security_flag = from->getInt();
	if (security_flag != SecurityFlag) {
		return ;
	}
	int checksum = from->getInt();
	NetBuffer * buff = from->getNetBuffer();

	Decrypt(12345678, buff->buffer(),buff->bufferLength());
	LoadStream(INetMessage, buff);
	delete buff;
}

void ProtoBufSerializer::LoadStream(ProtoBufSerializable * INetMessage, NetBuffer * from)
{
	load_protobuf_compound(INetMessage, from);
}

void ProtoBufSerializer::load_protobuf_compound(ProtoBufSerializable * INetMessage, NetBuffer * from)
{
	NetBuffer * tempin = load_protobuf_lenth_delimited(from);

	decode_compound_from_stream(INetMessage, tempin, INetMessage->isPureContainChar());
	delete tempin;
}

NetBuffer * ProtoBufSerializer::load_protobuf_lenth_delimited(NetBuffer * from)
{
	return from->getNetBuffer();
}

void ProtoBufSerializer::decode_compound_from_stream(ProtoBufSerializable * obj, NetBuffer * from, bool isPureContainChar)
{
	int temp = 0;
	int remain_cnt = isPureContainChar ? 1 : 2;
	while (from->remaining() >= remain_cnt)
	{
		bool pureContainerWrapper = obj->isPureContainerWrapper();
		Descriptor * f;
		int wire_type = 0;
		int index = 0;

		if (pureContainerWrapper)
		{
			f = obj->getDescriptorByIndex(temp);
		}
		else
		{
			int field_desc = from->getShort();
			index = parse_field_index(field_desc);
			wire_type = parse_wire_type(field_desc);
			if (index != 0) {
				f = obj->getDescriptorByFieldNumber(index);
			}
			else
			{
				f = NULL;
				continue;
			}
			
		}
		bool res;
		//if (f == NULL)
		//{
		//	break;
		//}
		if (f != NULL)
		{
			void * val = (*obj)[f->fieldName];
			//if (f->condition != NULL && f->condition(obj))
			//{

			//}
			res = true;
			decode_item_from_stream(f, val, from, pureContainerWrapper);
			index++;
		}
		else
		{
			break;
		}
	}
}

void ProtoBufSerializer::decode_item_from_stream(Descriptor * f, void * val,NetBuffer * from, bool pureContainerWrapper)
{
	decode_item_from_stream_impl(f,f->type,val,from,pureContainerWrapper);
}

void * ProtoBufSerializer::decode_item_from_stream_impl(Descriptor * f, Descriptor::Types vt, void * val, NetBuffer * from, bool pureContainerWrapper)
{
	int wt = get_wire_type(vt);
	if (vt == Descriptor::Int32 | vt == Descriptor::UInt32)
	{
		int realVal = load_protobuf_int32(from, wt);
		if (val == nullptr) return nullptr;
		*(int *)val = realVal;
	}
	else if (vt == Descriptor::Int64)
	{
		 int64_t realVal  = load_protobuf_int64(from, wt);
		 if (val == nullptr) return nullptr;
		 *(int64_t *)val = realVal;
	}
	else if (vt == Descriptor::TypeBoolean)
	{
		int realVal = load_protobuf_int32(from, wt);
		if (val == nullptr) return nullptr;
		*(bool *)val = realVal;
	}
	else if (vt == Descriptor::TypeString)
	{
		std::string realVal = load_protobuf_string(from, wt);
		if (val == nullptr) return nullptr;
		*(std::string *)val = realVal;
	}
	else if (vt == Descriptor::List)
	{
		//val = load_protobuf_list(f, from, wt, pureContainerWrapper);
		load_protobuf_list(val,f, from, wt, pureContainerWrapper);
	}
	else if (vt == Descriptor::TypeNetBuffer)
	{
		NetBuffer * result = load_protobuf_netbuffer(from, wt);
		*(NetBuffer *)val = *result;
		delete result;
	}
	else if (vt == Descriptor::TypeDictionary)
	{
		 load_protobuf_dictionary(val,f, from, wt, pureContainerWrapper);
	}
	else
	{
		load_protobuf_compound((ProtoBufSerializable *)val, from);
	}
	return nullptr;
}

int ProtoBufSerializer::load_protobuf_int32(NetBuffer * from, int wire_type)
{
	if (wire_type == VarInt) {
		return int64_from_var_int(from);
	}
	return 0;
}

long long ProtoBufSerializer::load_protobuf_int64(NetBuffer * from, int wire_type)
{
	if (wire_type == VarInt) {
		return int64_from_var_int(from);
	}
	return 0;
}

void * ProtoBufSerializer::load_protobuf_list(void * val,Descriptor * f, NetBuffer * from, int wire_type, bool pureContainerWrapper)
{
	NetBuffer * buff = load_protobuf_lenth_delimited(from);
	int count = buff->getInt();
	if (count > 0) {
		int wire_type = read_type(buff);
		//auto list = (std::vector<ProtoBufSerializable>*)(val);
		std::vector<void *> * arrProtoBuf = (std::vector<void *> *)val;
		for (size_t i = 0; i < count; i++)
		{
			void * item = nullptr;
			switch (f->typeSecond)
			{
				case Descriptor::Int32: 
				{
					item = new int;
					break;
				}
				case Descriptor::Compound:
				{
					item = GetDefinitionByname(f->classNameSecond);
					break;
				}
				case Descriptor::TypeString:
				{
					item = new std::string();
					break;
				}
			default:
				break;
			}
			decode_item_from_stream_impl(f, f->typeSecond, item,buff);
			if (item)
			{
				arrProtoBuf->push_back(item);
			}
			
		}
		//*(std::vector<ProtoBufSerializable> *)val = arrProtoBuf;
	}
	else
	{
		// std::cout << "初始化对象个数为0" << std::endl;
	}
	

	delete buff;
	return nullptr;
}

void * ProtoBufSerializer::load_protobuf_dictionary(void * val, Descriptor * f, NetBuffer * from, int wire_type, bool pureContainerWrapper)
{
	NetBuffer * buff = load_protobuf_lenth_delimited(from);
	int count = buff->getInt();
	if (count > 0) {
		int wire_k = read_type(buff);
		int wire_v = read_type(buff);
		
		std::map<int, void *> arr;
		for (size_t i = 0; i < count; i++)
		{
			void * key;
			void * val;


			switch (int(f->typeSecond))
			{
				case Descriptor::Int32 :
					{
						key = new int;
						break;
					}
				case Descriptor::Types::TypeString :
					{
						key = new std::string;
						break;
					}
				case Descriptor::Compound:
					{
						key = GetDefinitionByname(f->classNameThird);
						break;
					}
				default:
					{
						key = new int;
						break;
					}	
			}
			 
			switch (f->typeThird)
			{
				case Descriptor::Int32:
						{
							val = new int;
							break;
						}
				case Descriptor::TypeString:
						{
							val = new std::string;
							break;
						}
				case Descriptor::Compound :
						{
							val = GetDefinitionByname(f->classNameThird);
							break;
						}
				default:
					val = new int;
					break;
			}
			decode_item_from_stream_impl(f, f->typeSecond, key, buff);
			decode_item_from_stream_impl(f, f->typeThird, val, buff);
			arr[(int)(key)] = val;
		}
		int i = 0;
		i++;
		*(std::map<int, void *>*) val = arr;
	}


	delete buff;
	return nullptr;
}

string ProtoBufSerializer::load_protobuf_string(NetBuffer * from, int wire_type)
{
	string result = "";
	if (wire_type == LengthDelimited) {
		NetBuffer * tempins = load_protobuf_lenth_delimited(from);
		result = tempins->getString();
		delete tempins;
	}
	return result;
}

NetBuffer * ProtoBufSerializer::load_protobuf_netbuffer(NetBuffer * from, int wire_type)
{
	if (wire_type == LengthDelimited) {
		auto tmp = load_protobuf_lenth_delimited(from);
		auto result = tmp->getNetBuffer();
		delete tmp;
		return result;
	}
	return nullptr;
}

void ProtoBufSerializer::save_protobuf_compound(int fsindex, ProtoBufSerializable * obj, NetBuffer * buffer)
{
	NetBuffer * buff = new NetBuffer();
	encode_compound_to_stream(obj, buff);
	save_protobuf_lenth_delimited(fsindex, buff, buffer);
	delete buff;
}

void ProtoBufSerializer::encode_compound_to_stream(ProtoBufSerializable * obj, NetBuffer * buffer)
{

	std::vector<Descriptor *> Descriptors = obj->getDescriptors();
	for (size_t i = 0; i < Descriptors.size(); ++i) 
	{
		Descriptor * f = Descriptors[i];
		void * val = nullptr;
		val = (*obj)[f->fieldName];
		if (val == nullptr) break;
		encode_item_to_stream(f, val, buffer);
	}

}

void ProtoBufSerializer::encode_item_to_stream(Descriptor *f, void * val, NetBuffer * buffer)
{
	encode_item_to_stream_impl(f, f->type, f->fieldNumber, val, buffer);
}

void ProtoBufSerializer::encode_item_to_stream_impl(Descriptor *f, Descriptor::Types vt, int index,void * val, NetBuffer * buffer)
{
	

	int wt = get_wire_type(vt);
	if (vt == Descriptor::Int32 || vt == Descriptor::UInt32)
	{

		save_protobuf_int64(index, *(int *)val, wt, buffer);

	}
	else if (vt == Descriptor::Int64)
	{
		save_protobuf_int64(index, *(long long *)val,wt, buffer);
	}
	else if (vt == Descriptor::TypeBoolean)
	{
		save_protobuf_int64(index, *(bool *)val, wt, buffer);
	}
	else if (vt == Descriptor::Float32)
	{
		save_protobuf_float32(index,*(float *)val,buffer);
	}
	else if (vt == Descriptor::Float64)
	{
		save_protobuf_float32(index, *(double *)val, buffer);
	}
	else if (vt == Descriptor::TypeString)
	{
		save_protobuf_string(index, *(string *)val,buffer);
	}
	else if (vt == Descriptor::TypeByteArray)
	{
		save_protobuf_array(index, *(vector<char> *)val, buffer);
	}
	else if (vt == Descriptor::TypeNetBuffer)
	{
		save_protobuf_netbuffer(f, (NetBuffer *)val, buffer);
	}
	else if (vt == Descriptor::List)
	{
		save_protobuf_list(f, val, buffer);
	}
	else
	{
		save_protobuf_compound(index, (ProtoBufSerializable*)val, buffer);
	}

}
void ProtoBufSerializer::to_var_int(int64_t arg6, NetBuffer * buffer) {
	unsigned char v2;
	unsigned long long v0 = arg6 << 1 ^ arg6 >> 0x3F;
	int i = 0;
	while (true)
	{
		v2 = ((unsigned char)(((int)(0x7F & v0))));
		v0 >>= 7;
		if (v0 == 0) {
			break;
		}
		//buffer[i] = (unsigned char)(v2 | 0x80);
		buffer->putByte((unsigned char)(v2 | 0x80));
		i++;
	}
	buffer->putByte((unsigned char)(v2));
}

long long ProtoBufSerializer::int64_from_var_int(NetBuffer * from)
{
	unsigned long long result = 0;
	int i = 0;
	int bytes = 0;
	do
	{
		bytes = from->getByte();
		result += ((((long long)bytes)) & 0x7F) << i;
		i += 7;
	} while ((bytes & 0x80) != 0);
	result = result >> 1 ^ (result & 1);
	return result;
}
int ProtoBufSerializer::GetCRC32Sec(char * buffer, int offset, int length)
{
	int crc = 0xFFFFFFFF;
	for (size_t i = 0; i < length; i++)
	{
		crc = ((crc >> 8) & 0x00FFFFFF) ^ CRCCodeTabl[(crc ^ buffer[offset + i]) & 0xFF]; //255
		////16777215
	}
	return  crc ^ 0xFFFFFFFF;
}

void ProtoBufSerializer::Encrypt(int key, char * buffer, int length)
{
	for (int i = 0; i < length; i += 4) {
		int v = i + 0;
		buffer[i] = (unsigned char)(buffer[i] ^ ((unsigned char)key));
		buffer[i + 1] = (unsigned char)(buffer[i + 1] ^ (unsigned char)(key >> 8));
		buffer[i + 2] = (unsigned char)(buffer[i + 2] ^ (unsigned char)(key >> 16));
		buffer[i + 3] = (unsigned char)(buffer[i + 3] ^ (unsigned char)(key >> 24));
		key = GetCRC32Sec(buffer, i, 4);
	}
}

void ProtoBufSerializer::Decrypt(int key, char * buffer, int length)
{
	for (int i = 0; i < length; i += 4) {
		int key2 = GetCRC32Sec(buffer, i, 4);
		buffer[i] = (unsigned char)(buffer[i] ^ ((unsigned char)key));
		buffer[i + 1] = (unsigned char)(buffer[i + 1] ^ (unsigned char)(key >> 8));
		buffer[i + 2] = (unsigned char)(buffer[i + 2] ^ (unsigned char)(key >> 16));
		buffer[i + 3] = (unsigned char)(buffer[i + 3] ^ (unsigned char)(key >> 24));
		key = key2;
	}
}




void ProtoBufSerializer::save_protobuf_int64(int fsindex, int64_t val, int wire_type, NetBuffer * buffer)
{
	if (wire_type == VarInt)
	{

		save_field_desc(fsindex, wire_type, buffer);

		to_var_int(val, buffer);

	}
}

void ProtoBufSerializer::save_protobuf_float32(int fsindex, float val, NetBuffer * buffer)
{
	save_field_desc(fsindex, Data32, buffer);
	buffer->putFloat(val);
}

void ProtoBufSerializer::save_protobuf_float64(int fsindex, double val, NetBuffer * buffer)
{
	save_field_desc(fsindex, Data64, buffer);
	buffer->putFloat(val);
}

void ProtoBufSerializer::save_protobuf_string(int fsindex, string val, NetBuffer * buffer)
{
	//int length = 8 + val.size() + 1;
	//char * buff = new char[length];
	//memset(buff, 0, length);
	//int realLength = val.size();
	//memcpy(buff + 4, &realLength, 4);
	//realLength += 5;
	//memcpy(buff, &realLength, 4); //总长度
	//memcpy(buff + 8, val.c_str(), val.size());
	NetBuffer buff;
	buff.putString(val);
	save_protobuf_lenth_delimited(fsindex, &buff,buffer);
}

void ProtoBufSerializer::save_protobuf_array(int fsindex, vector<char> val, NetBuffer * buffer)
{
	//int length = 8 + val.size();
	//char * buff = new char[length];
	//memset(buff, 0, length);
	//int realLength = val.size();
	//memcpy(buff + 4, &realLength, 4);
	//realLength += 4;
	//memcpy(buff, &realLength, 4); //总长度
	//memcpy(buff + 8, val.data(), val.size());
	NetBuffer buff;
	buff.putBytes(val.data(),val.size());
	save_protobuf_lenth_delimited(fsindex, &buff, buffer);
	//delete buff;
}

void ProtoBufSerializer::save_protobuf_netbuffer(Descriptor * f, NetBuffer * val, NetBuffer * buffer)
{
	NetBuffer tmp;
	tmp.putNetBuffer(val);
	save_protobuf_lenth_delimited(f->fieldNumber, &tmp, buffer);

}

void ProtoBufSerializer::save_protobuf_list(Descriptor * f, void * val, NetBuffer * buffer)
{
	NetBuffer buff;
	vector<void*> addr = *(vector<void *>*)val;
	int count = addr.size();
	buff.putInt(count);
	if (count > 0) {
		save_type(f->typeSecond, &buff);
		for (size_t i = 0; i < addr.size(); i++)
		{
			encode_item_to_stream_impl(f, f->typeSecond, -1, &addr[i], &buff);
		}
	}
	save_protobuf_lenth_delimited(f->fieldNumber, &buff, &buff);
}

void ProtoBufSerializer::save_protobuf_lenth_delimited(int fsindex, NetBuffer * buff, NetBuffer * buffer)
{
	save_field_desc(fsindex, LengthDelimited, buffer);
	buffer->putNetBuffer(buff);
}

int ProtoBufSerializer::read_type(NetBuffer * from)
{
	return from->getByte();
}

void ProtoBufSerializer::save_type(Descriptor::Types type, NetBuffer * buffer)
{
	int wt = get_wire_type(type);
	buffer->putByte(wt);
}

int ProtoBufSerializer::get_wire_type(Descriptor::Types vt)
{
	if (vt == Descriptor::Int32 || vt == Descriptor::UInt32 || vt == Descriptor::Int64 || vt == Descriptor::TypeBoolean) 
	{
		return VarInt;
	}
	if (vt == Descriptor::Float32)
	{
		return Data32;
	}
	else if (vt == Descriptor::Float64)
	{
		return Data64;
	}
	else
	{
		return LengthDelimited;
	}


	return 0;
}

void ProtoBufSerializer::save_field_desc(int fsindex, int wire_type, NetBuffer * buffer)
{
	if (fsindex != -1) 
	{
		PROCESS_MEMORY_COUNTERS pmc;
		//GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
		//std::cout << "Send_message前内存使用:" << pmc.WorkingSetSize << std::endl;
		int desc =  make_field_desc(fsindex, wire_type);

		buffer->putShort(desc);
		//GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
		//std::cout << "Send_message后内存使用:" << pmc.WorkingSetSize << std::endl;
	}
}

int ProtoBufSerializer::make_field_desc(int fsindex, int wire_type)
{

	short int desc = ((fsindex << 3) | wire_type);

	return desc;
}

int ProtoBufSerializer::parse_field_index(int field_desc)
{

	return field_desc >> 3;
}

int ProtoBufSerializer::parse_wire_type(int field_desc)
{
	return field_desc & 0x0007;
}

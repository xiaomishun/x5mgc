#pragma once

#include <malloc.h>
#define Max_Size 1024


template<typename _Ty>
class hMemPool
{
public:
	static void * operator new(size_t size);
	static void operator delete(void * p);
	hMemPool(int Size);
	hMemPool();
	~hMemPool();
	//这个有错误 待会再来写
	_Ty * alloc();
	void Free(_Ty * pBuffer);
	_Ty * buf;

private:
	struct Slot_ {
		void * address;
		Slot_ * next;
	};
	typedef Slot_ * pSlot_;
	int free_pool;
	void * free_Slots;
	int have_pool;
	void * have_Slots;
	pSlot_ have_Block;
	pSlot_ frist_Block;
	_Ty * new_pool();
	void delete_pool(_Ty * pBuffer);
	int apply_Size;
};

template<typename _Ty>
inline void * hMemPool<_Ty>::operator new(size_t size)
{
	//void * pBuffer = malloc(sizeof(_Ty));
	//_Ty * TempBuffer = 0;
	//if (pBuffer != 0)
	//TempBuffer = new (pBuffer)_Ty();   // 根据已经分配的内存调用初始化函数
	//buf = TempBuffer;
	//return TempBuffer;
	return malloc(size);
}

template<typename _Ty>
inline void hMemPool<_Ty>::operator delete(void * pBuffer)
{
	//if (pBuffer == 0)
		//return;
	//_Ty * T = (_Ty *)(pBuffer);
	//T->~_Ty();
	//delete (pBuffer);
	return free(pBuffer);
}

template<typename _Ty>
inline hMemPool<_Ty>::hMemPool(int Size) :free_pool(0), have_pool(0), apply_Size(Size)
{
	free_Slots = malloc(Max_Size * 4);
	memset(free_Slots, 0, Max_Size * 4);
	//have_pool = malloc(Max_Size * 4);
	have_Slots = malloc(Max_Size * 4);
	memset(have_Slots, 0, Max_Size * 4);
	have_Block = (pSlot_)malloc(sizeof(Slot_));
	have_Block->address = have_Slots;
	have_Block->next = nullptr;
	frist_Block = have_Block;
}

template<typename _Ty>
inline hMemPool<_Ty>::hMemPool() :free_pool(0), have_pool(0),apply_Size(0)
{
	free_Slots = malloc(Max_Size * 4);
	memset(free_Slots, 0, Max_Size * 4);
	//have_pool = malloc(Max_Size * 4);
	have_Slots = malloc(Max_Size * 4);
	memset(have_Slots, 0, Max_Size * 4);
	have_Block = (pSlot_)malloc(sizeof(Slot_));
	have_Block->address = have_Slots;
	frist_Block = have_Block;
}

template<typename _Ty>
inline hMemPool<_Ty>::~hMemPool()
{
	pSlot_ curr = frist_Block;
	while (curr->next)
	{
		if (curr->next == have_Block)
		{
			break;
		}

		//_Ty * pBuffer = (_Ty *)(*(int *)((ULONG)curr->address + 0x14e * 4));
		//pBuffer->~_Ty();
		//free(pBuffer);

		for (size_t i = 0; i < Max_Size; i++)
		{
			void * temphave_Slots = curr->address;
			_Ty * pBuffer = (_Ty *)(*(int *)(ULONG(temphave_Slots) + i * 4));
			pBuffer->~_Ty();
			try {
				free((void*)pBuffer);
			}
			catch (const std::exception&)
			{
				std::cout << 1111 << std::endl;
			}

		}
		pSlot_ temp_curr = curr;
		curr = curr->next;
		free(temp_curr->address);
		free(temp_curr);

	}

	for (size_t i = 0; i < have_pool; i++)
	{
		_Ty * pBuffer = (_Ty *)(*(int *)((ULONG)have_Slots + i * 4));
		pBuffer->~_Ty();
		free((void*)pBuffer);
	}
	free(have_Block);
	free(have_Slots);
	free(free_Slots);
}

template<typename _Ty>
inline _Ty * hMemPool<_Ty>::alloc()
{
	return new_pool();
}

template<typename _Ty>
inline void hMemPool<_Ty>::Free(_Ty * pBuffer)
{
	return delete_pool(pBuffer);
}

struct MyStruct
{

	int is;
	MyStruct() {
		is = 5;
		//printf("22222\r\n");
	}
	~MyStruct() {
		is = 0;
		//printf("11111\r\n");
	}

};

template<typename _Ty>
inline _Ty * hMemPool<_Ty>::new_pool()
{
	_Ty * TempBuffer = 0;
	if (free_pool != 0) {
		free_pool--;
		int * pBuffer = (int *)((uint32_t)free_Slots + free_pool * 4);
		TempBuffer = new ((void *)*pBuffer)_Ty();
		return TempBuffer;
		// 如果内存池里面又数据  你就在这里把以前用过的返回过去    记得调用初始化函数
	}
	void * pBuffer = nullptr;
	try {
		if (apply_Size == 0) pBuffer = malloc(sizeof(_Ty));
		else pBuffer = malloc(apply_Size);
		
	}
	catch (const std::exception&)
	{
		return nullptr;
	}

	if (pBuffer != 0) {
		TempBuffer = new (pBuffer)_Ty();
	}  // 根据已经分配的内存调用初始化函数
	else {
		return nullptr;
	}

	if (have_pool >= Max_Size)
	{
		have_Slots = malloc(Max_Size * 4);
		memset(have_Slots, 0, Max_Size * 4);
		pSlot_ tmephave_Block = (pSlot_)malloc(sizeof(Slot_));
		tmephave_Block->address = have_Slots;
		tmephave_Block->next = 0;
		have_Block->next = tmephave_Block;
		have_Block = tmephave_Block;
		have_pool = 0;
	}

	memcpy((void *)((uint32_t)have_Slots + have_pool * 4), &pBuffer, 4);
	have_pool++;
	return TempBuffer;
	//placement new
}

template<typename _Ty>
inline void hMemPool<_Ty>::delete_pool(_Ty * pBuffer)


{
	if (pBuffer == 0)
		return;
	//	添加指针 到一个地方 下次申请的时候再用
	pBuffer->~_Ty();
	if (free_pool < Max_Size)
	{
		memcpy((void *)((uint32_t)free_Slots + free_pool * 4), &pBuffer, 4);
		free_pool++;
	}
	else
	{
		//如果超过一页最大内存，就不处理，等待析构的时候去销毁掉;
		//free(pBuffer);
	}



}



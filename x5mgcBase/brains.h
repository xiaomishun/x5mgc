#pragma once
//#include <afxwin.h>

#define SAFE_DEL(X) if (X != NULL) delete X;
#define SAFE_DELARRY(X) if (X != NULL) delete [] X;
#define INITIAL_VALUE   1
template<typename T> 
class brains
{
private:
	T * Val = NULL;        // 用户不能操作
	int * nTimes = NULL;
	size_t nSize = NULL;
	size_t nLen = NULL;
public:
	~brains(); 
	brains();
	brains(const T * _Val, size_t _nLen); 
	brains(size_t Size); 
	brains(const brains<T>& nVal); // 初始化时只拷贝数据
	//   ------------- operator 
	T * operator & ();
	T& operator[](int nArry) const;
	void operator =(const brains<T>& nVal);// 这只是指针的复制
	brains<T> operator +(brains<T> nVal);
	void operator +=(brains<T> nVal);      //     //brains<T> 
	BOOL operator == (brains<T> nVal);
	brains<T> operator<<(int nVal); //Get left value
	brains<T> operator>>(int nVal);//get right value
	//---------------------- Get Val
	virtual const T * getBuffer() { return Val; }
	virtual size_t getSize() { return nSize; }
	virtual size_t Size() { return nSize; }
	virtual size_t getLength() { return nLen; }
	virtual size_t Len() { return nLen; }
	virtual void ZeroVal();// 清空该数据
private:
	void set_nTimes(int _nTimes);
	void Add_nTimes(int * nTimesVal);
    void Sub_nTimes(int * nTimesVal);
	int get_nTimes();
	void ZeroBranis();
	
};

template<typename T>
inline brains<T>::brains()
{

}

template<typename T>
inline brains<T>::~brains()
{
	ZeroVal();
}

template<typename T>
inline brains<T>::brains(const T * _Val, size_t Size) : nSize(Size), nLen(Size * sizeof(T))
{
    // 多申请一个T 照顾Char 文本结束符
	Val = new T[Size + 1];
	SecureZeroMemory(Val, (Size + 1) * sizeof(T));
	memcpy(Val, _Val, Size * sizeof(T));
	set_nTimes(INITIAL_VALUE);
}

template<typename T>
inline brains<T>::brains(size_t Size) : nSize(Size), nLen(Size * sizeof(T)) //不能置0
{
	Val = new T[Size + 1];
	SecureZeroMemory(Val + Size, sizeof(T));
	set_nTimes(INITIAL_VALUE);
}

template<typename T>
inline brains<T>::brains(const brains<T>& nVal){
	/*brains<T>::brains(nVal.Val, nVal.nLen);*/
	brains<T>::~brains();
	memcpy(this, &nVal, sizeof(brains<T>));
	Add_nTimes(nTimes);
}

template<typename T>
inline T * brains<T>::operator&(){
	return Val;
}


template<typename T>
inline T & brains<T>::operator[](int nArry) const{
	return Val[nArry];
}

template<typename T>
inline void brains<T>::operator=(const brains<T>& nVal){
	brains<T>::~brains();
	memcpy(this, &nVal, sizeof(brains<T>));
	Add_nTimes(nTimes);
}

template<typename T>
inline brains<T> brains<T>::operator+(brains<T> nVal){
	brains<T> rBrans(nLen + nVal.nLen);
	//ZeroMemory(rBrans.Val, rBrans.nLen + sizeof(brains<T>));会自动初始化
	if (nLen != NULL)
		memcpy(rBrans.Val, Val, nLen);
	if (nVal.nLen != NULL)
		memcpy(rBrans.Val + nSize, nVal.Val, nVal.nLen);
	return rBrans;
}

template<typename T>
inline void brains<T>::operator+=(brains<T> _Val){ // 只是减少了代码量 没有任何意义{
	brains<T> rBrans(nLen + _Val.nLen);
	if (nLen != NULL)
		memcpy(rBrans.Val, Val, nLen);
	if (_Val.nLen != NULL)
		memcpy(rBrans.Val + nSize, _Val.Val, _Val.nLen);
	*this = rBrans;
}

template<typename T>
inline BOOL brains<T>::operator==(brains<T> _Val){
	if (nLen != _Val.nLen)
		return FALSE;
	if (nLen == NULL)
		return TRUE;
	for (size_t i = NULL; i < nLen; i++)
		if (Val[i] != _Val[i])
			return FALSE;
	return TRUE;
}

template<typename T>
inline brains<T> brains<T>::operator<<(int _Val){ // 取左边的数据 _Val 代表多少组

	brains<T> _brains(Val, sizeof(T)*_Val);
	return _brains;
}

template<typename T>
inline brains<T> brains<T>::operator>>(int _Val){
	brains<T> _brains(Val + (nSize - _Val), sizeof(T)*_Val);
	return _brains;
}

template<typename T>
inline void brains<T>::set_nTimes(int _nTimes){
	if (nTimes == NULL)
		nTimes = new int;
	*nTimes = _nTimes;
}

template<typename T>
inline void brains<T>::Add_nTimes(int * nTimesVal){
	if (nTimesVal != NULL)
		++*nTimesVal;
}

template<typename T>
inline void brains<T>::Sub_nTimes(int * nTimesVal){
	if (nTimesVal != NULL)
		--*nTimesVal;
}

template<typename T>
inline int brains<T>::get_nTimes(){
	if (nTimes == NULL)
		return NULL;
	return *nTimes;
}

template<typename T>
inline void brains<T>::ZeroBranis(){
	SAFE_DELARRY(Val); SAFE_DEL(nTimes);
}

template<typename T>
inline void brains<T>::ZeroVal(){
	if (nTimes != NULL) 
	{
		Sub_nTimes(nTimes);
		if (get_nTimes() == NULL)
			ZeroBranis();
	}
	Val = NULL; nTimes = NULL;
	nLen = NULL; nSize = NULL;
}

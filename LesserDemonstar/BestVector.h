#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

template <class T>
class BestVector
{
private:
	std::vector<T> data;
public:
	BestVector();
	void operator +=(T);
	void operator -=(T);
	T operator [](int);
	int operator()();
	void pop_back();
	T back();
};

template<class T>
inline BestVector<T>::BestVector()
{
	data.clear();
}

template<class T>
inline void BestVector<T>::operator+=(T a)
{
	data.push_back(a);
}

template<class T>
inline void BestVector<T>::operator-=(T a)
{
	for (int i = 0; i < (int)data.size(); i++) {
		if (data[i] == a) {
			data.erase(data.begin() + i);
			return;
		}
	}
}

template<class T>
inline T BestVector<T>::operator[](int x)
{
	return data[x];
}

template<class T>
inline int BestVector<T>::operator()()
{
	return data.size();
}

template<class T>
inline void BestVector<T>::pop_back()
{
	this->data.pop_back();
}

template<class T>
inline T BestVector<T>::back()
{
	return this->data.back();
}

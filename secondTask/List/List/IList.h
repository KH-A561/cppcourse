#pragma once
#include "IIterator.h"

template<typename T>
class IList 
{
public:
	//virtual ~IList() = 0;

	virtual void push(T& elem) = 0;
	virtual void remove() = 0;
	virtual IIterator<T>* listIterator(T elem) = 0;
	virtual void clear() = 0;
	virtual bool isEmpty() = 0;
	virtual int getSize() = 0;
	virtual IIterator<T>* iterator() = 0;
};


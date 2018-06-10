#include "stdafx.h"

template<typename T>
class IList
{
public:
	virtual ~IList() = 0;

	virtual void push(T elem) = 0;
	virtual void remove() = 0;
	virtual Iterator<T> listIterator(T elem) = 0;
	virtual void clear() = 0;
	virtual bool isEmpty() = 0;
	virtual int size() = 0;
	virtual Iterator<T> iterator() = 0;
};
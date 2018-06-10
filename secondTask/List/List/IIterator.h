#pragma once

template<typename T>
class IIterator
{
public:
	virtual void start() = 0;
	virtual T get() = 0;
	virtual void next() = 0;
	virtual bool hasNext() = 0;
};

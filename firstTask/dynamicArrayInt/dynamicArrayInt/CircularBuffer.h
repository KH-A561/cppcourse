#pragma once
#include "DynamicArrayInt.h"

class CircularBuffer
{
private:
	DynamicArrayInt* data;
	int head;
	int tail;

public:
	CircularBuffer();

	CircularBuffer(int& size);

	void push(int& element);

	int getSize();

	int pull();

	int top();

	void makeEmpty();

	bool isEmpty();

	~CircularBuffer();
};


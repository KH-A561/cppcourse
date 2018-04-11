#pragma once
#include "DynamicArrayInt.h"

class CircularBuffer
{
private:
	DynamicArrayInt* data;
	int head;
	int tail;
	int length;

public:
	CircularBuffer();

	CircularBuffer(int size);

	void push(int element);

	int getLength();

	int pull();

	int top();

	void makeEmpty();

	bool isEmpty();

	~CircularBuffer();
};


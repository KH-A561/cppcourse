// ConsoleApplication6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "DynamicArrayInt.h"
#include "CircularBuffer.h"
#include "BufferIterator.h"



int main()
{
	DynamicArrayInt *arrayFive = new DynamicArrayInt(5, 5);
	DynamicArrayInt *arrayThree = new DynamicArrayInt(3, 3);
	DynamicArrayInt *arrayConcat = arrayFive + arrayThree;
	return 0;
}


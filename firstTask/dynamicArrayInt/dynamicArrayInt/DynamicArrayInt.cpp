#include "stdafx.h"
#include "DynamicArrayInt.h"
#include <stdexcept>
#include <stdio.h>

#define PRINTER(Variable) (#Variable)


DynamicArrayInt::DynamicArrayInt()
{
	this->size = 0;
	this->array = new int[0];
}

DynamicArrayInt::DynamicArrayInt(int size)
{
	this->size = size;
	this->array = new int[size];
}

DynamicArrayInt::DynamicArrayInt(int size, int n)
{
	this->size = size;
	this->array = new int[size];
	for (int i = 0; i < size; i++)
	{
		this->array[i] = n;
	}
}

DynamicArrayInt::DynamicArrayInt(DynamicArrayInt &arrayCopy)
{
	this->size = arrayCopy.size;
	this->array = new int[arrayCopy.size];
	for (int i = 0; i < arrayCopy.size; i++)
	{
		this->array[i] = arrayCopy.array[i];
	}
}

DynamicArrayInt::DynamicArrayInt(DynamicArrayInt &&arrayTransfer)
{
	this->size = arrayTransfer.size;
	this->array = new int[arrayTransfer.size];
	for (int i = 0; i < arrayTransfer.size; i++)
	{
		this->array[i] = arrayTransfer.array[i];
	}
	arrayTransfer.size = NULL;
	arrayTransfer.array = nullptr;
}

DynamicArrayInt::~DynamicArrayInt()
{
	delete[] this->array;
}

int DynamicArrayInt::length()
{
	return this->size;
}

int & DynamicArrayInt::operator[](int i)
{
	return this->array[i];
}

void DynamicArrayInt::resize(int newSize)
{
	int *newArray = new int[newSize];
	for (int i = 0; i < newSize; i++)
	{
		newArray[i] = this->array[i];
	}
	if (newSize > this->size) {
		for (int i = this->size; i < newSize; i++)
		{
			newArray[i] = 0;
		}
	}
	delete[] this->array;
	this->array = newArray;
	this->size = newSize;
}

DynamicArrayInt& DynamicArrayInt::operator=(const DynamicArrayInt& secondArr)
{
	delete[] array;
	this->array = new int[secondArr.size];
	for (int i = 0; i < secondArr.size; i++) {
		this->array[i] = secondArr.array[i];
	}
	this->size = secondArr.size;
	return *this;
}

DynamicArrayInt & DynamicArrayInt::operator=(DynamicArrayInt && secondArr)
{
	if (this != &secondArr) {
		delete[] this->array;
		this->size = secondArr.size;
		for (int i = 0; i < secondArr.size; i++)
		{
			this->array[i] = secondArr.array[i];
		}
		secondArr.size = 0;
		secondArr.array = nullptr;
	}
	return *this;
}

const bool operator==(const DynamicArrayInt& firstArr, const DynamicArrayInt& secondArr)
{
	if (firstArr.size != secondArr.size) throw new std::invalid_argument("Array lengths are unequal");
	for (int i = 0; i < secondArr.size; i++) {
		if (firstArr.array[i] != secondArr.array[i]) { return false; }
	}
	return true;
}

const bool operator!=(const DynamicArrayInt& firstArr, const DynamicArrayInt& secondArr)
{
	if (firstArr.size != secondArr.size) throw new std::invalid_argument("Array lengths are unequal");
	for (int i = 0; i < secondArr.size; i++) {
		if (firstArr.array[i] == secondArr.array[i]) { return false; }
	}
	return true;
}

const bool operator<(const DynamicArrayInt& firstArr, const DynamicArrayInt& secondArr)
{
	if (firstArr == secondArr) return false;
	int n = firstArr.size > secondArr.size ? secondArr.size : firstArr.size;
	for (int i = 0; i < n; i++) {
		if (firstArr.array[i] < secondArr.array[i]) { return true; }
		if (firstArr.array[i] > secondArr.array[i]) { return false; }
	}
	if (firstArr.size < secondArr.size) { return true; }
	return false;
}

const bool operator>(const DynamicArrayInt& firstArr, const DynamicArrayInt& secondArr)
{
	if (firstArr == secondArr) return false;
	int n = firstArr.size > secondArr.size ? secondArr.size : firstArr.size;
	for (int i = 0; i < n; i++) {
		if (firstArr.array[i] < secondArr.array[i]) { return false; }
		if (firstArr.array[i] > secondArr.array[i]) { return true; }
	}
	if (firstArr.size > secondArr.size) { return true; }
	return false;
}

const bool operator<=(const DynamicArrayInt& firstArr, const DynamicArrayInt& secondArr)
{
	if (firstArr == secondArr) return true;
	int n = firstArr.size > secondArr.size ? secondArr.size : firstArr.size;
	for (int i = 0; i < n; i++) {
		if (firstArr.array[i] < secondArr.array[i]) { return true; }
		if (firstArr.array[i] > secondArr.array[i]) { return false; }
	}
	if (firstArr.size <= secondArr.size) { return true; }
	return false;
}

const bool operator>=(const DynamicArrayInt& firstArr, const DynamicArrayInt& secondArr)
{
	if (firstArr == secondArr) return true;
	int n = firstArr.size > secondArr.size ? secondArr.size : firstArr.size;
	for (int i = 0; i < n; i++) {
		if (firstArr.array[i] < secondArr.array[i]) { return false; }
		if (firstArr.array[i] > secondArr.array[i]) { return true; }
	}
	if (firstArr.size >= secondArr.size) { return true; }
	return false;
}

const DynamicArrayInt& operator+(const DynamicArrayInt& firstArr, const DynamicArrayInt& secondArr)
{
	DynamicArrayInt *newArr = new DynamicArrayInt(firstArr.size + secondArr.size);
	newArr->size = firstArr.size + secondArr.size;
	for (int i = 0; i < firstArr.size; i++) {
		newArr->array[i] = firstArr.array[i];
	}
	for (int i = 0; i < secondArr.size; i++) {
		newArr->array[firstArr.size + i] = secondArr.array[i];
	}
	return *newArr;
}

std::istream & operator>> (std::istream & inStream, DynamicArrayInt & inArr)
{
	std::cout << "Enter a size of the array: ";
	std::cin >> inArr.size;
	std::cout << "\n";
	for (int i = 0; i < inArr.size; i++)
	{
		std::cout << "Enter an element of the array: ";
		std::cin >> inArr.array[i];
		std::cout << "\n";
	}
	std::cout << std::endl;
	return inStream;
}



std::ostream & operator<< (std::ostream & outStream, DynamicArrayInt & outArr)
{
	outStream << PRINTER(outArr) << ":" << " [";
	for (int i = 0; i < outArr.length() - 1; i++)
	{
		outStream << outArr[i] << ", ";
	}
	outStream << outArr[outArr.length() - 1] << "]" << std::endl;
	return outStream;
}

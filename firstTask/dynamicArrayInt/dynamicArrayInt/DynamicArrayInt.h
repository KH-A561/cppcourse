#pragma once
#include <iostream>


class DynamicArrayInt
{
private:
	int size;
	int* array;

public:
	DynamicArrayInt();

	DynamicArrayInt(int size);

	DynamicArrayInt(int size, int n);

	DynamicArrayInt(DynamicArrayInt &arrayCopy);

	DynamicArrayInt(DynamicArrayInt &&arrayTransfer);

	~DynamicArrayInt();

	int length();

	int& operator [] (int i);

	void resize(int newSize);

	DynamicArrayInt& DynamicArrayInt::operator=(const DynamicArrayInt& secondArr);

	DynamicArrayInt& DynamicArrayInt::operator=(DynamicArrayInt&& secondArr);

	friend const bool DynamicArrayInt::operator==(const DynamicArrayInt& firstArr, const DynamicArrayInt& secondArr);

	friend const bool DynamicArrayInt::operator!=(const DynamicArrayInt& firstArr, const DynamicArrayInt& secondArr);

	friend const bool DynamicArrayInt::operator<(const DynamicArrayInt& firstArr, const DynamicArrayInt& secondArr);

	friend const bool DynamicArrayInt::operator>(const DynamicArrayInt& firstArr, const DynamicArrayInt& secondArr);

	friend const bool DynamicArrayInt::operator<=(const DynamicArrayInt& firstArr, const DynamicArrayInt& secondArr);

	friend const bool DynamicArrayInt::operator>=(const DynamicArrayInt& firstArr, const DynamicArrayInt& secondArr);

	friend DynamicArrayInt& DynamicArrayInt::operator+(DynamicArrayInt& firstArr, DynamicArrayInt& secondArr);

	friend std::istream& operator >> (std::istream& inStream, DynamicArrayInt& inArr);

	friend std::ostream& operator << (std::ostream& outStream, const DynamicArrayInt& outArr);
	
};


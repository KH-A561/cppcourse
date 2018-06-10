// List.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "IList.h"
#include "DoublyLinkedCircularList.h"
#include "DoublyLinkedCircularList.cpp"

int main()
{
	char symbol = 'a';
	IList<char>* list = new DoublyLinkedCircularList<char>(symbol);
	std::cout << list->getSize() << std::endl;
	try {
		IIterator<char>* iter = list->iterator();
		iter->start();
		symbol = 'b';
		list->push(symbol);
	}
	catch (std::invalid_argument e) {
		std::cerr << e.what();
	}
	std::cout << list->getSize() << std::endl;
	_getch();
    return 0;
}


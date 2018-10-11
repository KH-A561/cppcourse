#include <iostream>
#include "IList.h"
#include "DoublyLinkedCircularList.h"
#include "DoublyLinkedCircularList.cpp"

int main() {
  char symbol = 'a';
  IList<char>* list = new DoublyLinkedCircularList<char>();
  std::cout << list->getSize() << std::endl; // '' size: 0
  try {
    list->push(symbol);
    symbol = 'b';
    list->push(symbol);
    symbol = 'c';
    list->push(symbol);
    list->push(symbol);
    std::cout << list->getSize() << std::endl; // 'abcc' size: 4
    list->remove();
    std::cout << list->getSize() << std::endl; // 'abc' size: 3
    list->toString();

    symbol = 'b';
    IIterator<char>* iter = list->listIterator(symbol); // 'ab_c' _ - iterator pointer
    symbol = 'd';
    list->push(symbol);
    list->toString(); // 'abdc' size: 4

    list->clear();
    std::cout << list->getSize() << std::endl; // ' ', size: 0
  }
  catch (std::invalid_argument e) {
    std::cerr << e.what();
  }
  return 0;
}
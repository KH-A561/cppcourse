#include <iostream>
#include "HashTable.cpp"

int main() {
  HashTable<int,int> table;
  table.insert(1, 5);
  table.insert(2, 4);
  table.insert(3, 3);
  table.insert(4, 2);
  table.insert(5, 1);

  std::cout << table.get(1) << std::endl;
  std::cout << table.get(2) << std::endl;
  std::cout << table.get(3) << std::endl;
  std::cout << table.get(4) << std::endl;
  std::cout << table.get(5) << std::endl;
  std::cout << "Length: " << table.getLength() << std::endl;
  table.remove(3);

  HashTable<int, int>::Iterator iterator = table.iterator();
  while (iterator.hasNext()) {
    std::cout << iterator.next() << std::endl;
  }

  std::cout << "Length: " << table.getLength() << std::endl;
  table.removeAll();
  std::cout << "Table is empty: " << table.isEmpty() << std::endl;
  return 0;
}
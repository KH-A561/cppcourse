#include <iostream>
#include <iomanip>
#include "BinaryTree.h"

int main() {
  BinaryTree firstTree(5);
  BinaryTree secondTree(firstTree);
  secondTree.insert(1, "0");
  secondTree.insert(12, "00");
  secondTree.insert(-3, "001");
  secondTree.insert(6, "0010");
  secondTree.insert(9, "00101");
  secondTree.insert(0, "1");
  secondTree.insert(-5, "10");
  secondTree.insert(81, "101");
  secondTree.insert(14, "11");
  secondTree.insert(7, "111");
  secondTree.insert(-30, "1110");
  std::cout << secondTree << std::endl;
  std::cout << "Number of even elements in the tree is: " << secondTree.numberOfEvenKeys() << std::endl;
  std::cout << std::endl;
  std::cout << "Tree is positive: " << secondTree.isTreePositive() << std::endl;
  std::cout << std::endl;

  std::vector<int> vec1 = secondTree.getPath(6);
  std::vector<int> vec2 = secondTree.getPath(81);

  secondTree.cutLeaves();
  std::cout << "Leaves have been cut!" << std::endl;
  std::cout << secondTree << std::endl;
  std::cout << "Average of elements of the tree is: "  << std::fixed << std::setprecision(3) << secondTree.getAverage() << std::endl;

  return 0;
}
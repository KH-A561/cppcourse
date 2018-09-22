#include <iostream>
#include "WordTree.cpp"
int main() {
  const char* text = "a aa bb ab ba a b bb ca a ab";
  WordTree tree(text);
  std::cout << tree << std::endl;
  tree.removeWord("bb");
  tree.removeWord("b");
  tree.removeWord("aa");
  tree.removeWord("bb");
  tree.addWord("caa");
  std::cout << tree.getNumberOfWords() << std::endl;
  std::cout << tree;
  return 0;
}
//
// Created by alexander on 26.06.18.
//

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H

#include <iostream>
#include <vector>
#include <algorithm>

class BinaryTree {
 private:
  struct Node {
    int key;
    Node *leftPtr;
    Node *rightPtr;
    Node *parent;
    explicit Node(int key = -1) : key(key), parent(nullptr), leftPtr(nullptr), rightPtr(nullptr) {}
    Node(const Node &copy) : key(copy.key), parent(nullptr), leftPtr(nullptr), rightPtr(nullptr) {
      if (copy.rightPtr) {
        this->rightPtr = new Node(*copy.rightPtr);
      }
      if (copy.leftPtr) {
        this->leftPtr = new Node(*copy.leftPtr);
      }
    }
    ~Node() {
      key = 0;
      delete leftPtr;
      delete rightPtr;
    }
    static std::ostream &print(std::ostream &os, Node *node, int space) {
      if (node == nullptr) {
        return os;
      }
      for (int i = 0; i < space; i++) {
        os << " ";
      }
      if (node->leftPtr) {
        print(os, node->leftPtr, space + 1);
      }
      os << node->key << std::endl;
      if (node->rightPtr) {
        print(os, node->rightPtr, space + 1);
      }
      return os;
    }
    static int getNumberOfEvenKeysOnBranch(Node *node) {
      int result = 0;
      if (node->key % 2 == 0) {
        result++;
      }
      if (node->rightPtr) {
        result += getNumberOfEvenKeysOnBranch(node->rightPtr);
      }
      if (node->leftPtr) {
        result += getNumberOfEvenKeysOnBranch(node->leftPtr);
      }
      return result;
    }
    static bool isBranchPositive(Node *node) {
      bool result = true;
      if (node->key >= 0) {
        if (node->rightPtr) {
          result = isBranchPositive(node->rightPtr);
          if (!result) return false;
        }
        if (node->leftPtr) {
          result = isBranchPositive(node->leftPtr);
          if (!result) return false;
        }
      } else {
        return false;
      }
      return result;
    }
    static void cutLeavesOnBranch(Node *node, Node *parent) {
      if (!node->leftPtr && !node->rightPtr) {
        if (parent->leftPtr == node) {
          parent->leftPtr = nullptr;
        } else {
          parent->rightPtr = nullptr;
        }
      }
      if (node->leftPtr) {
        cutLeavesOnBranch(node->leftPtr, node);
      }
      if (node->rightPtr) {
        cutLeavesOnBranch(node->rightPtr, node);
      }
    }
    static int getNumberOfNodesOnBranch(Node *node) {
      int count = 0;
      count++;
      if (node->leftPtr) {
        count += getNumberOfNodesOnBranch(node->leftPtr);
      }
      if (node->rightPtr) {
        count += getNumberOfNodesOnBranch(node->rightPtr);
      }
      return count;
    }

    static int getSumOfBranch(Node *node) {
      int result = 0;
      result += node->key;
      if (node->leftPtr) {
        result += getSumOfBranch(node->leftPtr);
      }
      if (node->rightPtr) {
        result += getSumOfBranch(node->rightPtr);
      }
      return result;
    }

    static Node *findNodeByElem(Node *node, int elem) {
      Node *result = nullptr;
      if (node->key == elem) {
        return node;
      } else {
        if (node->leftPtr) {
          result = findNodeByElem(node->leftPtr, elem);
          if (result != nullptr) {
            return result;
          }
        }
        if (node->rightPtr) {
          result = findNodeByElem(node->rightPtr, elem);
          if (result != nullptr) {
            return result;
          }
        }
        return result;
      }
    }
    std::vector<int> getPathToNode(int elem) {
      std::vector<int> reversePath;
      Node* currentNode = Node::findNodeByElem(this, elem);
      if (currentNode == nullptr && this->key != elem) {
        throw std::invalid_argument("Element not found");
      } else if (this->key == elem) {
        return reversePath;
      }
      while (currentNode->parent != nullptr) {
        if (currentNode->parent->leftPtr == currentNode) {
          reversePath.push_back(0);
          currentNode = currentNode->parent;
        } else {
          reversePath.push_back(1);
          currentNode = currentNode->parent;
        }
      }
      std::reverse(reversePath.begin(), reversePath.end());
      return reversePath;
    }
  };
  Node *root;

 public:
  explicit BinaryTree(int root = 0);
  BinaryTree(const BinaryTree &copy);
  ~BinaryTree();

  void insert(int x, const char *path);
  friend std::ostream &operator<<(std::ostream &out, const BinaryTree &tree);
  int numberOfEvenKeys();
  bool isTreePositive();
  void cutLeaves();
  float getAverage();
  std::vector<int> getPath(int elem);
};

#endif //BINARYTREE_BINARYTREE_H

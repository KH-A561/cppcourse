//
// Created by alexander on 26.06.18.
//

#include "BinaryTree.h"
#include <cstring>

BinaryTree::BinaryTree(int root) {
  this->root = new Node(root);
}

BinaryTree::BinaryTree(const BinaryTree &copy) {
  if (&copy == nullptr) {
    return;
  }
  this->root = new Node(*copy.root);
}

BinaryTree::~BinaryTree() {
  delete this->root;
}

void BinaryTree::insert(int x, const char *path) {
  Node *current = this->root;
  if (path == nullptr || path[0] == '\0') {
    throw std::invalid_argument("The path is invalid");
  }
  if (strlen(path) > 1) {
    for (int i = 0; i <= strlen(path) - 2; i++) {
      if (path[i] == '0') {
        current->leftPtr->parent = current;
        current = current->leftPtr;
      } else if (path[i] == '1') {
        current->rightPtr->parent = current;
        current = current->rightPtr;
      } else {
        throw std::invalid_argument("Path has to be a sequence of 'ones' and 'zeroes'.");
      }
      if (current == nullptr) {
        throw std::invalid_argument("The path is invalid");
      }
    }
  }
  if (path[strlen(path) - 1] == '0') {
    if (current->leftPtr == nullptr) {
      current->leftPtr = new Node(x);
      current->leftPtr->parent = current;
    } else {
      current->leftPtr->key = x;
    }
  } else if (path[strlen(path) - 1] == '1') {
    if (current->rightPtr == nullptr) {
      current->rightPtr = new Node(x);
      current->rightPtr->parent = current;
    } else {
      current->rightPtr->key = x;
    }
  } else {
    throw std::invalid_argument("Path has to be a sequence of 'ones' and 'zeroes'.");
  }
}

std::ostream &operator<<(std::ostream &out, const BinaryTree &tree) {
  return BinaryTree::Node::print(out, tree.root, 0);
}

int BinaryTree::numberOfEvenKeys() {
  int result = 0;
  return BinaryTree::Node::getNumberOfEvenKeysOnBranch(this->root);
}

bool BinaryTree::isTreePositive() {
  return BinaryTree::Node::isBranchPositive(this->root);
}

void BinaryTree::cutLeaves() {
  if (root->leftPtr || root->rightPtr) {
    BinaryTree::Node::cutLeavesOnBranch(this->root, this->root);
  }
}

float BinaryTree::getAverage() {
  float result =  BinaryTree::Node::getSumOfBranch(this->root);
  result /= BinaryTree::Node::getNumberOfNodesOnBranch(this->root);
  return result;
}

std::vector<int> BinaryTree::getPath(int elem) {
  return root->getPathToNode(elem);
}













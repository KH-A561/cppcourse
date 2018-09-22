//
// Created by alexander on 18.09.18.
//

#include "WordTree.h"
WordTree::WordTree(const char *text) {
  numOfWords = 0;
  std::string textStr(text);
  auto bufStr = textStr.substr(0, textStr.find_first_of(' '));
  if (bufStr.length() > 0) {
    root = new WordNode(bufStr);
    numOfWords++;
    textStr.erase(0, textStr.find_first_of(' ') + 1);
    bufStr.erase();
  } else {
    throw std::invalid_argument("Text should not start from whitespace");
  }
  for (int i = 0; i <= textStr.size(); i++) {
    if (textStr[i] == ' ' || i == textStr.size()) {
      if (bufStr.length() > 0) {
        addWord(bufStr.data());
        bufStr.erase();
      }
    } else {
      bufStr.push_back(textStr[i]);
    }
  }
}

void WordTree::addWord(const char *word) {
  WordTree::WordNode *parent = WordNode::findNode(word, root);
  if (*parent->word == word) {
    parent->numOfOccurrences++;
    numOfWords++;
  } else if (!parent->leftNode && parent->word->compare(word) > 0) {
    parent->leftNode = new WordNode(word);
    numOfWords++;
  } else if (!parent->rightNode && parent->word->compare(word) < 0) {
    parent->rightNode = new WordNode(word);
    numOfWords++;
  }
}

WordTree::~WordTree() {
  delete root;
  numOfWords = 0;
}

int WordTree::getNumberOfWords() {
  return numOfWords;
}

std::ostream &WordTree::inorderPrint(std::ostream &out, const WordTree::WordNode *node) {
  if (!node) return out;
  if (node->leftNode) {
    inorderPrint(out, node->leftNode);
  }
  out << node->word->data() << " : " << node->numOfOccurrences << std::endl;
  if (node->rightNode) {
    inorderPrint(out, node->rightNode);
  }
  return out;
}

std::ostream &operator<<(std::ostream &out, const WordTree &tree) {
  WordTree::inorderPrint(out, tree.root);
}

int WordTree::findWord(const char *word) {
  WordTree::WordNode *parent = WordNode::findNode(word, root);
  if (*parent->word == word) {
    return parent->numOfOccurrences;
  } else {
    return 0;
  }
}

void WordTree::removeWord(const char *word) {
  WordTree::WordNode *node = WordNode::findNode(word, root);
  if (*node->word == word) {
    if (node->numOfOccurrences > 1) {
      node->numOfOccurrences--;
      numOfWords--;
    } else {
      if (!node->leftNode && !node->rightNode) {
        WordTree::WordNode *parent = WordNode::findParent(word, root);
        if (parent->leftNode && *parent->leftNode->word == word) {
          parent->leftNode = nullptr;
        } else if (parent->rightNode && *parent->rightNode->word == word) {
          parent->rightNode = nullptr;
        }
        delete node;
        numOfWords--;
      } else if (!node->leftNode && node->rightNode || node->leftNode && !node->rightNode) {
        WordTree::WordNode *parent = WordNode::findParent(word, root);
        if (parent->leftNode && *parent->leftNode->word == word) {
          if (node->leftNode) {
            parent->leftNode = node->leftNode;
            node->leftNode = nullptr;
            delete node;
            numOfWords--;
          } else {
            parent->leftNode = node->rightNode;
            node->rightNode = nullptr;
            delete node;
            numOfWords--;
          }
        } else if (parent->rightNode && *parent->rightNode->word == word) {
          if (node->leftNode) {
            parent->rightNode = node->leftNode;
            node->leftNode = nullptr;
            delete node;
            numOfWords--;
          } else {
            parent->rightNode = node->rightNode;
            node->rightNode = nullptr;
            delete node;
            numOfWords--;
          }
        }
      } else if (node->leftNode && node->rightNode) {
        if (node->rightNode->leftNode) {
          WordNode *lowestParent = WordNode::findParentOfTheLowest(node->rightNode);
          if (!lowestParent->rightNode) {
            *node->word = lowestParent->word->data();
            node->numOfOccurrences = lowestParent->numOfOccurrences;
            WordNode *leaf = lowestParent->leftNode;
            lowestParent->leftNode = nullptr;
            delete leaf;
            numOfWords--;
          } else {
            *node->word = lowestParent->leftNode->word->data();
            node->numOfOccurrences = lowestParent->leftNode->numOfOccurrences;
            WordNode *buf = lowestParent->leftNode;
            lowestParent->leftNode = lowestParent->leftNode->rightNode;
            buf->rightNode = nullptr;
            delete buf;
            numOfWords--;
          }
        } else {
          *node->word = node->rightNode->word->data();
          node->numOfOccurrences = node->rightNode->numOfOccurrences;
          WordNode *buf = node->rightNode;
          node->rightNode = node->rightNode->rightNode;
          buf->rightNode = nullptr;
          delete buf;
          numOfWords--;
        }
      }
    }
  }
}

WordTree::WordTree(WordTree::WordNode *node) {
  root = node;
  numOfWords = getNumberOfWords(node);
}

int WordTree::getNumberOfWords(WordTree::WordNode *node) {
  int result = 0;
  result += node->numOfOccurrences;
  if (node->leftNode) {
    getNumberOfWords(node->leftNode);
  }
  if (node->rightNode) {
    getNumberOfWords(node->rightNode);
  }
  return result;
}

WordTree::WordTree(WordTree &copy) {
  *this->root = WordNode(*copy.root);
  this->numOfWords = copy.numOfWords;
}


//
// Created by alexander on 18.09.18.
//

#ifndef WORDTREE_WORDTREE_H
#define WORDTREE_WORDTREE_H
#include <string>
#include <algorithm>
#include <stdexcept>

class WordTree {
 public:
  struct WordNode {
    WordNode *leftNode; //before
    WordNode *rightNode; //after
    std::string *word;
    int numOfOccurrences;

    explicit WordNode(const std::string &word = "/0")
        : leftNode(nullptr), rightNode(nullptr), numOfOccurrences(1) {
      this->word = new std::string(word);
    }

    WordNode(const WordNode &copy)
        : leftNode(nullptr), rightNode(nullptr), word(copy.word), numOfOccurrences(copy.numOfOccurrences) {
      if (copy.word) {
        this->word = new std::string(*copy.word);
      }
      if (copy.rightNode) {
        this->rightNode = new WordNode(*copy.rightNode);
      }
      if (copy.leftNode) {
        this->leftNode = new WordNode(*copy.leftNode);
      }
    }

    ~WordNode() {
      delete leftNode;
      delete rightNode;
      delete word;
      numOfOccurrences = 0;
    }

    static WordNode *findNode(const std::string &word, WordNode *currentNode) {
      if (*currentNode->word == word) {
        return currentNode;
      }
      if (currentNode->word->compare(word) > 0) {
        if (!currentNode->leftNode) {
          return currentNode;
        } else {
          findNode(word, currentNode->leftNode);
        }
      } else if (currentNode->word->compare(word) < 0) {
        if (!currentNode->rightNode) {
          return currentNode;
        } else {
          findNode(word, currentNode->rightNode);
        }
      }
    }

    static WordNode *findParent(const std::string &word, WordNode *node) {
      WordNode *buf = nullptr;
      if (node->leftNode || node->rightNode) {
        if (node->leftNode && *node->leftNode->word == word) {
          return node;
        } else if (node->rightNode && *node->rightNode->word == word) {
          return node;
        }
      }
      if (node->leftNode) {
        buf = findParent(word, node->leftNode);
        if (buf != nullptr) {
          return buf;
        }
      }
      if (node->rightNode) {
        buf = findParent(word, node->rightNode);
        if (buf != nullptr) {
          return buf;
        }
      }
      throw std::invalid_argument("Element not found");
    }

    static WordNode *findParentOfTheLowest(WordNode *node) {
      WordNode* buf = node;
      while (buf->leftNode && (buf->leftNode->leftNode != nullptr)) {
        buf = buf->leftNode;
      }
      return buf;
    }
  };
  WordNode *root;
  int numOfWords;

 public:
  explicit WordTree(WordNode *node);
  explicit WordTree(const char *text);
  WordTree(WordTree &copy);
  WordTree& operator=(const WordTree& secondTree);
  ~WordTree();

  int findWord(const char *word);
  void addWord(const char *word);
  void removeWord(const char *word);
  int getNumberOfWords();
  int getNumberOfWords(WordNode *node);
  static std::ostream &inorderPrint(std::ostream &out, const WordNode *node);
  friend std::ostream &operator<<(std::ostream &out, const WordTree &tree);
};

#endif //WORDTREE_WORDTREE_H

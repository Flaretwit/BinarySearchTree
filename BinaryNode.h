#include <iostream>

#ifndef BINARYNODE_h
#define BINARYNODE_h
class BinaryNode {
 public:
  BinaryNode(int newValue);
  BinaryNode();
  ~BinaryNode();
  BinaryNode* getRight();
  BinaryNode* getLeft();
  void setLeft(BinaryNode* newLeft);
  void setRight(BinaryNode* newRight);
  int getValue();
  void setValue(int newvalue);
  BinaryNode* left;
  BinaryNode* right;
 private:

  int value;
};

#endif

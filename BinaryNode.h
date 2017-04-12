#include <iostream>

#ifndef BinaryNODE_H
#define Bino9
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
 private:
  BinaryNode* left;
  BinaryNode* right;
  int value;
};

#endif

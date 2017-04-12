#include <iostream>
#include "BinaryNode.h"
#include <string.h>

using namespace std;

BinaryNode::BinaryNode(){
  left = NULL;
  right = NULL;
}
//intializes the note with a value
BinaryNode::~BinaryNode(int newValue){
  value = newValue
  left = NULL;
  right = NULL;
}

void BinaryNode::setLeft(BinaryNode* newLeft){
  left = newLeft;
}

void BinaryNode::setRight(BinaryNode* newRight){
  right = newRight;
}

BinaryNode* BinaryNode::getLeft(){
  return left;
}

BinaryNode* BinaryNode::getRight(){
  return right;
}

int BinaryNode::getValue(){
  return value;
}

void BinaryNode::setValue(int newvalue){
  value = newvalue;
}

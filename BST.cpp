#include <iostream>
#include <string.h>
#include <stack>
#include "BinaryNode.h"
#include <cstring>
#include <stdlib.h>

insert(BinaryNode* node, BinaryNode *& root);

int main() {

  BinaryNode* root = NULL;
  return 0;
}

void insert(BinaryNode* node, BinaryNode *& root) {
  if(root == NULL) {
    root = node;
    return;
  }
  else if(node->getValue() < root->getValue()) {
      insert(node, root->getLeft());
  }
  else if(node->getValue() >= root->getValue()) {
      insert(node, root->getRight());
  }

}
//removes a node by value in the Binary Search Tree.
void removeNode(int number, BinaryNode *& root) {
  //if current node has value equal to value, deal with removing the Node.
  if(root = NULL) {
    return;
  }
  else if(number < root->getValue()) {
    remove(number, root->getLeft());
  }
  else if(number > root->getValue()) {
    remove(number, root->getRight());
  }
  //then perform upshift operations
  else if(number == root->getValue()) {
    //if the no left or right child
    if(root->getLeft() == NULL && root->getRight() = NULL) {
      delete root;
      root = NULL;
    }
    //if there is a left and right child or just a right child
    else if(root->getRight() != NULL) {
      int tempValue = root->getValue();
      root->setValue(root->getRight()->getValue());
      root->getRight()->setValue(tempValue);
      removeNode(number, root->getRight())
    }
  }
}

//upshifts nodes
upShift()




pr

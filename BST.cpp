#include <iostream>

#include <string.h>
#include <stack>
#include "BinaryNode.h"
#include <cstring>
#include <algorithm>

void insert(int value, BinaryNode *& root);
void removeNode(int number, BinaryNode *& root);
int getDepth(int number, BinaryNode* root);
void printTree(BinaryNode* current, BinaryNode* root);

using namespace std;

int main() {
  BinaryNode* root = NULL;
  char array[500] = "";
  char token[100] = "";

  int arrLength = 0;
  int layer = 0;
  cout << "Enter numbers, each separated by one space (1 2 3 4) " << endl;
  cin.getline(array, 500);
  arrLength = strlen(array);

  //reads the input and inserts each number into the BST
  for(int i = 0; i <= arrLength; i++) {
    if(array[i] != ' ' && array[i] != '\0') {
      //copies the array to the token as long as the element is not a space
      //or null terminator
      strncat(token, &array[i], 1);
    }
    else {
      if(token[0] != ' ' && token[0] != '\0') {
        int temp = atoi(token);
        token[0] = '\0';
        cout << "temp " << temp << endl;
        insert(temp, root);
      }
    }
  }
  cout << "array" << array << endl;
  cout << "root value" << root->getValue() << endl;
//  inorder(root);

  printTree(root, root);

  return 0;
}

void printTree(BinaryNode* current, BinaryNode *root) {
    if (root != NULL)
    {
        printTree(root->getRight(), root);
        int num = getDepth(current->getValue(), root);
        cout << "HEIGHT" << num << flush;
        for(int i = 0; i < num; i++) {
          cout << "\t" << flush;
        }
        cout << current->getValue() << endl;
        printTree(root->getLeft(), root);
    }
}

//inserts a node into the Binary Search Tree, maintaining order.
void insert(int value, BinaryNode*& root) {
    cout << "Looping" << endl;
  if(root == NULL) {
      BinaryNode* node = new BinaryNode(value);
      root = node;
      cout << "finalized" << endl;
      return;
  }
  else if(value < root->getValue()) {
    //Root has no right child
     if(root->getLeft() == NULL){
        BinaryNode* newNode = new BinaryNode();
        newNode->setValue(value);
        root->setLeft(newNode);
     }
     else {
       BinaryNode* temp = root->getLeft();
       insert(value, temp);
       cout << "went to left" << endl;
     }
  }
  else if(value >= root->getValue()) {
    if(root->getRight() == NULL){
       BinaryNode* newNode = new BinaryNode();
       newNode->setValue(value);
       root->setRight(newNode);
    }
    else {
      BinaryNode* temp = root->getRight();
      insert(value, temp);
      cout << "went to right" << endl;
    }
  }
}
//removes a node by value in the Binary Search Tree.
void removeNode(int number, BinaryNode * root) {
  //if current node has value equal to value, deal with removing the Node.
  if(root = NULL) {
    return;
  }
  else if(number < root->getValue()) {
    removeNode(number, root->getLeft());
  }
  else if(number > root->getValue()) {
    removeNode(number, root->getRight());
  }
  //then perform upshift operations
  else if(number == root->getValue()) {
    //if the no left or right child
    if(root->getLeft() == NULL && root->getRight() == NULL) {
      delete root;
      root = NULL;
    }
    //if there is a left and right child or just a right child
    else if(root->getRight() != NULL) {
      int tempValue = root->getValue();
      root->setValue(root->getRight()->getValue());
      root->getRight()->setValue(tempValue);
      removeNode(number, root->getRight());
    }
    //if there is a left child but no right
    else if(root->getRight() == NULL) {
      int tempValue = root->getValue();
      root->setValue(root->getLeft()->getValue());
      root->getLeft()->setValue(root->getValue());
      removeNode(number, root->getLeft());
    }
  }
}

int getDepth(int number, BinaryNode* root) {
  if(root->getValue() == number) {
    return 0;
  }
  else if(number < root->getValue()) {
    return 1 + getDepth(number, root->getLeft());
  }
  else if(number > root->getValue()) {
    return 1 + getDepth(number, root->getRight());
  }
}

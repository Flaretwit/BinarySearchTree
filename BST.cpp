//Binary Search Tree.
//Implementation allows the addition and removal of Nodes containing integers into the BST
//There is also a function that prints the tree.

#define ADD 1
#define REMOVE 2
#define PRINT 3
#define EXIT 4

#include <iostream>
#include <string.h>
#include "BinaryNode.h"
#include <cstring>
#include <algorithm>

void insert(int value, BinaryNode *& root);
BinaryNode* removeNode(int value, BinaryNode *& root);
int getDepth(int level, int number, BinaryNode* root);
void printTree(BinaryNode* current, BinaryNode* root);
int parseCommand(char *input);
BinaryNode* findMin(BinaryNode* root);
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
    //if the array is found to be a space or null terminator,
    //then the token is converted to an integer and inserted into the BST
    else {
      if(token[0] != ' ' && token[0] != '\0') {
        int temp = atoi(token);
        token[0] = '\0';
        insert(temp, root);
      }
    }
  }

  char input[80];
  bool done = false;
  while(!done) {
    cout << "ADD, REMOVE, OR PRINT, OR EXIT?" << endl;
    cin >> input;
    switch(parseCommand(input)) {
      case ADD: {
        char temp[80];
        cout << "Enter an integer: " << flush;
        cin >> temp;
        int num = atoi(temp);
        insert(num, root);
        break;
      }
      case PRINT:
        printTree(root, root);
        break;
      case REMOVE: {
        char temp[80];
        cout << "What number to remove from the BST?" << endl;
        cin >> temp;
        int num = atoi(temp);
        removeNode(num, root);
        break;
      }
      case EXIT:
        done = true;
        break;
    }
  }
  return 0;
}

void printTree(BinaryNode* node, BinaryNode* root)
{
     if (node == NULL)
          return;
     /* first recur on right child */
     printTree(node->right, root);

     int num = getDepth(0, node->getValue(), root);
     for(int i = 0; i < num; i++) {
       cout << "\t" << flush;
     }
     /* then print the data of the node */
     cout << " " << node->getValue() << endl;

     /* now recur on left child */
     printTree(node->left, root);
}


//inserts a node into the Binary Search Tree, maintaining order.
void insert(int value, BinaryNode*& root) {
  if(root == NULL) {
      BinaryNode* node = new BinaryNode(value);
      root = node;
      return;
  }
  else if(value < root->getValue()) {
    //Root has no right childb
     if(root->getLeft() == NULL){
        BinaryNode* newNode = new BinaryNode();
        newNode->setValue(value);
        root->setLeft(newNode);
     }
     else {
       BinaryNode* temp = root->getLeft();
       insert(value, temp);
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
    }
  }
}

//finds minimum node greater than the current node (for two children node deletion)
BinaryNode* findMin(BinaryNode* root) {
  while(root->left != NULL) {
    root = root->left;
  }
  return root;
}
//removes a node by value in the Binary Search Tree... completely recursively!
BinaryNode* removeNode(int value, BinaryNode *& root) {
  //if root is NULL e.g. tree is empty, exit immediately
  if(root == NULL) {
    return root;
  }
  else if(value < root->value) {
    root->left = removeNode(value, root->left);
  }
  else if(value > root->value) {
    root->right = removeNode(value, root->right);
  }
  else {
    //Case 1: No child
    if(root->left == NULL && root->right == NULL) {
        delete root;
        root = NULL;
    }
    //Case 2: One child
    else if(root->left == NULL) {
      BinaryNode* temp = root;
      root = root->right;
      delete temp;
    }
    else if(root->right == NULL) {
      BinaryNode* temp = root;
      root = root->left;
      delete temp;
    }
    //Case 3: Two children
    else {
      //first copy the value of the minimum node that was larger than the node to be deleted
      //then perform a delete operation on that minimum node
      //because we made sure it only had a maximum of 1 child, deleting it will be simple
      BinaryNode* temp = findMin(root->right);
      root->value = temp->value;
      root->right = removeNode(temp->value, root->right);
    }
  }
  return root;
}
//gets depth of a particular number in the BST
int getDepth(int level, int number, BinaryNode* root) {
  if(root == NULL) {
    return 0;
  }
  else if(root->getValue() == number) {
    return level;
  }
  int downLevel = getDepth(level + 1, number, root->getLeft());
  if(downLevel != 0) {
    return downLevel;
  }
  downLevel = getDepth(level + 1, number, root->getRight());
  return downLevel;
}

//compares the input to known commands
int parseCommand(char *input) {
  for(int i = 0; i < strlen(input); i++) {
		input[i] = toupper(input[i]);
	}
	if(!strcmp(input, "ADD")) {
		return ADD;
	}
	else if(!strcmp(input, "PRINT")) {
		return PRINT;
	}
	else if(!strcmp(input, "REMOVE")) {
		return REMOVE;
	}
	else if(!strcmp(input, "EXIT")) {
		return EXIT;
	}
	else {
		return 0;
	}
}

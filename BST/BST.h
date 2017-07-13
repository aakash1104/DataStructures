#ifndef BST_H
#define BST_H
#include <iostream>

class BST;
class Node{
public:
  int data;
  Node *left;
  Node *right;
  Node(int d, Node* l, Node* r): data(d), left(l), right(r){};
  friend class BST;
};

class BST{
public:
  Node *root;
  BST(): root(NULL){};
  void insert(int data);
  void Remove(Node *root, int data);
  void inOrderTraversal(Node *root);
  void preOrderTraversal(Node *root);
  void postOrderTraversal(Node *root);
  void levelOrderTraversal(Node *root);
  int find(Node *root, int data);
private:
  void insertChild(Node *root, int data);
  void removeRoot(Node *root);
  void removeLeafNode(Node *ptr, Node *parent);
  void removeInternalNodeWithOnlyLeftChild(Node *ptr, Node *parent);
  void removeInternalNodeWithOnlyRightChild(Node *ptr, Node *parent);
  void removeInternalNodeWithTwoChildren(Node *ptr, Node *parent);
  Node* MinRightSubTree(Node *root);
  Node* DeleteRootHelper(Node *root);
};

#endif

#include "BST.h"
#include <iostream>
#include <queue> // For level order traversal
using namespace std;

void BST::insert(int data){
  if (root == NULL)
    root = new Node(data, NULL, NULL);
  else
    insertChild(root, data);
} // insert(int data)


void BST::insertChild(Node *root, int data){

  if (data < root->data){
    if (root->left == NULL)
      root->left = new Node(data, NULL, NULL);
    else
      insertChild(root->left, data); // Recurse till we find the left most node!
  } // Go left

  else{
    if (root->right == NULL)
      root->right = new Node(data, NULL , NULL);
    else
      insertChild(root->right, data); // Recurse till we find the right most node!
  } // Go right
} // insertChild()

void BST::inOrderTraversal(Node *root){
  if (root == NULL)
    return;
  else{
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
  } // root not NULL
} // inOrderTraversal(Node *root)

void BST::preOrderTraversal(Node *root){
  if (root == NULL)
    return;
  else {
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
  }
}

void BST::postOrderTraversal(Node *root){
  if (root == NULL)
    return;
  else {
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
  }
}
void BST::levelOrderTraversal(Node *root){
  queue <Node*> Q;
  Node* temp;
  Q.push(root);

  while(!Q.empty()){
    temp = Q.front();
    Q.pop();
    cout << temp->data << " ";
    if (temp->left == NULL && temp->right == NULL) // Hit a leaf
      continue;
    else if (temp->right == NULL && temp->left != NULL) // No right child
      Q.push(temp->left);
    else if (temp->left == NULL && temp->right != NULL) // No left child
      Q.push(temp->right);
    else {
      Q.push(temp->left); // Push the left child before the right child as a convention
      Q.push(temp->right);
    } // Has both left and right children
  } // While Queue not empty
} // levelOrderTraversal(Node *root)

int BST::find(Node *root, int data){
  Node *temp = root;
  while (temp){
    if (data == temp->data) // GOAL
      return data;

    else if (data < temp->data) // Look left
      temp = temp->left;

    else // Look right
      temp = temp->right;
  } // Perform binary search
  return -1; // NOT FOUND
}

Node* BST::MinRightSubTree(Node *root){
  while (root && root->left)
    root = root->left;
  return root;
}

Node* BST::DeleteRootHelper(Node *root){
    Node* parent = NULL;
    while(root && root->left){
      parent = root;
      root = root->left;
    }
    return parent;
}

void BST::removeRoot(Node *root){
  Node *parentOfMinRight;
  root->data = MinRightSubTree(root->right)->data;
  parentOfMinRight = DeleteRootHelper(root->right);
  parentOfMinRight->left = NULL;
}

void BST::removeLeafNode(Node *ptr, Node *parent){
  if (ptr->data < parent->data){
    parent->left = NULL;
    return;
  } // If data is left of parent then lazy delete
  else{
    parent->right = NULL;
    return;
  } // If data is right of parent then lazy delete
}

void BST::removeInternalNodeWithOnlyRightChild(Node *ptr, Node *parent){
  if (ptr->data < parent->data){
    parent->left =  ptr->right;
    return;
  }
  else{
    parent->right = ptr->right;
    return;
  }
}

void BST::removeInternalNodeWithOnlyLeftChild(Node *ptr, Node *parent){
  if (ptr->data < parent->data){
    parent->left = ptr->left;
    return;
  }
  else {
    parent->right = ptr->left;
    return;
  }
}

void BST::removeInternalNodeWithTwoChildren(Node *ptr, Node *parent){
  Node *minRight = MinRightSubTree(ptr->right); // Find the minimum of the right subtree
  if (ptr->data > parent->data){
    parent->right = minRight; // Update pointers
    minRight->left = ptr->left; // Update pointers
    return;
  }
  else{
    parent->left = minRight;
    minRight->left = ptr->left;
    return;
  }
}


void BST::Remove(Node *root, int data){
  // Assuming we're only trying to delete elements that are in the BST
  Node *ptr = root, *parent = NULL;

  if (root->data == data){
    removeRoot(root);
    return;
  } // Delete the root -> Special case

  while (ptr){
    if (data < ptr->data){
      parent = ptr;
      ptr = ptr->left;
    } // Go left

    else if (data > ptr->data){
      parent = ptr;
      ptr = ptr->right;
    } // Go right

    else{
      if (ptr->left == NULL && ptr->right == NULL) {
        removeLeafNode(ptr, parent);
        return;
      }// If leaf node

      else if (ptr->left == NULL) {
        removeInternalNodeWithOnlyRightChild(ptr, parent);
        return;
      } // Only one child (right child)

      else if (ptr->right == NULL){
        removeInternalNodeWithOnlyLeftChild(ptr, parent);
        return;
      } // Only one child (left child)

      else {
        removeInternalNodeWithTwoChildren(ptr, parent);
        return;
      }
    } // data == ptr->data
  } // While ptr
} // remove()

#include "BST.h"
#include <iostream>
using namespace std;

// Driver Program
int main(void){
  BST bst;
  int elements[8] = {10,6,8,4,18,15, 21, 22};
  for (int i = 0; i < 8; i++)
    bst.insert(elements[i]);

  cout << "In Order/BFS Traversal" << endl;
  bst.inOrderTraversal(bst.root);
  cout << endl << endl;

  cout << "Preorder Traversal" << endl;
  bst.preOrderTraversal(bst.root);
  cout << endl << endl;

  cout << "Postorder Traversal" << endl;
  bst.postOrderTraversal(bst.root);
  cout << endl << endl;

  cout << "Level Order Traversal" << endl;
  bst.levelOrderTraversal(bst.root);
  cout << endl << endl;

  cout << "Attempting to find 10: Found " << bst.find(bst.root,10) << endl; // Found
  cout << "Attempting to find 4: Found " << bst.find(bst.root,4) << endl; // Found
  cout << "Attempting to find 15: Found " << bst.find(bst.root,15) << endl; // Found
  cout << "Attempting to find 27: Found " << bst.find(bst.root, 27) << " => NOT FOUND " << endl << endl; // Not Found

  cout << "Removing 18" << endl;
  bst.Remove(bst.root, 18);
  cout << "Level order Traversal of the tree after deleting 18" << endl;
  bst.levelOrderTraversal(bst.root);
  cout << endl;
  return 0;
}

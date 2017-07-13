#include "LinkedList.h"
#include <iostream>

using namespace std;

int main(void){
  LinkedList linkedList;
  cout << "Demonstrating simple inserts into a linked list (unsorted)" << endl;
  linkedList.insert(10);
  linkedList.insert(5);
  linkedList.insert(13);
  linkedList.insert(25);
  linkedList.insert(17);
  linkedList.print();
  cout << endl << "Demonstrating sorted inserts into a linked list" << endl;
  linkedList.~LinkedList();
  linkedList.insertSorted(10);
  linkedList.insertSorted(5);
  linkedList.insertSorted(13);
  linkedList.insertSorted(25);
  linkedList.insertSorted(17);
  linkedList.print();
  cout << endl << "Testing for deletes of a particular element" << endl;
  linkedList.Remove(13);
  linkedList.Remove(5);
  linkedList.print();
  cout << endl;
  return 0;
}

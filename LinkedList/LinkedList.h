#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <cstddef>
class LinkedList;
class ListNode{
public:
  int data;
  ListNode *next;
  ListNode() {};
  ListNode(int d, ListNode *n): data(d), next(n){};
  friend class LinkedList;

}; // class ListNode

class LinkedList{
public:
  ListNode *head;
  LinkedList(): head(NULL){};
  ~LinkedList();
  void insert(int data);
  void insertSorted(int data);
  void Remove(int data);
  void print();
}; // class LinkedList
#endif

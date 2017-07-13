#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::~LinkedList(){

    for (ListNode *ptr = head; ptr; ptr = head){
      head = ptr->next;
      delete ptr;
    }
} // ~LinkedList()

void LinkedList::insert(int data){
  ListNode *ptr = head;
  if (head == NULL) // If Linked List is empty, then insert at the front of the list
    head = new ListNode(data, NULL);

  else {
    while (ptr->next != NULL){
      ptr = ptr->next;
    } // Go to the last position of the linked list
    ptr->next = new ListNode(data, NULL); // Insert data at the back of the list
  } // If linked list is not empty

} // insert(int data)

void LinkedList::insertSorted(int data){
  ListNode *ptr = head, *prev = NULL;
  for (ptr = head; ptr && ptr->data < data; ptr = ptr->next)
    prev = ptr;

  if (!prev) // If prev == NULL then insert at the beginning of the list
    head = new ListNode(data, head);

  else // If pre is not NULL
    prev->next = new ListNode(data, ptr);
}

void LinkedList::Remove(int data){
  ListNode *ptr = head, *prev = NULL;
  for (ptr = head; ptr && ptr->data < data; ptr = ptr->next)
    prev = ptr;
  if (ptr && ptr->data == data){
    if (!prev)
      head = ptr->next;
    else
      prev->next = ptr->next;
    delete ptr;
  }
}

void LinkedList::print() {
  for (ListNode *ptr = head; ptr; ptr = ptr->next)
    cout << ptr->data << " ";
}

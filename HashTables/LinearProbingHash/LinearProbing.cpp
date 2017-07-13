#include "LinearProbing.h"
#include <iostream>
using namespace std;


void initialize(int hashTable[], int TABLE_SIZE){
  for (int i = 0; i < TABLE_SIZE; i++)
    hashTable[i] = 0; // Initialize all our positions to 0. If element at index is 0 => Empty position
} // initialize()

void printHashTable(int hashTable[], int TABLE_SIZE){
    cout << "\t\t\t\t Hash Table " << endl;
    for (int i = 0; i < TABLE_SIZE; i++)
      cout  << i << " ---> " << hashTable[i] << endl;
} // printHashTable()

int* linearProbing(int hashTable[], int TABLE_SIZE, int number){
  bool inserted = false;
  int pos = number % TABLE_SIZE;
  for (int i = pos; i < TABLE_SIZE; i++)
    if (hashTable[i] == 0){
      hashTable[i] = number;
      inserted = true;
      break;
    }
  if (!inserted)
    for (int i = 0; i < pos; i++)
      if (hashTable[i] == 0){
        hashTable[i] = number;
        inserted = true;
        break;
      }
  return hashTable;
} // linearProbing()

void insert(int hashTable[], int TABLE_SIZE, int number){
  if (hashTable[number % TABLE_SIZE] == 0) // If the position is empty -> No collision
    hashTable[number % TABLE_SIZE] = number;

  else // collision
    hashTable = linearProbing(hashTable, TABLE_SIZE, number); // Perform linear probing
} // insert()

int* rehash(int hashTable[], int newTableSize){
  int *temp;
  temp = new int[newTableSize];
  initialize(temp, newTableSize);
  for (int i = 0; i < newTableSize / 2; i++)
    if (hashTable[i] != 0)
      insert(temp, newTableSize, hashTable[i]);
      //temp[hashTable[i] % newTableSize] = hashTable[i];
  hashTable = new int[newTableSize];
  hashTable = temp;
  return hashTable;
} // rehash()

int find(int hashTable[], int TABLE_SIZE, int number){
  // Returns the position of the number in the hashTable, else returns -1
  int hashToPos = number % TABLE_SIZE;
  bool found = false;
  if (hashTable[hashToPos] != number && hashTable[hashToPos] != 0)
    for (int i = hashToPos; i < TABLE_SIZE; i++)
      if (hashTable[i] == number){
          found = true;
          return i; // Return position
      }
  if (hashTable[hashToPos] == number && hashTable[hashToPos] != 0)
        return hashToPos; // FOUND
  if (!found)
    for (int i = 0; i < hashToPos; i++)
      if (hashTable[i] == number){
        found = true;
        return i; // Return postion since we could loop back around;
      }
  return -1; // Else, not found
} // find()

void Remove(int hashTable[], int TABLE_SIZE, int number){
  int pos = find(hashTable, TABLE_SIZE, number);
  if (pos != -1){
    hashTable[pos] = 0; // Setting it to zero -> LAZY DELETE
    Count--; // Decrement count, we don't want to affect loadFactor on a new insert
  } // If we find the number
}

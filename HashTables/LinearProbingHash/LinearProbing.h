#ifndef LINEAR_PROBING_H
  #define LINEAR_PROBING_H

  extern int Count;
  void initialize(int hashTable[], int TABLE_SIZE);
  void printHashTable(int hashTable[], int TABLE_SIZE);
  int* linearProbing(int hashTable[], int TABLE_SIZE, int number);
  void insert(int hashTable[], int TABLE_SIZE, int number);
  int* rehash(int hashTable[], int newTableSize);
  int find(int hashTable[], int TABLE_SIZE, int number);
  void Remove(int hashTable[], int TABLE_SIZE, int number);

#endif

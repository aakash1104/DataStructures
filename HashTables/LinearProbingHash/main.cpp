#include "LinearProbing.h"
#include <fstream>
using namespace std;

int Count = 0;

int main(int argc, char **argv){
  const double loadFactor = 0.75;
  int TABLE_SIZE = 7, number;
  int *hashTable;
  hashTable = new int[TABLE_SIZE]; // Declare an initial size -> Usually a prime number
  initialize(hashTable, TABLE_SIZE); // initialize all elements to 0 -> Empty hash table
  ifstream inf;
  inf.open(argv[1]); // Open test file

  while (inf >> number){
    Count++; // Increment count because we're going to insert element
    // Now, we have to check if adding a new element goes beyond our defined load factor.
    double check = ((Count) / static_cast<double>(TABLE_SIZE)); // Load factor check
    if (check > loadFactor){
      TABLE_SIZE *= 2;
      hashTable = rehash(hashTable, TABLE_SIZE); // Time to rehash
      insert(hashTable, TABLE_SIZE, number); // Insert the new element after rehashing the previous elements
    } // If we exceeded load factor
    else
      insert(hashTable, TABLE_SIZE, number); // We're good to just insert without rehashing
  } // While we still read from the file

  printHashTable(hashTable, TABLE_SIZE);
  return 0;
}

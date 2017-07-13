#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

const int TABLE_SIZE = 37; // Pick a nice prime number :)

void printHashTable(vector <int> HashTable[]){
  for (int i = 0; i < TABLE_SIZE; i++){
    cout << i << " --> ";
    for (vector<int>::iterator it = HashTable[i].begin(); it != HashTable[i].end(); it++)
      cout << *it << " ";
    cout << endl;
  }
} // printHashTable

void insert(vector <int> HashTable[], int number){
  HashTable[number % TABLE_SIZE].push_back(number);
} // insert()

void remove(vector <int> HashTable[], int number){
  HashTable[number % TABLE_SIZE].erase(find(HashTable[number % TABLE_SIZE].begin(),HashTable[number % TABLE_SIZE].end(), number));
} // remove()

int Find(vector <int> HashTable[], int number){
  vector <int>::iterator it = find (HashTable[number % TABLE_SIZE].begin(), HashTable[number % TABLE_SIZE].end(), number);
  if (it != HashTable[number % TABLE_SIZE].end())
    return *it;
  return -1;
} // find()

int main(int argc, char **argv){
  int number;
  vector <int> HashTable[TABLE_SIZE]; // Declare a separate Chaining Hash of siae TABLE_SIZE
  ifstream inf;
  inf.open(argv[1]);

  while (inf >> number)
    insert(HashTable, number);

  printHashTable(HashTable);
  return 0;
}

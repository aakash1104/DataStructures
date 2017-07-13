#include <iostream>
#include <fstream>
#include <random>
using namespace std;

int main(void){
  random_device rd;
  mt19937 gen(rd());
  int n, lowerBound, upperBound;

  cout << "Enter the number of elements >> ";
  cin >> n;
  cout << "You now need to enter the range of numbers to be generated" << endl;
  cout << "Enter a lower bound and an upper bound (lower bound < upper bound) >> ";
  cin >> lowerBound >> upperBound;

  uniform_int_distribution<> dis(lowerBound, upperBound);
  ofstream outf;
  outf.open("TestLinearProbing.txt");

  for (int i = 0; i < n - 1; i++)
    outf << dis(rd) << " ";

  outf << dis(rd);
  outf.close();
  return 0;
}

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int getmedian(int arraysize, int array[1000]){

  sort(array, array+arraysize);
  int median;
  return array[(arraysize-1)/2];
}

int main(){
  string size1;
  int size;
  getline(cin, size1);
  stringstream x(size1);
  x >> size;
  int medians[1000];
  int array[1000];
  for (int i = 0; i < size; i++){
    string line;
    getline(cin, line);
    stringstream ss(line);
    string token;
    for (int j = 0; j < size; j++){
      getline(ss,token, ' ');
      array[j] = stoi(token);
    }
    medians[i] = getmedian(size, array);
  }
  cout << getmedian(size, medians);
}

/*
ID: alanycw1
LANG: C++
TASK: ride
*/
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int get_id(ifstream* input){
  int y = 1;
  string line;
  getline (*input, line);
  int len = line.length();
  for (int i = 0; i < len; i++){
    int x = line[i]-64;
    y *= x;
  }
  return y;
}

int main() {
  int a;
  int b;
  ifstream input;
  ofstream output;
  output.open("ride.out");
  input.open("ride.in");
  a = get_id(&input);
  b = get_id(&input);
  if  (a%47 == b%47){
    output << "GO" << endl;
  }
  else  {
    output << "STAY" << endl;
  }
  input.close();
}

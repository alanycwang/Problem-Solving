#include <iostream>

using namespace std;

int factorial(int n){
  int x;
  if (n != 1){
    x = n*factorial(n-1);
  }
  else(x = 1);
  return x;

}

int main(){
  int x;
  cin >> x;
  cout << factorial(x);

}

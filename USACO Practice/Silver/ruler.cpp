#include <iostream>

using namespace std;

void printRuler(int n){
  if (n == 1){
    cout << '*' << endl;
  }
  else{
    printRuler(n-1);
    for (int i = 0; i < n; i++){
      cout << '*';
    }
    cout << endl;
    printRuler(n-1);
  }
}

int main(){
  int x;
  cin >> x;
  for (int i = 0; i < x; i++){
    cout << '*';
  }
  cout << endl;
  printRuler(x-1);
  for (int i = 0; i < x; i++){
    cout << '*';
  }
}

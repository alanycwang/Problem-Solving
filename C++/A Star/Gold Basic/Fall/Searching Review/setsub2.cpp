#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  int numbers[n];
  for (int i = 0; i < n; i++){
    cin >> numbers[i];
  }
  for (int i = 0; i < ( 1 << n); i++){
    int sum = 0;
    for (int j = 0; j < n; j++){
      int tmp = i >> j;
      if (tmp & 1){
        cout << numbers[j];
      }
    }
    if (i != 0){
      cout << endl;
    }
  }
}

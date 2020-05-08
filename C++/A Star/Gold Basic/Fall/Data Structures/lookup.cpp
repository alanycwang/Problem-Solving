#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  int heights[n];
  for (int i = 0; i < n; i++){
    cin >> heights[i];
  }
  for (int i = 0; i < n; i++){
    bool none = true;
    for (int j = i; j < n; j++){
      if (heights[j] > heights[i]){
        cout << j + 1 << endl;
        none = false;
        break;
      }
    }
    if (none){
      cout << 0 << endl;
    }
  }
}

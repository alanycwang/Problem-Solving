#include <iostream>

using namespace std;

void solve(){
  int ans = 9999999;
  int a = 0;;
  int b = 0;
  bool bowls[20];
  bool bowl[20];
  for (int i = 0; i < 20; i++){
    cin >> bowl[i];
  }
  for (int i = 0; i < (1 << 20); i++){
    a = 0;
    b = 0;
    for (int k = 0; k < 20; k++){
      bowls[k] = bowl[k];
    }
    int sum = 0;
    for (int j = 0; j < 20; j++){
      int tmp = i >> j;
      if (tmp & 1){
        if (bowls[j-1]){
          bowls[j-1] = false;
        }
        else{
          bowls[j-1] = true;
        }
        if (bowls[j]){
          bowls[j] = false;
        }
        else{
          bowls[j] = true;
        }
        if (bowls[j+1]){
          bowls[j+1] = false;
        }
        else{
          bowls[j+1] = true;
        }
        a++;
      }
    }
    for (auto x : bowls){
      if (!x){
        b++;
      }
    }
    if (b == 20){
      if (a < ans){
        ans = a;
      }
    }

  }
  cout << ans;
}

int main(){
  solve();
}

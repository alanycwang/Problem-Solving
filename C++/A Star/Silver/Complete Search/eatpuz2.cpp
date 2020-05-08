#include <iostream>

using namespace std;

void solve(){
  int c, b;
  cin >> c >> b;
  int buckets[b];
  int ans = 0;
  for (int i = 0; i < b; i++){
    cin >> buckets[i];
  }
  for (int i = 0; i < ( 1 << b); i++){
    int sum = 0;
    for (int j = 0; j < b; j++){
      int tmp = i >> j;
      if (tmp & 1){
        sum += buckets[j];
      }
    }
    if (sum > ans && sum <= c){
      ans = sum;
    }
  }
  cout << ans;
}

int main(){
  solve();
}

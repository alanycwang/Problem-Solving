#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

void solve(){
  int n;
  cin >> n;
  pair<int, int> bales[n];
  int last3 = 0;
  for (int i = 0; i < n; i++){
    cin >> bales[i].first >> bales[i].second;
  }
  sort(bales, bales + n, greater<pair<int, int>>());
  /*for (auto x : bales){
    cout << x.first << " " << x.second << endl;
  }*/
  for (int i = 0; i < (1 << n); i++){
    int last1 = 999999;
    int last2 = 999099;
    int sum = 0;
    for (int j = 0;j < n; j++){
      int tmp = i >> j;
      if (tmp & 1){
        if (last1 > bales[j].first && last2 > bales[j].second){
          last1 = bales[j].first;
          last2 = bales[j].second;
          sum++;
        }
      }
    }
    if (sum > last3){
      last3 = sum;
    }
  }
  cout << last3;
}

int main(){
  solve();
}

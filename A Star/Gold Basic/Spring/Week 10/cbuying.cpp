#include <bits/stdc++.h>

using namespace std;

bool helper(pair<int, int> a, pair<int, int> b){
  return a.first < b.first;
}

int main(){
  int n, b;
  cin >> n >> b;
  pair<int, int> a[n];
  for (int i = 0; i < n; i++){
    cin >> a[i].first >> a[i].second;
  }
  int c = 0;
  int ans = 0;
  sort(a, a+n, helper);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < a[i].second; j++){
      c += a[i].first;
      if (c > b){
        break;
      }
      ans ++;
    }
  }
  cout << ans;
}

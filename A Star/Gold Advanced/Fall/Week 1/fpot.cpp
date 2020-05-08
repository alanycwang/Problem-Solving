#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool s(pair<int, int> a, pair<int, int> b){
  return a.first < b.first;
}

int main(){
  int n, d; cin >> n >> d;
  pair<int, int> drops[n];
  int m = 0;
  for (int i = 0; i < n; i++){
    cin >> drops[i].first >> drops [i].second;
    m = max(drops[i].first, m);
  }
  sort(drops, drops+n, s);
  for (int w = 1; true; w++){
    for (int i = 0; i < n-1; i+=w){
      int l = drops[i].second;
      int s = drops[i].second;
      for (int j = i+1; j < n; j++){
        //cout << drops[j].first << " " << drops[i].first << " " << w << endl;
        l = max(l, drops[j].second);
        s = min(s, drops[j].second);
        if (drops[j].first - drops[i].first <= w && abs(l-s) >= d){
          cout << w;
          return 0;
        }
        if (drops[j].first - drops[i].first > w){
          break;
        }
      }
    }
    if (w > m){
      cout << -1;
      return 0;
    }
  }
}

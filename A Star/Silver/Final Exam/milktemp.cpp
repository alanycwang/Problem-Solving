#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n, x, y, z;
  cin >> n >> x >> y >> z;
  pair<int, int> cows[n];
  for (int i = 0; i < n; i++){
    cin >> cows[i].first >> cows[i].second;
  }
  int ans = 0;
  sort(cows, cows+n);
  for (int i = cows[0].first; i < cows[n-1].second; i++){
    int production = 0;
    for (int j = 0; j < n; j++){
      if (i >= cows[j].first && i <= cows[j].second){
        production += y;
      }
      else if (i < cows[j].first){
        production += x;
      }
      else{
        production += z;
      }
    }
    if (production > ans){
      ans = production;
    }
  }
  cout << ans;
}

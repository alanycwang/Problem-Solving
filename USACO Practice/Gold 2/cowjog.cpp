#include <iostream>
#include <algorithm>

using namespace std;

bool sortHelper (pair<long long, long long> a, pair<long long, long long> b){
  if(a.first == b.first){
    return a.second < b.second;
  }
  return a.first > b.first;
}

bool helper (pair<long long, long long> a, pair<long long, long long> b){
  return a.first > b.first;
}

int main(){
  int n, t;
  cin >> n >> t;
  pair<long long, long long> cows[n];
  for (int i = 0; i < n; i++){
    cin >> cows[i].first >> cows[i].second;
  }
  sort (cows, cows + n, sortHelper);
  cows[0].first += cows[0].second * t;
  for (int i = 1; i < n; i++){
    if (cows[i].second * t >= cows[i-1].first - cows[i].first){
      cows[i].first = cows[i-1].first;
    }
    else {
      cows[i].first += cows[i].second * t;
    }
  }
/*  for (int i = 0; i < n; i++){
    cout << cows[i].first << " " << cows[i].second << endl;
  }*/
  sort(cows, cows + n, helper);
  long long current = cows[0].first;
  int ans = 1;
  for (int i = 0; i < n; i++){
    if (cows[i].first != current){
      ans++;
      current = cows[i].first;
    }
  }
  cout << ans;
}

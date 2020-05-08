#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> drops[10000];
int n, d;

bool wide_enough(int w){
  for (int i = 0; i < n-1; i+=w){
    int l = drops[i].second;
    int s = drops[i].second;
    for (int j = i+1; j < n; j++){
      //cout << drops[j].first << " " << drops[i].first << " " << w << endl;
      l = max(l, drops[j].second);
      s = min(s, drops[j].second);
      if (drops[j].first - drops[i].first <= w && abs(l-s) >= d){
        return true;
      }
      if (drops[j].first - drops[i].first > w){
        break;
      }
    }
  }
  return false;
}

bool s(pair<int, int> a, pair<int, int> b){
  return a.first < b.first;
}

int main(){
  int m = 0; int l = 0;
  cin >> n >> d;
  for (int i = 0; i < n; i++){
    cin >> drops[i].first >> drops [i].second;
    m = max(drops[i].first, m);
    l = min(drops[i].first, m);
  }
  sort(drops, drops+n, s);
  if (!wide_enough(m-l)){
    cout << -1;
    return 0;
  }
  int mid;
  int minw = 0;
  int maxw = m-l;
  while (minw != maxw){
    mid = (minw + maxw)/2;
    //cout << minw << " " << maxw << " " << mid << endl;
    if (wide_enough(mid)){
      maxw = mid;
    }
    else{
      minw = mid+1;
    }
  }
  cout << minw;
}

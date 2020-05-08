#include <bits/stdc++.h>

using namespace std;

int wait[100000];
bool visited[100000];

int main(){
freopen("convention2.in", "r", stdin);
  freopen("convention2.out", "w", stdout);
  int n;
  cin >> n;
  pair<int, int> cows[n];
  for (int i = 0; i < n; i++){
    cin >> cows[i].first >> cows[i].second;
  }
  sort(cows, cows + n);
  int t = cows[0].first;
  priority_queue<int> q;
  q.push(0);
  visited[0] = true;
  int c = 1;
  while (c <= n){
    int a = q.top();
    q.pop();
    wait[a] = t-cows[a].first;
    t += cows[a].second;
    for (int i = 0; i < n; i++){
      if (cows[i].first < t && !visited[i]){
        visited[i] = true;
        q.push(i);
        c++;
      }
    }
    if (q.empty()){
      int l = 1000000000;
      int l2;
      for (int i = 0; i < n; i++){
        if (!visited[i] && cows[i].first < l){
          l = cows[i].first;
          l2 = i;
        }
      }
      q.push(l2);
      c++;
      t = l;
      visited[l2] = true;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++){
    ans = max(ans, wait[i]);
  }
  cout << ans;
}

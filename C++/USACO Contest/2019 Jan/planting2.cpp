#include <bits/stdc++.h>

using namespace std;

int main(){
  freopen("planting.in", "r", stdin);
  freopen("planting.out", "w", stdout);
  int n;
  cin >> n;
  int fields[n];
  set<int> paths[n];
  bool visited[n];
  memset (fields, 0, sizeof(fields));
  memset (visited, 0, sizeof(visited));
  for (int i = 1; i < n; i++){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    paths[x].insert(y);
    paths[y].insert(x);
  }
  int ans = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(0, 1));
  fields[0] = 1;
  visited[0] = true;
  while (!q.empty()){
    pair<int, int> a = q.front(); q.pop();
    int j = 0;
    for (int i = 1; i < n; i++){
      if (i != a.first && paths[a.first].find(i) != paths[a.first].end() && !visited[i]){
        visited[i] = true;
        while (true){
          j++;
          if (j != a.second && j != fields[a.first]){
            ans = max(ans, j);
            fields[i] = j;
            q.push(make_pair(i, fields[a.first]));
            break;
          }
        }
      }
    }
  }
/*  for (int i = 0; i < n; i++){
    cout << fields[i] << endl;
  }*/
  cout << ans << endl;
}

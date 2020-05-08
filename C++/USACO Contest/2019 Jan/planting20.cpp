#include <bits/stdc++.h>

using namespace std;

int main(){
  freopen("planting.in", "r", stdin);
  freopen("planting.out", "w", stdout);
  int n;
  cin >> n;
  int fields[n];
  int paths[n-1][2];
  bool visited[n];
  memset (fields, 0, sizeof(fields));
  memset (visited, 0, sizeof(visited));
  for (int i = 0; i < n-1; i++){
    int x, y;
    cin >> x >> y;
    x--; y--;
    paths[i][0] = x;
    paths[i][1] = y;
  }
  int ans = 0;
  priority_queue<pair<int, int>> q;
  q.push(make_pair(0, 1));
  fields[0] = 1;
  visited[0] = true;
  while (!q.empty()){
    pair<int, int> a = q.top(); q.pop();
    int j = 0;
    for (int i = 0; i < n-1; i++){
      if (paths[i][0] == a.first && !visited[paths[i][1]]){
        visited[paths[i][1]] = true;
        while (true){
          j++;
          if (j != a.second && j != fields[a.first]){
            ans = max(ans, j);
            fields[paths[i][1]] = j;
            q.push(make_pair(paths[i][1], fields[a.first]));
            break;
          }
        }
      }
      if (paths[i][1] == a.first && !visited[paths[i][0]]){
        visited[paths[i][0]] = true;
        while (true){
          j++;
          if (j != a.second && j != fields[a.first]){
            ans = max(ans, j);
            fields[paths[i][0]] = j;
            q.push(make_pair(paths[i][0], fields[a.first]));
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

#include <bits/stdc++.h>

using namespace std;

int main(){
  freopen("perimeter.in", "r", stdin);
  freopen("perimeter.out", "w", stdout);
  int n;
  cin >> n;
  string graph[n];
  bool visited[n][n];
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < n; i++){
    cin >> graph[i];
  }
  int ans = 0;
  int ans2 = 1000000000;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (graph[i][j] == '#' && !visited[i][j]){
        //cout << "a" << endl;
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        int p = 0;
        int area = 1;
        visited[i][j] = true;
        while (!q.empty()){
          pair<int, int> a = q.front(); q.pop();
          int chx[4] = {a.first + 1, a.first - 1, a.first, a.first};
          int chy[4] = {a.second, a.second, a.second + 1, a.second - 1};
          for (int k = 0; k < 4; k++){
            if (chx[k] < 0 || chx[k] >= n || chy[k] < 0 || chy[k] >= n || graph[chx[k]][chy[k]] == '.'){
              p++;
              //cout << chx[k] << " " << chy[k] << " " << p << endl;
              continue;
            }
            if (!visited[chx[k]][chy[k]]){
              visited[chx[k]][chy[k]] = true;
              q.push(make_pair(chx[k], chy[k]));
              area++;
            }
          }
        }
        if (area == ans){
          ans2 = min(p, ans2);
        }
        else if (area > ans){
          ans = area;
          ans2 = p;
        }
      }
    }
  }
  cout << ans << " " << ans2 << endl;
}

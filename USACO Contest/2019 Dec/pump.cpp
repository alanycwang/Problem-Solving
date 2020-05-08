#include <bits/stdc++.h>

using namespace std;

float value(int cost, int flow){
  if (cost == 0){
    return 1000000000.0;
  }
  return flow/cost;
}

int main(){
freopen("pump.in", "r", stdin);
  freopen("pump.out", "w", stdout);
  int n, m;
  cin >> n >> m;
  int paths [n][n][2];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      paths[i][j][0] = 1000000000;
      paths[i][j][1] = -1000000000;
    }
    paths[i][i][0] = 0;
    paths[i][i][1] = 1000000000;
  }
  bool visited[n];
  memset (visited, 0, sizeof(visited));
  for (int i = 0; i < m; i++){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    paths[a-1][b-1][0] = c;
    paths[a-1][b-1][1] = d;
    paths[b-1][a-1][0] = c;
    paths[b-1][a-1][1] = d;
  }
  pair<int, int> dist[n];
  for (int i = 0; i < n; i++){
    dist[i] = make_pair (1000000000, -1000000000);
  }
  dist[0] = make_pair(0, 1000000000);
  for (int i = 0; i < n; i++){
    int maxj = -1;
    for (int j = 0; j < n; j++){
      if (!visited[j] && (maxj == -1 || value(dist[j].first, dist[j].second) > value(dist[maxj].first, dist[maxj].second))){
        maxj = j;
      }
    }
    if (maxj != -1){
      visited[maxj] = true;
      for (int j = 0; j < n; j++){
        if (value(dist[j].first, dist[j].second) < value(paths[maxj][j][0] + dist[maxj].first, min(paths[maxj][j][1], dist[maxj].second))){
          dist[j] = make_pair(paths[maxj][j][0] + dist[maxj].first, min(paths[maxj][j][1], dist[maxj].second));
        }
      }
    }
  }
  cout << (1000000 * dist[n-1].second) / dist[n-1].first << endl;
}

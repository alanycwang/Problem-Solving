#include <iostream>

using namespace std;

int paths[101][101];
int dist[101];
int visited[101];

int main(){
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    for (int j  = 0; j < n; j++){
      paths[i][j] = 1000000000;
    }
    paths[i][i] = 0;
  }
  for (int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    paths[a-1][b-1] = c;
    paths[b-1][a-1] = c;
  }
  int a = 0;
  int ans = 0;
  for (int i = 0; i < n; i++){
    dist[i] = 1000000000;
  }
  dist[0] = 0;
  for (int i = 0; i < n; i++){
    int x = -1;
    for (int j = 0; j < n; j++){
      if (!visited[j] && (x == -1 || dist[j] < dist[x])){
        x = j;
      }
    }
    visited[x] = true;
    for (int j = 0; j < n; j++){
      dist[j] = min(dist[j], dist[x] + paths[x][j]);
    }
  }
  a = dist[n-1];
  for (int k = 0; k < n; k++){
    for (int l = 0; l < n; l++){
      if (paths[k][l] >= 1000000000){
        continue;
      }
      paths[k][l] *= 2;
      for (int i = 0; i < n; i++){
        visited[i] = false;
      }
      for (int i = 1; i < n; i++){
        dist[i] = 1000000000;
      }
      dist[0] = 0;
      for (int i = 0; i < n; i++){
        int x = -1;
        for (int j = 0; j < n; j++){
          if (!visited[j] && (x == -1 || dist[j] < dist[x])){
            x = j;
          }
        }
        visited[x] = true;
        for (int j = 0; j < n; j++){
          dist[j] = min(dist[j], dist[x] + paths[x][j]);
        }
      }
      ans = max(ans, dist[n-1]);
      paths[k][l] /= 2;
    }
  }
  cout << ans - a << endl;
  //cout << a << " " << ans;
}

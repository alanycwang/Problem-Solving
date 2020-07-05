#include <iostream>

using namespace std;

bool visited[2501];
int roads[2501][2501];
int dist[2501];

int main(){
  int n, c, ts, te;
  cin >> n >> c >> ts >> te;
  ts--;
  te--;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      roads[i][j] = 1000000000;
    }
    roads[i][i] = 0;
  }
  for (int i = 0; i < c; i++){
    int a, b, c;
    cin >> a >> b >> c;
    roads[a-1][b-1] = min(roads[a-1][b-1], c);
    roads[b-1][a-1] = min(roads[b-1][a-1], c);
  }

  for (int i = 0; i < n; i++){
    dist[i] = 1000000000;
  }
  dist[ts] = 0;
  for (int i = 0; i < n; i++){
    int x = -1;
    for (int j = 0; j < n; j++){
      if (!visited[j] && (x == -1 || dist[j] < dist[x])){
        x = j;
      }
    }
    visited[x] = true;
    for (int j = 0; j < n; j++){
      if (!visited[j]){
        dist[j] = min(dist[j], dist[x] + roads[x][j]);
      }
    }
  }
  cout << dist[te];
}

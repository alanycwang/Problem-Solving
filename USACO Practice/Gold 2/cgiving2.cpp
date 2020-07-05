#include <iostream>

using namespace std;

bool visited[1000];

int main(){
  int n, m, b;
  cin >> n >> m >> b;
  int graph[n][n];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      graph[i][j] = 1000000000;
    }
    graph [i][i] = 0;
  }
  for (int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    graph[a-1][b-1] = min(graph[a-1][b-1], c);
    graph[b-1][a-1] = min(graph[a-1][b-1], c);
  }
  int dist[n];
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
    for (int j = 1; j < n; j++){
      if (!visited[j]){
        dist[j] = min(dist[j], graph[x][j] + dist[x]);
      }
    }
  }
  /*for (int i = 0; i < n; i++){
    cout << i+1 << " " << dist[i] << endl;
  }*/
  for (int i = 0; i < b; i++){
    int a, b;
    cin >> a >> b;
    cout << dist[a-1] + dist[b-1] << endl;
  }
}

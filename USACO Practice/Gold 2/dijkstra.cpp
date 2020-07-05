#include <iostream>
#include <vector>

using namespace std;

bool visited[2501];
int graph[2501][2501];

int main(){
  int n, e, s;
  cin >> n >> e >> s;
  s--;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      graph[i][j] = 1000000000;
    }
    graph[i][i] = 0;
  }
  for (int i = 0; i < e; i++){
    int a, b, c;
    cin >> a >> b >> c;
    graph[a-1][b-1] = c;
    graph[b-1][a-1] = c;
  }
  int dist[n];
  for (int i = 0; i < n; i++){
    dist[i] = 1000000000;
  }
  dist[s] = 0;
  for (int i = 0; i < n; i++){
    int minj = -1;
    for (int j = 0; j < n; j++){
      if (!visited[j] && (minj == -1 || dist[j] < dist[minj])){
        minj = j;
      }
    }
    if (minj != -1){
      visited[minj] = true;
      for (int j = 0; j < n; j++){
        dist[j] = min(dist[j], graph[minj][j] + dist[minj]);
      }
    }
  }
  for (int i = 0; i < n; i++){
    if (dist[i] >= 1000000000){
      cout << -1 << endl;
    }
    else {
      cout << dist[i] << endl;
    }
  }
}

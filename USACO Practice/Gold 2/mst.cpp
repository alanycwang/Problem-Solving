#include <iostream>
#include <string.h>

using namespace std;

bool visited[2500];
int dist[2500];

int main(){
  for (int i = 0; i < 2500; i++){
    dist[i] = 1000000000;
  }
  dist[0] = 0;
  int v, e;
  cin >> v >> e;
  int edges[v][v];
  for (int i = 0; i < v; i++){
    for (int j = 0; j < v; j++){
      edges[i][j] = 2000000000;
    }
  }
  for (int i = 0; i < e; i++){
    int a, b, c;
    cin >> a >> b >> c;
    edges[a-1][b-1] = c;
    edges[b-1][a-1] = c;
  }
  int ans = 0;
  for (int i = 0; i < v; i++){
    int mind = 1000000000;
    int minj = -1;
    for (int j = 0; j < v; j++){
      if (!visited[j] && dist[j] < mind){
        mind = dist[j];
        minj = j;
      }
    }
    visited[minj] = true;
    ans += mind;
    for (int j = 0; j < v; j++){
      dist[j] = min(dist[j], edges[minj][j]);
    }
  }
  cout << ans;
}

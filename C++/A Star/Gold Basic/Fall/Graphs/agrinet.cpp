#include <iostream>

using namespace std;

bool visited[100];

int main(){
  int n;
  cin >> n;
  int edges[n][n];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> edges[i][j];
    }
  }
  int dist[n];
  for (int i = 1; i < n; i++){
    dist[i] = 1000000000;
  }
  int ans = 0;
  dist[0] = 0;
  for (int i = 0; i < n; i++){
    int mind = 1000000000;
    int minj = -1;
    for (int j = 0; j < n; j++){
      if (!visited[j] && dist[j] < mind){
        mind = dist[j];
        minj = j;
      }
    }
    ans += mind;
    visited[minj] = true;
    for (int j = 0; j < n; j++){
      dist[j] = min(dist[j], edges[minj][j]);
    }
  }
  cout << ans;
}

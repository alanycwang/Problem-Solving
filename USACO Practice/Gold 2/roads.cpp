#include <iostream>
#include <cmath>

using namespace std;

bool visited[1000];

int main(){
  int n, m;
  cin >> n >> m;
  double farms[n][2];
  for (int i = 0; i < n; i++){
    cin >> farms[i][0] >> farms[i][1];
  }
  bool roads[n][n];
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    roads[a][b] = true;
    roads[b][a] = true;
  }
  double dist[n];
  for (int i = 1; i < n; i++){
    dist[i] = 1000000000;
  }
  dist[0] = 0;
  double ans = 0;
  for (int i = 0; i < n; i++){
    double mind = 1000000000;
    int minj = -1;
    for (int j = 0; j < n; j++){
      if (!visited[j] && dist[j] < mind){
        mind = dist[j];
        minj = j;
      }
    }
    visited[minj] = true;
    for (int j = 0; j < n; j++){
      if (roads[minj][j] && visited[j]){
        ans-=mind;
        dist[j] = min(dist[j], sqrt(pow(farms[j][0] - farms[minj][0], 2) + pow(farms[j][1] - farms[minj][1], 2)));
        break;
      }
    }
    ans += mind;
    for (int j = 0; j < n; j++){
      if (roads[minj][j]){
        ans-=mind;
        dist[j] = min(dist[j], sqrt(pow(farms[j][0] - farms[minj][0], 2) + pow(farms[j][1] - farms[minj][1], 2)));
        break;
      }
      else {
        dist[j] = min(dist[j], sqrt(pow(farms[j][0] - farms[minj][0], 2) + pow(farms[j][1] - farms[minj][1], 2)));
      }
    }
  }
  printf("%.2f", ans);
}

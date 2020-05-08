#include <iostream>
#include <string.h>

using namespace std;

int n, m, x;

float calc(float l, float c){
  if(c == 0){return 1000000000.0;}
  return l + x/c;
}

int main(){
  cin >> n >> m >> x;
  int graph[n][n][2];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      graph[i][j][0] = 1000000000;
      graph[i][j][1] = 0;
    }
    graph[i][i][0] = 0;
    graph[i][i][1] = 1000000000;
  }
  for (int i = 0; i < m; i++){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    graph[a-1][b-1][0] = c;
    graph[a-1][b-1][1] = d;
    graph[b-1][a-1][0] = c;
    graph[b-1][a-1][1] = d;
  }
  float dist[n][3];
  bool visited[n];
  memset(visited, 0, sizeof(visited));
  float temp[3] = {0, 0, 1000000000};
  dist[0][0] = 0; dist[0][1] = 0; dist[0][2] = 1000000000;
  temp[0] = 1000000000; temp[1] = 1000000000; temp[2] = 0;
  for (int i = 1; i < n; i++){
    dist[i][0] = 1000000000; dist[i][1] = 1000000000; dist[i][2] = 0;
  }
  for (int i = 0; i < n; i++){
    int minj = -1;
    for (int j = 0; j < n; j++){
      if (!visited[j] && (minj == -1 || dist[j][0] < dist[minj][0])){
        minj = j;
      }
    }
    if (minj != -1){
      visited[minj] = true;
      for (int j = 0; j < n; j++){
        //cout << calc(dist[minj][1] + graph[minj][j][0], min(dist[minj][2], float(graph[minj][j][1]))) << " " << minj << " " << j << endl;
        if (dist[j][0] > calc(dist[minj][1] + graph[minj][j][0], min(dist[minj][2], float(graph[minj][j][1])))){
          dist[j][0] = calc(dist[minj][1] + graph[minj][j][0], min(dist[minj][2], float(graph[minj][j][1])));
          dist[j][1] = dist[minj][1] + graph[minj][j][0];
          dist[j][2] = min(dist[minj][2], float(graph[minj][j][1]));
        }
      }
    }
  }
  cout << int(dist[n-1][0]);
}

#include <iostream>
#include <string.h>

using namespace std;

int n, p, k;
int graph[1000][1000];

bool possible (int cost){
  int tempgraph[n][n];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (graph[i][j] >= 1000000000){tempgraph[i][j] = 1000000000;}
      else if (graph[i][j] <= cost){tempgraph[i][j] = 0;}
      else {tempgraph[i][j] = 1;}
    }
  }
  bool visited[n];
  int dist[n];
  for (int i = 0; i < n; i++){
    dist[i] = 1000000000;
  }
  dist[0] = 0;
  memset (visited, 0, sizeof(visited));
  for (int i = 0; i < n; i++){
    int minj = -1;
    for (int j = 0; j < n; ++j){
      if (!visited[j] && (minj == -1 || dist[j] < dist[minj])){
        minj = j;
      }
    }
    if (minj != -1){
      visited[minj] = true;
      for (int j = 0; j < n; j++){
        dist[j] = min(dist[j], dist[minj] + tempgraph[j][minj]);
      }
    }
  }
  return (dist[n-1] <= k);
}

int main (){
  cin >> n >> p >> k;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      graph[i][j] = 1000000000;
    }
    graph[i][i] = 0;
  }
  int high = 0;
  for (int i = 0; i < p; i++){
    int a, b, c;
    cin >> a >> b >> c;
    graph[a-1][b-1] = c;
    graph[b-1][a-1] = c;
    high = max(high, c);
  }
  int low = 0;
  int mid;
  while (high > low){
    mid = int((high + low)/2);
    //cout << high << " " << mid << " " << low << endl;
    if (possible(mid)){high = mid;}
    else {low = mid + 1;}
  }
  if (!possible(low)){
    cout << -1;
    return 0;
  }
  cout << low << endl;
}

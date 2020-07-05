#include <iostream>
#include <set>
#include <queue>

using namespace std;

long long INF = 1000000000000000;
bool visited[1000];
long long dist[1000];

int main(){
  int a, b, n;
  cin >> a >> b >> n;
  long long edges[1000][1000];
  for (int i = 0; i < n; i++){
    long long c, d;
    cin >> c >> d;
    long long cities[d];
    for (int j = 0; j < d; j++){
      cin >> cities[j];
      cities[j]--;
    }
    for (int j = 0; j < d; j++){
      for (int k = j + 1; k < d; k++){
        edges[cities[j]][cities[k]] = min(edges[cities[j]][cities[k]], d);
        edges[cities[k]][cities[j]] = min(edges[cities[k]][cities[j]], d);
      }
    }
  }
  for (int i = 0; i < n; i++){
    dist[i] = INF;
  }
  dist[a-1] = 0;
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
        dist[j] = min(dist[j], edges[minj][j] + dist[minj]);
      }
    }
  }
  cout << dist[b-1];
}

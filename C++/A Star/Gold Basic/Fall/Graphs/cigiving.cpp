#include <iostream>
#include <set>
#include <queue>

using namespace std;

int INF = 1000000000;

int main(){
  int n, m, b;
  cin >> n >> m >> b;
  set<pair<int, int>> edges[n];
  for (int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    edges[a-1].insert(make_pair(b-1, c));
    edges[b-1].insert(make_pair(a-1, c));
  }
  bool visited[n];
  int dist[n];
  for (int j = 0; j < n; j++){
    visited[j] = false;
    dist[j] = INF;
  }
  dist[0] = 0;
  priority_queue<pair<int, int>> q;
  q.push(make_pair(0, 0));
  while(!q.empty()){
    pair<int, int> x = q.top(); q.pop();
    if (!visited[x.second]){
      visited[x.second] = true;
      for (auto j : edges[x.second]){
        if (!visited[j.first] && dist[j.first] > dist[x.second] + j.second){
          dist[j.first] = dist[x.second] + j.second;
          q.push(make_pair(-dist[j.first], j.first));
        }
      }
    }
  }
  for (int i = 0; i < b; i++){
    int a, b;
    cin >> a >> b;
    cout << dist[a-1] + dist[b-1] << endl;
  }
}

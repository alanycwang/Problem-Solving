#include <iostream>
#include <set>
#include <queue>

using namespace std;

int INF = 1000000000;
bool visited[50000];

int main(){
  int v, e, s;
  cin >> v >> e >> s;
  set<pair<int, int>> edges[v];
  for (int i = 0; i < e; i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    edges[a].insert(make_pair(b, c));
    edges[b].insert(make_pair(a, c));
  }
  int dist[v];
  for (int i = 0; i < v; i++){
    dist[i] = INF;
  }
  dist[s-1] = 0;
  priority_queue<pair<int, int>> q;
  q.push(make_pair(0, s-1));
  while (!q.empty()){
    pair<int, int> x = q.top();
    q.pop();
    if (!visited[x.second]){
      visited[x.second] = true;
      for (auto i : edges[x.second]){
        if (!visited[i.first] && dist[i.first] > dist[x.second] + i.second){
          dist[i.first] = dist[x.second] + i.second;
          q.push(make_pair(-dist[i.first], i.first));
        }
      }
    }
  }
  for (auto i : dist){
    if (i == INF){
      cout << -1 << endl;
    }
    else{
      cout << i << endl;
    }
  }
}

#include <iostream>
#include <set>
#include <queue>

using namespace std;

int INF = 1000000000;
int dist[500000];
bool visited[500000];
set<pair<int, int>> edges[50000];

int main(){
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
      edges[a-1].insert(make_pair(b-1, c));
      edges[b-1].insert(make_pair(a-1, c));
  }
  for (int i = 0; i < n; i++){
    dist[i] = INF;
  }
  dist[0] = 0;
  priority_queue<pair<int, int>> q;
  q.push(make_pair(0, 0));
  while(!q.empty()){
    pair<int, int> x = q.top(); q.pop();
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
  cout << dist[n-1];
}

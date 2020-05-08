#include <iostream>
#include <set>
#include <queue>

using namespace std;

int INF = 1000000000;
bool visited[50000];

int main(){
  int v, e;
  cin >> v >> e;
  set<pair<int, int>> edges[e];
  for (int i = 0; i < e; i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    pair<int, int> d;
    d.first = b;
    d.second = c;
    edges[a].insert(d);
    pair<int, int> e;
    e.first = a;
    e.second = c;
    edges[b].insert(e);
  }
  int ans = 0;
  int dist[v];
  for (int i = 0; i < v; i++){
    dist[i] = INF;
  }
  dist[0] = 0;
  priority_queue<pair<int, int>> q;
  pair<int, int> a;
  a.first = 0;
  a.second = 0;
  q.push(a);
  while (!q.empty()){
    pair<int, int> b = q.top();
    q.pop();
    if (!visited[b.second]){
      visited[b.second] = true;
      ans += dist[b.second];
      for (auto i : edges[b.second]){
        if (!visited[i.first] && dist[i.first] > i.second){
          dist[i.first] = i.second;
          pair<int, int> c;
          c.first = -dist[i.first];
          c.second = i.first;
          q.push(c);
        }
      }
    }
  }
/*  for (auto i : dist){
    cout << i << endl;
  }*/
  cout << ans;
}

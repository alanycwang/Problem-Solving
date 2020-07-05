#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  bool graph[n][n];
  memset(graph, 0, sizeof(graph));
  for(int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    graph[a-1][b-1] = true;
    graph[b-1][a-1] = true;
  }

  queue<pair<int, int>> q;
  bool visited[n];
  memset(visited, 0, sizeof(visited));
  visited[0] = true;
  q.push(make_pair(0, 0));
  int ans;
  int ans2 = 0;
  int ans3;
  while(!q.empty()){
    pair<int, int> c;
    c = q.front(); q.pop();
    if(ans2 < c.second){
      ans = c.first;
      ans2 = c.second;
      ans3 = 1;
    }
    else if(ans2 == c.second){
      ans = min(c.first, ans);
      ans3++;
    }
    for (int i = 0; i < n; i++){
      if(graph[c.first][i] && !visited[i]){
        q.push(make_pair(i, c.second + 1));
        visited[i] = true;
      }
    }
  }
  cout << ans + 1 << " " << ans2 << " " << ans3;
}

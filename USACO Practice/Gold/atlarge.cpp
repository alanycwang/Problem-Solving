#include <bits\stdc++.h>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  set<int> paths[n];
  for (int i = 0; i < n-1; i++){
    int a, b;
    cin >> a >> b;
    paths[a-1].insert(b-1);
    paths[b-1].insert(a-1);
  }

  queue<pair<int, int>> q;
  int dist[n];
  bool visited[n];
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < n; i++){
    int temp = 0;
    for (int j = 0; j < n; j++){
      if (paths[i].find(j) != paths[i].end()){
        temp++;
      }
      if (temp >= 2){
        q.push(make_pair(i, 0));
        dist[i] = 0;
        visited[i] = true;
        break;
      }
    }
  }

  /*for (int i = 0; i < n; i++){
    cout << i+1 << endl;
    for (auto j : paths[i]){
      cout << j+1 << " ";
    }
    cout << endl;
  }*/

  //cout << "working" << endl;

  int dist2[n];
  dist2[k] = 0;
  bool visited2[n];
  memset(visited2, 0, sizeof(visited2));
  queue<pair<int, int>> q2;
  q2.push(make_pair(k, 0));
  visited2[k] = true;
  while(!q2.empty()){
    pair<int, int> temp = q2.front();
    q2.pop();
    for (int i = 0; i < n; i++){
      if (!visited2[i] && paths[i].find(temp.first) != paths[i].end()){
        q2.push(make_pair(i, temp.second + 1));
        visited2[i] = true;
        dist2[i] = temp.second + 1;
      }
    }
  }

  while (!q.empty()){
    pair<int, int> temp = q.front();
    q.pop();
    for (int i = 0; i < n; i++){
      if (!visited[i] && paths[i].find(temp.first) != paths[i].end()){
        q.push(make_pair(i, temp.second + 1));
        visited[i] = true;
        dist[i] = temp.second + 1;
      }
    }
  }

  for (int i = 0; i < n; i++){
    cout << dist[i] << endl;
  }

  //cout << "working" << endl;

  for (int i = 0; i < n; i++){
    cout << dist2[i] << endl;
  }
  int ans = 0;
  for (int i = 0; i < n; i++){
    if (dist[i] == dist2[i] || dist[i] + 1 == dist2[i]){
      ans++;
    }
  }
  cout << ans - 1;
}

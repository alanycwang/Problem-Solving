#include <iostream>
#include <set>
#include <queue>
#include <string.h>

using namespace std;

bool visited[1000];

int main(){
  int k, n, m;
  cin >> k >> n >> m;
  int cows[k];
  set<int> paths[n];
  for (int i = 0; i < k; i++){
    cin >> cows[i];
    cows[i]--;
  }
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    paths[a-1].insert(b-1);
  }
  for (int i = 0; i < k; i++){
    queue<int> q;
    q.push(cows[i]);
    memset(visited, 0, n);
    visited[cows[i]] = true;
    while (!q.empty()){
      int b = q.front();
      //cout << b << endl;
      q.pop();
      paths[cows[i]].insert(b);
      for (auto j : paths[b]){
        if (!visited[j]){
          visited[j] = true;
          q.push(j);
        }
      }
    }
  }
/*  for (int i = 0; i < n; i++){
    for (auto j : paths[i]){
      cout << j << " ";
    }
    cout << endl;
  }*/
  int ans = 0;
  for (int i = 0; i < n; i++){
    ans++;
    for (int j = 0; j < k; j++){
      if (paths[cows[j]].find(i) == paths[cows[j]].end()){
        ans--;
        break;
      }
    }
  }
  cout << ans;
}

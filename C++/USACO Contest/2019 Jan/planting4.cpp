#include <bits/stdc++.h>

using namespace std;

bool visited[100001];
int grass[100001];

int main(){
  freopen("planting.in", "r", stdin);
  freopen("planting.out", "w", stdout);

  int n;
  cin >> n;
  int paths[n-1][2];
  for (int i = 0; i < n-1; i++){
    cin >> paths[i][0] >> paths[i][1];
  }

  queue<int> q;
  q.push(1);
  visited[1] = true;
  int ans = 0;

  while (!q.empty()){
    /*for (int i = 1; i <= n; i++){
      cout << grass[i] << " ";
    }
    cout << endl;*/
    int a = q.front();
    q.pop();
    bool b = false;
    for(int i = 0; i < n; i++){
      if (paths[i][0] == a){
        if (!visited[paths[i][1]]){
          q.push(paths[i][1]);
          visited[paths[i][1]] = true;
          if (grass[paths[i][1]] == grass[a]){
            grass[a]++;
            b = true;
          }
        }
      }

      else if (paths[i][1] == a){
        if (!visited[paths[i][0]]){
          b = true;
          q.push(paths[i][0]);
          visited[paths[i][0]] = true;
          if (grass[paths[i][0]] == grass[a]){
            grass[a]++;
            b = true;
          }
        }
      }
    }
    if (b){
      ans++;
    }
  }
/*  for (auto i:grass){
    cout << i << " ";
  }
  cout << endl;*/
  /*for (int i = 0; i < n; i++){
    ans = max(ans, grass[i]);
  }*/
  cout << ans << endl;
}

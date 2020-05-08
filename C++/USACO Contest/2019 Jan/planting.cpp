#include <bits/stdc++.h>

using namespace std;

int fields[100000];
bool bad[100000];

int main(){
  freopen("planting.in", "r", stdin);
  freopen("planting.out", "w", stdout);
  int n;
  cin >> n;
  set<pair<int, int>> paths[n];
  for (int i = 1; i < n; i++){
    int x, y;
    cin >> x >> y;
    x--; y--;
    paths[x].insert(make_pair(y, 1));
    paths[y].insert(make_pair(x, 1));
  }
  for (int k = 0; k < n; k++){
    for (int i = 0; i < n; i++){
      if (i != k){
        for (int j = 0; j < n; j++){
          if (i != j && paths[i].find(make_pair(k, 1)) != paths[i].end() && paths[j].find(make_pair(k, 1)) != paths[j].end()){
            //cout << k << " " << i << " " << j << endl;
            paths[i].insert(make_pair(j, 2));
            paths[j].insert(make_pair(i, 2));
          }
        }
      }
    }
  }
/*  for (int i = 0; i < n; i++){
    for (auto j : paths[i]){
      cout << i << " " << j.first << endl;
    }
  }*/
  int ans = 0;
  for (int i = 0; i < n; i++){
    memset(bad, 0, sizeof(bad));
    fields[i] = 1;
    for (auto j : paths[i]){
      if (fields[j.first] == fields[i]){
        bad[fields[i]] = true;
        //cout << i << " " << j.first << " " << fields[i] << " " << fields[j.first] << endl;
        for (int k = 1; k < 100000; k++){
          if (!bad[k]){
            fields[i] = k;
            ans = max(ans, k);
            break;
          }
        }
      }
    }
  }
  /*for (int i  = 0; i < n; i++){
    cout << fields[i] << endl;
  }*/
  cout << ans << endl;
}

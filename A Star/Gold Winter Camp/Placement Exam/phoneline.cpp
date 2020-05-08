#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int n, p, k;

bool helper (int a, int b){
  return a > b;
}

int dyst (vector<int> a){
  if (a.empty()){
    return 1000000000;
  }
  sort(a.begin(), a.begin()+a.size(), helper);
  vector<int> b;
  for (int i = 0; i < a.size(); i++){
    if (a[i] >= 1000000000){return 1000000000;}
    if (a[i] != 0){
      b.push_back(a[i]);
    }
  }
  int ans = 0;
  for (int i = 0; i < b.size(); i++){
    ans = max(ans, b[i]);
  }

  return ans;
}

int main(){
  cin >> n >> p >> k;
  int graph[n][n];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      graph[i][j] = 1000000000;
    }
    graph[i][i] = 0;
  }
  for (int i = 0; i < p; i++){
    int a, b, c;
    cin >> a >> b >> c;
    graph[a-1][b-1] = c;
    graph[b-1][a-1] = c;
  }
/*  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cout << graph[i][j] << " ";
    }
    cout << endl;
  }*/
  vector<int> dist[n];
  bool vis[n];
  memset (vis, 0, sizeof(vis));
  vector<int> a;
  for (int i = 1; i < n; i++){
    dist[i] = a;
  }
  a.push_back(0);
  dist[0] = a;
  for (int i = 0; i < n; i++){
    int mindist = -1;
    for (int j = 0; j < n; j++){
      if (!vis[j] && (mindist == -1 || dyst(dist[j]) < dyst(dist[mindist]))){
        mindist = j;
      }
    }
    //cout << mindist << endl;
    if (mindist != -1){
      vis[mindist] = true;
      for (int j = 0; j < n; j++){
        //cout << graph[mindist][j] + dist[mindist]) << endl;
        vector<int> b = dist[mindist];
        b.push_back(graph[mindist][j]);
        if (dyst(dist[j]) > dyst(b)){
          //cout << "working" << endl;
          dist[j] = b;
        }
      }
    }
  }
/*  sort (dist[n-1].begin(), dist[n-1].begin() + dist[n-1].size(), helper);
  for (auto i : dist[n-1]){
    cout << i << " ";
  }
  cout << endl;*/
  cout << dyst(dist[n-1]);
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int graph[1001][1001];
bool vis[1001];
int n, p, k;
int ans = 1000000000;
vector<int> ans2;

bool helper (int a, int b){
  return a > b;
}

int dyst (vector<int> a){
  sort(a.begin(), a.begin()+a.size(), helper);
  int ans = 0;
  int ans = 0;
  for (int i = k; i < a.size(); i++){
    ans = max(ans, a[i]);
  }
  return ans;
}

void dfs (int loc, vector<int> map){
  //cout << loc << endl;
  if (loc == n-1){
    if (ans > dyst(map)){
      ans = dyst(map);
      ans2 = map;
    }
  }
  for (int i = 0; i < n; i++){
    if(!vis[i] && graph[loc][i] < 1000000000){
      vis[i] = true;
      vector<int> a = map;
      a.push_back(graph[loc][i]);
      dfs(i, a);
      vis[i] = false;
    }
  }
}

int main(){
  cin >> n >> p >> k;
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
  vector<int> a; a.push_back(0);
  vis[0] = true;
  dfs(0, a);
  vector<int> c;
  for (int i = 0; i < ans2.size(); i++){
    if (ans2[i] != 0){
      c.push_back(ans2[i]);
      //cout << ans2[i] << endl;
    }
  }
  sort (c.begin(), c.begin()+c.size(), helper);
  int ans = 0;
  for (int i = k; i < c.size(); i++){
    ans = max(ans, c[i]);
  }
  cout << ans;
}

#include <iostream>
#include <set>

using namespace std;

int n, m;
bool edges[250][250];
bool visited[250];

void dfs(int cow){
  for (int i = 0; i < n; i++){
    if (edges[cow][i] && !visited[i]){
      visited[i] = true;
      dfs(i);
    }
  }
}

int main(){
  cin >> n >> m;
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    edges[a-1][b-1] = true;
    edges[b-1][a-1] = true;
  }
  visited[0] = true;
  dfs(0);
  bool none = true;
  for (int i = 0; i < n; i++){
    if (visited[i] == false){
      cout << i + 1 << endl;
      none = false;
    }
  }
  if (none){
    cout << 0;
  }
}

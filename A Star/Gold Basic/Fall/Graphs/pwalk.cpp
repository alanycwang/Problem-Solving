#include <iostream>

using namespace std;

int n, q;
int edges[1001][1001];
bool visited[1001];
int shortest = 9999999;

void dfs(int cow, int destination, int length){
  //cout << "working" << endl;
  //cout << cow << endl;
  if (cow == destination){
    shortest = min(length, shortest);
    //cout << length << endl;
    return;
  }
  for (int i = 1; i < n + 1; i++){
    //cout << "working" << endl;
    if (edges[cow][i] != 0 && !visited[i]){
      visited[i] = true;
      dfs(i, destination, length + edges[cow][i]);
      visited[i] = false;
    }
  }
}

int main(){
  cin >> n >> q;
  for (int i = 0; i < n - 1; i++){
    int a, b, c;
    cin >> a >> b >> c;
    edges[a][b] = c;
    edges[b][a] = c;
    //cout << "working" << endl;
  }
  /*for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cout << edges[i][j] << " ";
    }
    cout << endl;
  }*/
  for (int i = 0; i < q; i++){
    int a, b;
    cin >> a >> b;
    dfs(a, b, 0);
    cout << shortest << endl;
    shortest = 9999999;
  }
}

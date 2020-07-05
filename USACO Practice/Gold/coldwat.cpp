#include <iostream>

using namespace std;

bool connected[100000];
pair<int, int> pipes[100000];
int dystance[100000];

void dfs(int loc, int dist){
  dystance[loc] = dist;
  if (connected[loc]){
    dfs(pipes[loc].first, dist + 1);
    dfs(pipes[loc].second, dist + 1);
  }
  return;
}

int main(){
  int n, c;
  cin >> n >> c;
  for (int i = 0; i < c; i++){
    int a, b, d;
    cin >> a >> b >> d;
    connected[a] = true;
    pipes[a] = make_pair(b, d);
  }
  dfs (1, 1);
  for (int i = 1; i <= n; i++){
    cout << dystance[i] << endl;
  }
}
  

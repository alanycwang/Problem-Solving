#include <iostream>
#include <set>

using namespace std;

int v, e, k;
set<pair<int, int>> slides[50001];
long int visited[50001][11];

long int f(int a, int b){
  //cout << a << " " << b << endl;
  if (visited[a][b] < 1000000000000){
    return visited[a][b];
  }
  long int c = -1;
  long int d = 1000000000000;
  for (auto i : slides[a]){
    //cout << i.first << " " << i.second << endl << endl;
    c = max(c, f(i.first, b) + i.second);
    if (b < k){
      d = min(d, f(i.first, b+1) + i.second);
    }
  }
  long int g = min(c, d);
  visited[a][b] = g;
  return g;
}

int main(){
  cin >> v >> e >> k;
  for (int i = 0; i <= v; i++){
    for (int j = 0; j < k+1; j++){
      visited[i][j] = 1000000000000;
    }
  }
  for (int i = 0; i < e; i++){
    int a, b, c;
    cin >> a >> b >> c;
    slides[a-1].insert(make_pair(b-1, c));
    //slides[b-1].insert(make_pair(a-1, c));
  }
  for (int i = 0; i < k+1; i++){
    visited[v-1][i] = 0;
  }
/*  for (int i = 0; i < v; i++){
    for (int j = 0; j < k; j++){
      cout << visited[i][j] << " ";
    }
    cout << endl;
  }*/
  cout << f(0, 0);
/*  cout << endl;
  for (int i = 0; i < v; i++){
    for (auto j : slides[i]){
      cout << i << " " << j.first << " " << j.second << endl;
    }
  }*/
}

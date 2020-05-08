#include <iostream>
#include <cmath>

using namespace std;

int fields[2000][2];
int edges[2000][2000];
int dist[2000];
bool visited[2000];

int main(){
  int n, c;
  cin >> n >> c;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      edges[i][j] = 1000000000;
    }
  }
  int x, y;
  for (int i = 0; i < n; i++){
    cin >> fields[i][0] >> fields[i][1];
    /*x = max(fields[n][0], x);
    y = max(fields[n][1], y);*/
  }
  /*x++;
  y++;*/
  for (int i = 0; i < n; i++){
    for (int j = i; j < n; j++){
      int a = pow(fields[i][0] - fields[j][0], 2) + pow(fields[i][1] - fields[j][1], 2);
      //cout << a << endl;
      if (a < c){
        continue;
      }
      edges[i][j] = a;
      edges[j][i] = a;
    }
  }
  for (int i = 0; i < n; i++){
    edges[i][i] = 0;
  }
/*  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cout << edges[i][j] << " ";
    }
    cout << endl;
  }*/
  for (int i = 0; i < n; i++){
    dist[i] = 1000000000;
    visited[i] = false;
  }
  dist[0] = 0;
  int ans = 0;
  for (int i = 0; i < n; i++){
    //cout << ans << endl;
    int mind = 1000000000;
    int minj = -1;
    for (int j = 0; j < n; j++){
      if (!visited[j] && dist[j] < mind){
        mind = dist[j];
        minj = j;
      }
    }
    visited[minj] = true;
    //cout << int(mind) << endl;
    ans += mind;
    for (int j = 0; j < n; j++){
      dist[j] = min(dist[j], edges[minj][j]);
      //cout << edges[minj][j] << endl;
    }
  }
  if (ans < 0 || ans > 1000000000){
    cout << -1;
    return 0;
  }
  cout << int(ans);
}

#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

bool edges[1051][1051];
bool visited[1051];
double rollers[1051][3];
int n, x_t, y_t;

struct m{
  int e;
  double r, t;
};

int main(){
  cin >> n >> x_t >> y_t;
  int v;
  for (int i = 1; i < n + 1; i++){
    for (int j = 0; j < 3; j++){
      cin >> rollers[i][j];
    }
    if (rollers[i][0] == 0 && rollers[i][1] == 0){
      v = i;
    }
  }
  for (int i = 1; i < n + 1; i++){
    for (int j = i + 1; j < n + 1; j++){
      if ((rollers[j][0] - rollers[i][0])*(rollers[j][0] - rollers[i][0]) + (rollers[j][1] - rollers[i][1])*(rollers[j][1] - rollers[i][1]) == (rollers[i][2] + rollers[j][2]) * (rollers[i][2] + rollers[j][2])){
        edges[i][j] = true;
        edges[j][i] = true;
      }
    }
  }
  /*for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cout << edges[i][j] << " ";
    }
    cout << endl;
  }*/
  visited[v] = true;
  queue<m> q;
  m a;
  a.e = v;
  a.r = 10000;
  a.t = 10000;
  q.push(a);
  while(!q.empty()){
    m b = q.front();
    q.pop();
    //cout <<  b.e << " " << b.r << " " << b.t << endl;
    if (rollers[b.e][0] == x_t && rollers[b.e][1] == y_t){
      cout << int(b.r);
      break;
    }
    for (int i = 1; i < n + 1; i++){
      if (edges[b.e][i] && !visited[i]){
        visited[i] = true;
        m c;
        c.e = i;
        c.r = b.r + (b.t*rollers[b.e][2])/rollers[i][2];
        c.t = (b.t*rollers[b.e][2])/rollers[i][2];
        q.push(c);
      }
    }
  }
}

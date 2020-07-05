#include <iostream>

using namespace std;

int paths[500][500];

int main(){
  const int INF = 1000000000;
  int n, m, t;
  cin >> n >> m >> t;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      paths[i][j] = INF;
    }
    paths[i][i] = 0;
  }
  for (int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    paths[a-1][b-1] = c;
  }
  for (int k = 0; k < n; k++){
    for (int i = 0; i < n; i++){
      if (paths[i][k] < INF){
        for (int j = 0; j < n; j++){
          paths[i][j] = min(paths[i][j], max(paths[i][k], paths[k][j]));
        }
      }
    }
  }
/*  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cout << paths[i][j] << " ";
    }
    cout << endl;
  }*/
  for (int i = 0; i < t; i++){
    int a, b;
    cin >> a >> b;
    int c = paths[a-1][b-1];
    if (c >= INF){
      c = -1;
    }
    cout << c << endl;
  }
}

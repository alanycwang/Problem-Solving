#include <iostream>

using namespace std;

bool edges[100][100];

int main(){
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    edges[a-1][b-1] = true;
    //edges[b-1][a-1] = true;
  }
  int ans = 0;
  for (int k = 0; k < n; k++){
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        if (edges[i][k] && edges[k][j]){
          edges[i][j] = true;
        }
      }
    }
  }
/*  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cout << edges[i][j] << " ";
    }
    cout << endl;
  }*/
  for (int i = 0; i < n; i++){
    bool stop = false;
    for (int j = 0; j < n; j++){
      if (i != j && !edges[i][j] && !edges[j][i]){
        stop = true;
        break;
      }
    }
    if (!stop){
      ans ++;
    }
  }
  cout << ans;
}

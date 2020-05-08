#include <iostream>

using namespace std;

int paths[100][100];

int main(){
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      paths[i][j] = 1000000000;
    }
  }
  int required[m];
  for (int i = 0; i < m; i++){
    cin >> required[i];
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> paths[i][j];
    }
  }
  for (int k = 0; k < n; k++){
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        paths[i][j] = min(paths[i][j], paths[i][k] + paths[k][j]);
      }
    }
  }
  int ans = 0;
  int last = 0;
  for (int i = 0; i < m; i++){
    ans += paths[last][required[i]-1];
    last = required[i]-1;
  }
  ans += paths[last][n-1];
  cout << ans;
}

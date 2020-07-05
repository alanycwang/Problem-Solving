#include <iostream>

using namespace std;

int main(){
  int n, c;
  cin >> n >> c;
  int w[n+1];
  w[0] = 0;
  for (int i = 1; i <= n; i++){
    cin >> w[i];
  }
  int m[][] = new int[n+1][c+1];
  for (int i = 0; i <= c; i++){
    m[0][i] = 0;
  }

  for (int i = 1; i <= n; i++){
    for (int j = 0; j <= c; j++){
      if (w[i] > j){
        m[i][j] = m[i-1][j];
      }
      else {
        m[i][j] = max(m[i-1][j], m[i-1][j-w[i]]+w[i]);
      }
    }
  }
  cout << m[n][c];
}

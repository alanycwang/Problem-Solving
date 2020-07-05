#include <iostream>
#include <string.h>

using namespace std;

long long dp[101][101];
int graph[101][101];

int main(){
  memset(dp, 0, sizeof(dp));
  int r, c, a;
  cin >> r >> c >> a;
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      cin >> graph[i][j];
    }
  }
  dp[0][0] = 1;
  for (int i = 1; i < r; i++){
    for (int j = 1; j < c; j++){
      for (int k = 0; k < i; k++){
        for (int l = 0; l < j; l++){
          if (graph[i][j] != graph[k][l]){
            dp[i][j] += (dp[k][l])%1000000007;
          }
        }
      }
    }
  }
/*  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }*/
  cout << dp[r-1][c-1] % 1000000007;
}

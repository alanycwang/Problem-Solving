#include <iostream>
#include <cstring>

using namespace std;

int dp[10001][501];
int d[1000];

int main(){
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    cin >> d[i];
  }
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++){
    dp[i][0] = dp[i-1][0];
    for (int j = 1; j <= m; j++){
      if (dp[i-1][j-1] != -1){
        dp[i][j] = max(dp[i][j], dp[i-1][j-1] + d[i-1]);
      }
      if (i-j >= 0){
        dp[i][0] = max(dp[i][0], dp[i-j][j]);
      }
    }
  }
/*  for (int i = 0; i <= m; i++){
    for (int j = 0; j <= n; j++){
      cout << dp[j][i] << " ";
    }
    cout << endl;
  }*/
  cout << dp[n][0];
}

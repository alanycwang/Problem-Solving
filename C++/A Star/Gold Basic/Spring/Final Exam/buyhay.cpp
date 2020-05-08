#include <iostream>
#include <string.h>

using namespace std;

int dp[55001][101];

int main(){
  int n, h;
  cin >> n >> h;
  int suppliers[n][2];
  int a = 0;
  for (int i = 0; i < n; i++){
    cin >> suppliers[i][0] >> suppliers[i][1];
    a = max(a, suppliers[i][0]);
  }
  for (int i = 0; i < h+a; i++){
    for (int j = 0; j < n; j++){
      dp[i][j] = 1000000000;
    }
  }
  for (int i = 0; i < n; i++){
    dp[suppliers[i][0]][i] = suppliers[i][1];
  }
  for (int i = 0; i < h+a; i++){
    for (int j = 0; j < n; j++){
      if (i-suppliers[j][0] >= 0){
        dp[i][j] = min(dp[i-suppliers[j][0]][n-1] + suppliers[j][1], dp[i][j]);
      }
      if (j > 0){
        dp[i][j] = min(dp[i][j], dp[i][j-1]);
      }
    }
  }
  int ans = 1000000000;
  for (int i = h; i < h+a; i++){
    ans = min(ans, dp[i][n-1]);
  }
  cout << ans;
}

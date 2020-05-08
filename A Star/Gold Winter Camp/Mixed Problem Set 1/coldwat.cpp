#include <iostream>
#include <string.h>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  int c[n][2];
  for (int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    c[i][0] = a;
    c[i][1] = b-a;
  }
  int dp[m+1][n+1];
  memset(dp, -1, sizeof(dp));
  memset(dp[0], 0, sizeof(dp[0]));
  for (int i = 1; i <= m; i++){
    for (int j = 0; j < n; j++){
      if (i - c[j][0] >= 0){
        dp[i][j] = dp[i-c[j][0]][n] + c[j][1];
        dp[i][n] = max(dp[i][n], dp[i][j]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= m; i++){
      ans = max(ans, dp[i][n]);
  }
  cout << ans;
}

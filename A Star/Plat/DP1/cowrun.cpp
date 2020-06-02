#include <iostream>
#include <string.h>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  int days[n];
  for (int i = 0; i < n; i++){
    cin >> days[i];
  }

  int dp[n+1];
  memset(dp, 0, sizeof(dp));
  dp[0] = 0;
  for (int i = 1; i <= n; i++){
    dp[i] = dp[i-1];
    for (int j = 1; (2*j <= i) && (j <= m); j++){
      int e = dp[i - 2*j];
      for (int k = 0; k < j; k++){
        e += days[i - 2*j + k];
      }
      dp[i] = max(dp[i], e);
    }
  }

  int ans = 0;
  for (int i = 0; i <= n; i++){
    ans = max(ans, dp[i]);
    //cout << dp[i] << " ";
  }

  cout << ans;
}

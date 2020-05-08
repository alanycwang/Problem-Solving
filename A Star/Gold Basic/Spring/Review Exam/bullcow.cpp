#include <iostream>
#include <cstring>

using namespace std;

int n, k;

int main(){
  cin >> n >> k;
  int dp[n][2];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  dp[0][1] = 1;
  for (int i = 1; i < n; i++){
    /*for (int j = 0; j < n; j++){
      cout << dp[j][0] << " " << dp[j][1] << endl;
    }*/
    dp[i][0] = dp[i-1][1];
    for (int j = 2; j < k + 1 && i - j >= 0; j++){
      dp[i][0] -= dp[i-j][0];
    }
    dp[i][1] = dp[i-1][0] + dp[i-1][1];
  }
  /*for (int j = 0; j < n; j++){
    cout << dp[j][0] << " " << dp[j][1] << endl;
  }*/
  cout << dp[n-1][0] + dp[n-1][1];
}

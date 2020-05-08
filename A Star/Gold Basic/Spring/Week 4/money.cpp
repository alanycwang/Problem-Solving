#include <iostream>
#include <string.h>

using namespace std;

int main(){
  int v, n;
  cin >> v >> n;
  int coins[v];
  for (int i = 0; i < v; i++){
    cin >> coins[i];
  }
  long long dp[v+1][n+1];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 1; i <= v; i++){
    for (int j = 0; j <= n; j++){
      if(j-coins[i-1] >= 0){
        for (int k = 0; k <= i; k++){
          dp[i][j] += dp[k][j-coins[i-1]];
        }
      }
    }
  }
/*  for (int i = 0; i <= v; i++){
    for (int j = 0; j <= n; j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }*/
  long long ans = 0;
  for (int i = 1; i <= v; i++){
    ans += dp[i][n];
  }
  cout << ans;
}

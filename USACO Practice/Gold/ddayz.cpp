//long longs aren't big enough, used python instead
#include <iostream>
#include <string.h>

using namespace std;

int main(){
  long long n, k;
  cin >> n >> k;
  long long dp[n+1][k];
  memset(dp, 0, sizeof(dp));
  /*for (long longi = 0; i < k; i++){
    dp[0][i] = 1;
  }*/
  dp[0][0] = 1;
  for (long long i = 1; i <= n; i++){
    for (long long j = 0; j < k; j++){
      for (long long l = 0; l <= j; l++){
        if (i - j - 1 >= 0){
          dp[i][j] += dp[i - j - 1][l];
        }
      }
    }
  }
  long long ans = 0;
/*  for (long long i = 0; i <= n; i++){
    for (long long j = 0; j < k; j++){
        cout << dp[i][j] << " ";
    }
    cout << endl;
  }*/
  for (long long i = 0; i < k; i++){
    ans += dp[n][i];
  }
  cout << ans;
}

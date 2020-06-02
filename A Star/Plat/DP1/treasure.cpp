#include <iostream>
#include <string.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int coins[n];
  for (int i = 0; i < n; i++){
    cin >> coins[i];
  }


  int sum[n];
  sum[0] = 0;
  for (int i = 1; i <= n; i++){
    sum[i] = coins[i-1] + sum[i-1];
  }

  int dp[n];
  for (int i = 0; i < n; i++){
    dp[i] = coins[i];
  }
  for (int i = n - 1; i >= 0; i--){
    for (int j = i+1; j < n; j++){
       dp[j] = sum[j + 1] - sum[i] - min(dp[j - 1], dp[j]);
    }
    /*for (int j = 0; j < n; j++){
      cout << dp[j] << " ";
    }
    cout << endl;*/
  }

  cout << dp[n-1];
}

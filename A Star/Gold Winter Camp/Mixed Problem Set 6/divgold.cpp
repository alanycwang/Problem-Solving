#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

int n;
int total = 0;
int coins[251];
int dp[500000];

int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> coins[i];
    total += coins[i];
  }
  for (int i = 1; i <= total*0.5+ 1; i++){
    dp[i] = 0;
  }
  dp[0] = 1;
  for (int i = 1; i <= total * 0.5 + 1; i++){
    for (int j = 0; j < n; j++){
      if (i - coins[j] >= 0){
        dp[i] += dp[i-coins[j]];
      }
    }
  }
  for (int i = 0; i < total*0.5 + 1; i++){
    cout << dp[i] << " ";
  }
  cout << endl;

  int ans = 1000000000;
  int ans2;

  for (int i = 0; i <= total*0.5 + 1; i++){
    if (dp[i] && ans > abs(total - 2*i)){
      ans = abs(total - 2*i);
      ans2 = dp[i];
    }
  }
  cout << ans << endl << ans2;
}

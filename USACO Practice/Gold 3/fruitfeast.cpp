#include <iostream>
#include <string.h>

using namespace std;

int main(){
  int t, a, b;
  cin >> t >> a >> b;

  bool dp[t+1];
  memset(dp, false, sizeof(dp));
  dp[0] = true;

  for (int i = 1; i <= t; i++){
    bool temp_a = false;
    bool temp_b = false;

    if (i-a >= 0){
      temp_a = dp[i-a];
    }

    if (i-b >= 0){
      temp_b = dp[i-b];
    }
    dp[i] = temp_a || temp_b;
  }

  for (int i = 1; i <= t; i++){
    dp[int(i/2)] = dp[int(i/2)] || dp[i];
  }

  for (int i = 1; i <= t; i++){
    bool temp_a = false;
    bool temp_b = false;

    if (i-a >= 0){
      temp_a = dp[i-a];
    }

    if (i-b >= 0){
      temp_b = dp[i-b];
    }
    dp[i] = (dp[i] || temp_a || temp_b);
  }

  for (int i = t; i >= 0; i--){
    if (dp[i]){
      cout << i;
      break;
    }
  }
}

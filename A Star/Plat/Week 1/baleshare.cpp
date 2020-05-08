#include <iostream>
#include <string.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int bales[n];
  for (int i = 0; i < n; i++){
    cin >> bales[i];
  }

  int sum = 0;
  for (int i = 0; i < n; i++){
    sum += bales[i];
  }

  bool dp[int((sum+1)/2)][int((sum+1)/3)];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = true;
  for (int i = 0; i < n; i++){
    for (int j = int((sum+1)/2)-1; j >= 0; j--){
      for (int k = int((sum+1)/3)-1; k >= 0 ; k--){
        bool b = false;
        bool c = false;
        if (j-bales[i] >= 0) b = dp[j-bales[i]][k];
        if (k-bales[i] >= 0) c = dp[j][k-bales[i]];
        dp[j][k] = (dp[j][k] || b || c);
      }
    }
  }
  int ans = 1000000000;
  for (int i = 0; i < int((sum+1)/2); i++){
    for (int j = 0; j < int((sum+1)/3); j++){
      if (dp[i][j] && i >= j && sum - i - j >= i) ans = min(ans, sum - i - j);
    }
  }

  cout << ans;
}

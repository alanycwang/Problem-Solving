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
  int dp[m+1];
  memset(dp, 0, sizeof(dp));
  int dp2[n];
  for (int i = 1; i <= m; i++){
    memset(dp2, -1, sizeof(dp2));
    for (int j = 0; j < n; j++){
      if (i - c[j][0] >= 0){
        dp2[j] = dp[i-c[j][0]] + c[j][1];
        dp[i] = max(dp[i], dp2[j]);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= m; i++){
      ans = max(ans, dp[i] + m - i);
  }
  cout << ans;
}

#include <iostream>
#include <string.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;

  int dp[2][n];
  memset(dp, 0, sizeof(dp));
  for (int i = n-2; i >= 0; i--){
    for (int j = i+1; j < n; j++){
      if (s[i] == s[j]) dp[i%2][j] = dp[(i+1)%2][j-1];
      else dp[i%2][j] = 1 + min(dp[(i+1)%2][j], dp[i%2][j-1]);
    }
  }

  cout << dp[0][n-1];
}

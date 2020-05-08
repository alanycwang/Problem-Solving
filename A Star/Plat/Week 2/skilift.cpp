#include <iostream>
#include <string.h>
#include <limits.h>

using namespace std;

long long dp[5001];
int heights[5001];

int main(){
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++){
    cin >> heights[i];
  }

  dp[0] = 1;
  for (int i = 1; i < n; i++){
    dp[i] = LLONG_MAX;
  }
  for (int i = 1; i < n; i++){
    int tallest = i-1;
    dp[i] = dp[i-1] + 1;
    for (int j = 2; j <= k && i - j >= 0; j++){
      if (int64_t(tallest - (i - j))*int64_t(heights[i] - heights[i - j]) >= int64_t(heights[tallest] - heights[i - j])*int64_t(j)){
        dp[i] = min(dp[i], dp[i - j] + 1);
        tallest = i-j;
      }
    }
    //cout << dp[i] << " ";
  }

  cout << dp[n-1];
}

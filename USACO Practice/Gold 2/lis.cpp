#include <iostream>

using namespace std;

int dp[20001];

int main(){
  int n;
  cin >> n;
  int val[n];
  for (int i = 0; i < n; i++){
    cin >> val[i];
  }
  for (int i = 0; i < n; i++){
    dp[i] = 1;
  }
  for (int i = 0; i < n; i++){
    for (int j = i-1; j >= 0; j--){
      if (val[j] < val[i]){
        //cout << val[i] << " " << val[j] << endl;
        dp[i] = max(dp[j] + 1, dp[i]);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i < n; i++){
    ans = max(ans, dp[i]);
  }
  cout << ans;
}

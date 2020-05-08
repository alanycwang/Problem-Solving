#include <iostream>
#include <string.h>

using namespace std;

int dp[5000][5000];
int coins[5000];

int f(int l, int r){
  if (dp[l][r] != -1){
    return dp[l][r];
  }
  if (l == r) return 0;
  int total = 0;
  for (int i = l; i <= r; i++){
    total += coins[i];
  }
  int ans = total - max(f(l + 1, r), f(l, r - 1));
  dp[l][r] = ans;
  return ans;
}

int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> coins[i];
  }

  memset(dp, -1, sizeof(dp));
  cout << f(0, n-1);
}

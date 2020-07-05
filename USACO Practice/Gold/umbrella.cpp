#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  int cows[n];
  int cost[m];
  for (int i = 0; i < n; i++){
    cin >> cows[i];
  }
  for (int j = 0; j < m; j++){
    cin >> cost[j];
  }
  sort(cows, cows+n);
  int dp[n+1];
  for (int i = 1; i <= n; i++){
    dp[i] = 1000000000;
  }
  dp[0] = 0;
  for (int i = 1; i <= n; i++){
    for (int j = 0; j < i; j++){
      dp[i] = min(dp[i], dp[j] + cost[cows[i-1] - cows[j]]);
    }
  }
/*  for (int i = 0; i <= n; i++){
    cout << dp[i] << " ";
  }
  cout << endl;*/
  cout << dp[n];
}

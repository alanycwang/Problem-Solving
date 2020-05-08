#include <iostream>
#include <algorithm>

using namespace std;

int dp[20000][15];

int main(){
  int n, k;
  cin >> k >> n;
  for(int i = 0; i < 20000; i++){
    for (int j = 0; j < n; j++){
      dp[i][j] = 1000000000;
    }
  }
  int stamps[n];
  for (int i = 0; i < n; i++){
    cin >> stamps[i];
  }
  sort(stamps, stamps+n);
  int ans = 1;
  dp[0][0] = 1;
  for (int i = 1; i < n; i++){
    dp[0][i] = 0;
  }
  for (; true; ans++){
    for (int i = 0; i < n; i++){
      //cout << i << " " << ans << endl;
      if (ans - stamps[i] >= 0){
        for (int j = 0; j < n; j++){
          dp[ans][i] = min(dp[ans][i], dp[ans-stamps[i]][j] + 1);
        }
      }
    }
    bool a = true;
    for (int i = 0; i < n; i++){
      cout << dp[ans][i] << endl;
      if (dp[ans][i] <= k){
        a = false;
        break;
      }
    }
    if (a){
      break;
    }
    cout << endl;
  }
  cout << ans - 1;
}

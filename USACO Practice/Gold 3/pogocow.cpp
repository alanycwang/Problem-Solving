#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
  return b.first < a.first;
}

int main(){
  int n;
  cin >> n;
  pair<int, int> targets[n];
  for (int i = 0; i < n; i++){
    cin >> targets[i].first >> targets[i].second;
  }

  sort (targets, targets + n);

  int dp[n][n];
  memset(dp, 0, sizeof(dp));

  for (int i = 0; i < n; i++){
    for (int j = 0; j <= i; j++){
      for (int k = 0; k <= j; k++){
        if (targets[i].first - targets[j].first >= targets[j].first - targets[k].first){
          dp[i][j] = max(dp[i][j], dp[j][k] + targets[i].second);
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      //cout << dp[i][j] << " ";
      ans = max(ans, dp[i][j]);
    }
    //cout << endl;
  }

sort (targets, targets + n, compare);

  memset(dp, 0, sizeof(dp));

  for (int i = 0; i < n; i++){
    for (int j = 0; j <= i; j++){
      for (int k = 0; k <= j; k++){
        if (targets[i].first - targets[j].first <= targets[j].first - targets[k].first){
          dp[i][j] = max(dp[i][j], dp[j][k] + targets[i].second);
        }
      }
    }
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      //cout << dp[i][j] << " ";
      ans = max(ans, dp[i][j]);
    }
    //cout << endl;
  }
  cout << ans << endl;
}

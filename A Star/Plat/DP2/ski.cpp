#include <iostream>
#include <string.h>

using namespace std;

int main(){
  int t, s, n;
  cin >> t >> s >> n;
  int classes[s][3];
  for (int i = 0; i < s; i++){
    for (int j = 0; j < 3; j++){
      cin >> classes[i][j];
    }
  }
  int slopes[n][2];
  for (int i = 0; i < n; i++){
    cin >> slopes[i][0] >> slopes[i][1];
  }

  int best[100];
  for (int i = 0; i < 100; i++) {
    best[i] = 1000000000;
    for (int j = 0; j < n; j++){
      if (slopes[j][0]-1 <= i) best[i] = min(best[i], slopes[j][1]);
    }
  }

  /*for (int i = 0; i < 100; i++){
    cout << best[i] << " ";
  }*/

  int dp[t+1][100];
  dp[0][0] = 0;
  for (int i = 1; i < 100; i++){
    dp[0][i] = -1000000000;
  }
  for (int i = 1; i <= t; i++){
    for (int j = 0; j < 100; j++){
      dp[i][j] = dp[i-1][j];
      if (i-best[j] >= 0) dp[i][j] = max(dp[i][j], dp[i-best[j]][j] + 1);
      for (int k = 0; k < s; k++){
        if (classes[k][0] + classes[k][1] == i && classes[k][2] == j) {
          for (int l = 0; l < j; l++){
            dp[i][j] = max(dp[i][j], dp[i-classes[k][1]][l]);
          }
        }
      }
    }
  }

/*  for (int i = 0; i < t; i++){
    for (int j = 0; j < 100; j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }*/

  int ans = 0;
  for (int i = 0; i < 100; i++){
    ans = max(ans, dp[t][i]);
  }
  cout << ans;
}

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  int points[n][2];
  for (int i = 0; i < n; i++){
    cin >> points[i][0] >> points[i][1];
  }
  int dp[k+1][n];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i < n; i++){
    dp[0][i] = abs(points[i][0] - points[i-1][0]) + abs(points[i][1] - points[i-1][1]) + dp[0][i-1];
  }
  for (int i = 1; i <= k; i++){
    for (int j = 1; j < n; j++){
      dp[i][j] = dp[i][j-1] + abs(points[j][0]-points[j-1][0]) + abs(points[j][1] - points[j-1][1]);
      for (int k = 1; k <= i; k++){
        if (j-k-1 >= 0){
          dp[i][j] = min(dp[i][j], dp[i-k][j-k-1] + abs(points[j-k-1][0] - points[j][0]) + abs(points[j-k-1][1] - points[j][1]));
        }
      }
    }
  }
/*  for (int i = 0; i < k+1; i++){
    for (int j = 0; j < n; j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }*/
  cout << dp[k][n-1];
}

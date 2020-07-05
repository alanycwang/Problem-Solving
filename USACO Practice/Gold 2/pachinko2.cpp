#include <iostream>

using namespace std;

int dp[101][101];

int main(){
  int n;
  cin >> n;
  int val[n][n];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < i + 1; j++){
      cin >> val[i][j];
    }
  }
  for (int i = n-1; i > -1; i--){
    for (int j = 0; j < i + 1; j++){
      dp[i][j] = val[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
    }
  }
  cout << dp[0][0];
}

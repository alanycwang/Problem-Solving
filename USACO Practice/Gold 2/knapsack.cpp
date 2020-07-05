#include <iostream>

using namespace std;

int v[1000];
int s[1000];
int dp[1001][5001];

int main(){
  int n, c;
  cin >> n >> c;
  for (int i = 0; i < n; i++){
    cin >> s[i] >> v[i];
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= c; j++){
      if (j-s[i-1] >= 0){
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-s[i-1]] + v[i-1]);
        continue;
      }
      dp[i][j] = dp[i-1][j];
    }
  }
/*for (int i = 0; i<= n; i++){
    for (int j = 0; j < c; j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }*/
  cout << dp[n][c];
}

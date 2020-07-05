#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  if (int((float(n)/2)*(n+1))%2 != 0){
    cout << 0;
    return 0;
  }
  int dp[n+1][int(((float(n)/2)*(n+1))+1)];
  for (int i = 0; i <= n; i++){
    for (int j = 0; j <= ((n/2)*(n+1)); j++){
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= int((float(n)/2)*(n+1)); j++){
      dp[i][j] += dp[i-1][j];
      if (j-i >=0){
        dp[i][j] += dp[i-1][j-i];
      }
    }
/*for (int k = 0; k <= n; k++){
      for (int l = 0; l <= int((float(n)/2)*(n+1)); l++){
        printf("%3d ", dp[k][l]);
      }
      cout << endl;
    }
    cout << endl;*/
  }
  cout << dp[n][int((float(n)/2)*(n+1))/2];
}

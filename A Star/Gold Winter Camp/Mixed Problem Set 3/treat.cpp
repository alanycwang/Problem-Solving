#include <iostream>
#include <string.h>

using namespace std;

int dp[2001][2001];

int main(){
  int n;
  cin >> n;
  int treats[n];
  for (int i = 0; i < n; i++){
    cin >> treats[i];
  }
  for (int i = 0; i < n; i++){

  }
  for (int i = n-1; i >= 0; i--){
    for (int j = i; j < n; j++){
      int a, b;
      a = -1; b = -1;
      if (i+1 < n){
        a = dp[i + 1][j] + treats[i] * (n - j + i);
      }
      if (j-1 >= 0){
        b = dp[i][j - 1] + treats[j] * (n - j + i);
      }
      dp[i][j] = max(a, b);
    }
  }
/*  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (dp[i][j] >= 1000000000){
        cout << "inf" << " ";
        continue;
      }
      printf("%3d ", dp[i][j]);
    }
    cout << endl;
  }*/
  cout << dp[0][n-1];
}

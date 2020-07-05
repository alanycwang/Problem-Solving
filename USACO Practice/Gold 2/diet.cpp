#include <iostream>
#include <string.h>

using namespace std;

int main(){
  int h, n;
  int bales[n];
  for (int i = 0; i < n; i++){
    cin >> bales[i];
  }
  int dp[n+1][h+1];
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++){
    for (int j = 0; j <= h; j++{
      if (j-bales[i-1] >= 0){
        for (int k = 0; k <= n; k++){
          if ()
            dp[i][j] = max(dp[i][j], dp[])
        }
      }
    }
  }
}

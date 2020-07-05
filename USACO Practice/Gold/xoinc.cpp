#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int c[n];
  for (int i = 0; i < n; i++){
    cin >> c[i];
  }
  int m = int(log(n) / log(2) + 1);
  int dp[n][m];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){

    }
  }
}

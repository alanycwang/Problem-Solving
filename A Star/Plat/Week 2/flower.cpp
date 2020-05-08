#include <iostream>
#include <string.h>

using namespace std;

int main(){
  int f, v;
  cin >> f >> v;
  int value[f][v];
  for (int i = 0; i < f; i++){
    for (int j = 0; j < v; j++){
      cin >> value[i][j];
    }
  }

  int dp[2][f];
  memset(dp, -1, sizeof(dp));
  dp[0][0] = value[0][0];
  for (int i = 1; i < v; i++){
    dp[i%2][0] = max(dp[(i-1)%2][0], value[0][i]);
    for (int j = 1; j < f; j++){
      if (i >= j) dp[i%2][j] = max(dp[(i-1)%2][j], dp[(i-1)%2][j-1] + value[j][i]);
    }

    /*for (int j = 0; j < f; j++){
      cout << dp[i%2][j] << " ";
    }
    cout << endl;*/
  }

  cout << dp[(v-1)%2][f-1];
}

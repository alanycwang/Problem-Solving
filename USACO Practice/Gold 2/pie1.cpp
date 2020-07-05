#include <iostream>

using namespace std;

int main(){
  int r, c;
  cin >> r >> c;
  int field[r][c];
  int dp[r][c];
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      cin >> field[i][j];
      if ((c-j)+i < r){
        field[i][j] = -1;
        dp[i][j] = -1;
      }
      else{
        dp[i][j] = field[i][j];
      }
    }
  }
  for (int j = c-2; j >= 0; j--){
    for (int i = 0; i < r; i++){
      if ((c-j)+i < r){
        continue;
      }
      int a = -1;
      int b = -1;
      int c = dp[i][j+1];
      if (i < r-1){
        a = dp[i+1][j+1];
      }
      if (i > 0){
        b = dp[i-1][j+1];
      }
      dp[i][j] = max(a, max(b, c)) + field[i][j];
    }
  }
/*  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }*/
  cout << dp[0][0];
}

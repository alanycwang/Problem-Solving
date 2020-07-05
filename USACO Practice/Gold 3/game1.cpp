#include <iostream>
#include <string.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int board[n];
  int total = 0;
  for (int i = 0; i < n; i++){
    cin >> board[i];
    total += board[i];
  }
  int dp[n];
  for (int i = 0; i < n; i++){
    dp[i] = 0;
  }

  for (int i = n-1; i >= 0; i--){
    for (int j = i; j < n; j++){
      dp[j] = max(board[i] - dp[j], board[j] - dp[j-1]);
    }
  }
  cout << (total + dp[n-1])/2 << " " << (total - dp[n-1])/2 << endl;
}

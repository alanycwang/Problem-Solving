#include <iostream>
#include <cstring>

using namespace std;

int main(){
  string a;
  string b;
  cin >> a >> b;
  int dp[2][b.length() + 1];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i < a.length()+1; i++){
    for (int j = 1; j < b.length()+1; j++){
      if (a[i-1] == b[j-1]){
        dp[i%2][j] = max(dp[i%2][j-1], max(dp[(i-1)%2][j], dp[(i-1)%2][j-1] + 1));
      }
      else{
        dp[i%2][j] = max(dp[i%2][j-1], max(dp[(i-1)%2][j], dp[(i-1)%2][j-1]));
      }
    }
  }
  cout << dp[0][b.length()];
}

#include <bits/stdc++.h>

using namespace std;

string s1;
string s2;
int dp[1000][1000];

int recurse(int r, int c){
  //cout << r << " " << c << endl;
  if (r <= -1 || c <= -1){
    return 0;
  }
  if (dp[r][c] > -1){
    return dp[r][c];
  }
  int a = -1;
  if (s1[r] == s2[c]){
    a = recurse(r-1, c-1) + 1;
  }
  int ans = max(recurse(r-1, c), max(recurse(r, c-1), a));
  dp[r][c] = ans;
  return ans;
}

int main(){
  memset(dp, -1, sizeof(dp));
  cin >> s1 >> s2;
  cout << recurse(s1.length()-1, s2.length()-1) << endl;
/*for (int i = 0; i < s1.length(); i++){
    for (int j = 0; j < s2.length(); j++){
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }*/
}

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin >> n;
  pair<int, int> p[n];
  for (int i = 0; i < n; i++){
    int temp;
    cin >> temp;
    p[i] = make_pair(temp, i);
  }
  int t[n][n];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> t[i][j];
    }
  }


  sort(p, p+n);
  int dp[n];
  for (int i = 1; i < n; i++){
    dp[i] = -1000000000;
    //dp[i] = 0;
  }
  dp[0] = 0;
  for (int i = 0; i < n; i++){
    if (p[i].second == 0){
      dp[0] = 1;
    }
    for (int j = 0; j < n; j++){
      if (i != j && (p[j].first + t[p[j].second][p[i].second] <= p[i].first || (i == 0 && p[j].second == 0 && t[0][p[i].second] <= p[i].first))){
        //cout << p[i].first << " " << p[j].first << " " << p[j].first + t[p[j].second][p[i].second] << endl;
        //cout << p[i].second << " " << p[j].second << endl;
        dp[p[i].second] = max(dp[p[i].second], dp[p[j].second] + 1);
      }
    }
    if (t[0][p[i].second] <= p[i].first) dp[p[i].second] = max(dp[p[i].second], 1);
  }

  int ans = 0;
  for (int i = 0; i < n; i++){
    //cout << dp[i] << endl;
    ans = max(ans, dp[i]);
  }
  cout << ans;
}

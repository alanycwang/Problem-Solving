#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main(){
  int n, t, k;
  cin >> n >> t >> k;
  int blocks[n][2];
  for (int i = 0; i < n; i++){
    cin >> blocks[i][0] >> blocks[i][1];
  }
  vector<pair<int, int>> sblocks;
  vector<pair<int, int>> lblocks;
  for (int i = 0; i < n; i++){
    if (blocks[i][0] < k){
      sblocks.push_back(make_pair(blocks[i][0], blocks[i][1]));
    }
    else{
      lblocks.push_back(make_pair(blocks[i][0], blocks[i][1]));
    }
  }
  int ans = 0;
  int ns = sblocks.size();
  int dp[t+1][ns];
  memset(dp, 0, sizeof(dp));
  for (int i = 1; i <= t; i++){
    for (int j = 0; j < ns; j++){
      if (i - sblocks[j].second >= 0){
        dp[i][j] = 0;
        for (int k = 0; k < ns; k++){
          dp[i][j] = max(dp[i][j], dp[i-sblocks[j].second][k] + sblocks[j].first);
        }
      }
    }
  }
  for (int i = 0; i < ns; i++){
    ans = max(ans, dp[t][i]);
  }
  cout << "working" << endl;
  for (int k = 0; k < lblocks.size(); k++){
    int dp2[t+1-lblocks[k].second][n];
    memset(dp2, 0, sizeof(dp2));
    for (int i = 1; i <= t; i++){
      for (int j = 0; j < n; j++){
        if (i - blocks[j][1]*.8 >= 0){
          dp2[i][j] = 0;
          for (int l = 0; l < n; l++){
            dp2[i][j] = max(dp2[i][j], dp2[i-int(blocks[j][1]*.8)][l] + blocks[j][0]);
          }
        }
      }
    }
    cout << "working" << endl;
    for (int i = 0; i < n; i++){
      ans = max(ans, dp2[t][i] + lblocks[k].first);
    }
  }
  cout << ans;
}

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main(){
  int n, v;
  cin >> n >> v;
  pair<int, pair<int, vector<pair<int, int>>>> consoles[n];
  for (int i = 0; i < n; i++){
    int p_i, g_i;
    cin >> p_i >> g_i;
    vector<pair<int, int>> games;
    for (int j = 0; j < g_i; j++){
      pair<int, int> game;
      cin >> game.first >> game.second;
      games.push_back(game);
    }
    consoles[i] = make_pair(p_i, make_pair(g_i, games));
  }

/*  for (int i = 0; i < n; i++){
    cout << consoles[i].first << " " << consoles[i].second.first << " ";
    for (int j = 0; j < consoles[i].second.first; j++){
      cout << consoles[i].second.second[j].first << " " << consoles[i].second.second[j].second << " ";
    }
    cout << endl;
  }*/
  int dp[n][1001][11];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++){
    dp[i][0][0] = 0;
    for (int j = 1; j <= 1000; j++){
      for (int k = 1; k <= consoles[i].second.first; k++){
        dp[i][j][k] = dp[i][j][k-1];
        if (j - consoles[i].second.second[k-1].first >= 0) dp[i][j][k] = max(dp[i][j - consoles[i].second.second[k-1].first][k-1] + consoles[i].second.second[k-1].second, dp[i][j][k]);
      }
    }
  }
  vector<pair<int, int>> sets[n];
  for (int i = 0; i < n; i++){
    for (int j = 1; j <= 1000; j++){
      bool ok = false;
      for (int k = 1; k <= consoles[i].second.first; k++){
        if (dp[i][j][k] != dp[i][j-1][k]) {
          ok = true;
          break;
        }
      }
      if (ok){
        /*cout << j << " ";
        for (int k = 1; k <= consoles[i].second.first; k++){
          cout << dp[i][j][k] << " ";
        }*/
        sets[i].push_back(make_pair(dp[i][j][consoles[i].second.first], j));
        //cout << endl;
      }
    }
    //cout << endl << endl << endl;
  }

  int dp2[v+1][n+1];
  memset(dp2, 0, sizeof(dp2));
  for (int i = 1; i <= v; i++){
    for (int j = 1; j <= n; j++){
      dp2[i][j] = dp2[i][j-1];
      for (pair<int, int> k : sets[j-1]){
        if (i-k.second-consoles[j-1].first >= 0){
          dp2[i][j] = max(dp2[i][j], dp2[i-k.second-consoles[j-1].first][j-1] + k.first);
        }
      }
    }
  }
  /*for (int i = 0; i <= v; i++){
    cout << i << " ";
    for (int j = 0; j <= n; j++){
      cout << dp2[i][j] << " ";
    }
    cout << endl;
  }*/
  cout << dp2[v][n];
}

#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int r = 0;
int words[5000][2];
char lines[100000];

int f(vector<pair<int, int>> words){
  int dp[words.length()][k];
  for (int i = 0; i < n; i++)
}

int main(){
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++){
    cin >> words[i][0] >> words[i][1];
    r = max(words[i][1], r);
  }
  for (int i = 0; i < m; i++){
    cin >> lines[i];
  }
}

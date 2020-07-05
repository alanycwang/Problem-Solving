#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

int main(){
  string pathf;
  string pathb;
  int lenf;
  int lenb;
  int n, m;
  cin >> n >> m;
  pair<int, int> b;
  pair<int, int> f;
  cin >> f.first >> f.second >> b.first >> b.second;
  cin >> pathf >> pathb;
  lenf = pathf.length();
  lenb = pathb.length();
  int dp[lenf+1][lenb+1];
  pair<int, int> lb[lenb+1];
  pair<int, int> lf[lenf+1];
  memset(dp, -1, sizeof(dp));
  lf[0] = make_pair(f.first, f.second);
  lb[0] = make_pair(b.first, b.second);
  for (int i = 1; i <= pathf.length(); i++){
    pair<int, int> temp = lf[i-1];
    if (pathf[i-1] == 'N') lf[i] = make_pair(temp.first, temp.second + 1);
    else if (pathf[i-1] == 'S') lf[i] = make_pair(temp.first, temp.second - 1);
    else if (pathf[i-1] == 'E') lf[i] = make_pair(temp.first + 1, temp.second);
    else lf[i] = make_pair(temp.first-1, temp.second);
  }
  for (int i = 1; i <= pathb.length(); i++){
    pair<int, int> temp = lb[i-1];
    if (pathb[i-1] == 'N') lb[i] = make_pair(temp.first, temp.second + 1);
    else if (pathb[i-1] == 'S') lb[i] = make_pair(temp.first, temp.second - 1);
    else if (pathb[i-1] == 'E') lb[i] = make_pair(temp.first + 1, temp.second);
    else {lb[i] = make_pair(temp.first-1, temp.second);}
  }
  dp[0][0] = 0;
  for (int i = 0; i <= lenf; i++){
    for (int j = 0; j <= lenb; j++){
      int x, y, z;
      x = 1000000000; y = 1000000000; z = 1000000000;
      if (i-1 >= 0 && j-1 >= 0){
        x = dp[i-1][j-1];
        y = dp[i-1][j];
        z = dp[i][j-1];
      }
      else if (i-1 >= 0){
        y = dp[i-1][j];
      }
      else if (j-1 >= 0){
        z = dp[i][j-1];
      }
      else {
        continue;
      }
      dp[i][j] = min(x, min(y, z)) + pow(lb[j].first - lf[i].first, 2) + pow(lb[j].second - lf[i].second, 2);
    }
  }
  cout << dp[lenf][lenb];
}

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

struct store{
  int x, f, c;
};

bool compare(store a, store b){
  if (a.x == b.x){
    return a.c < b.c;
  }
  return a.x < b.x;
}

int main(){
  int k, e, n;
  cin >> k >> e >> n;
  store stores[n+1];
  for (int i = 0; i < n; i++){
    cin >> stores[i].x;
    cin >> stores[i].f;
    cin >> stores[i].c;
  }
  stores[n].x = 0;
  stores[n].f = 0;
  stores[n].c = 0;

  sort(stores, stores + n + 1, compare);

  int dp[n+1][k+1];
  for (int i = 0; i <= n; i++){
    dp[i][0] = 0;
  }
  for (int i = 0; i <= n; i++){
    for (int j = 1; j <= k; j++){
      dp[i][j] = 1000000000;
    }
  }

  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= k; j++){
      for (int l = 0; l <= stores[i].f && l <= j; l++){
        dp[i][j] = min(dp[i][j], dp[i-1][j-l] + (stores[i].x - stores[i-1].x )*(j-l) + stores[i].c * l);
      }
    }
  }

  int ans = 1000000000;

  for (int i = 1; i <= n; i++){
    ans = min(ans, dp[i][k] + k*(e - stores[i].x));
  }
  cout << ans << endl;
}

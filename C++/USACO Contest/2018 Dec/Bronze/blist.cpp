#include <bits/stdc++.h>

using namespace std;

int times[1001];

int main(){
  freopen("blist.in", "r", stdin);
  freopen("blist.out", "w", stdout);
  int n;
  cin >> n;
  int input[n][3];
  int x = 0;
  for (int i = 0; i < n; i++){
    cin >> input[i][0] >> input[i][1] >> input[i][2];
    x = max(x, input[i][1]);
  }
  for (int i = 0; i < n; i++){
    for (int j = input[i][0]; j < input[i][1]; j++){
      times[j] += input[i][2];
    }
  }
  int ans = 0;
  for (int i = 1; i < x; i++){
    ans = max(ans, times[i]);
  }
  cout << ans;
}

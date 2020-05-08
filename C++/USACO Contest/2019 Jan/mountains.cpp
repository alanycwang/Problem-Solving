#include <bits/stdc++.h>

using namespace std;

int main(){
  freopen("mountains.in", "r", stdin);
  freopen("mountains.out", "w", stdout);
  int n;
  cin >> n;
  int peaks[n][2];
  for (int i = 0; i < n; i++){
    cin >> peaks[i][0] >> peaks[i][1];
  }
  int ans = n;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (i != j  && abs(peaks[i][0] - peaks[j][0]) <= peaks[j][1] - peaks[i][1]){
        //cout << i << " " << j << endl;
        ans--;
        break;
      }
    }
  }
  cout << ans << endl;
}

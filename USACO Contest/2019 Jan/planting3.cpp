#include <bits/stdc++.h>

using namespace std;

int main(){
  /*freopen("planting.in", "r", stdin);
  freopen("planting.out", "w", stdout);*/
  int n;
  cin >> n;
  int paths[n-1][2];
  int fields[n];
  memset (fields, 0, sizeof(fields));
  for (int i = 0; i < n-1; i++){
    int x, y;
    cin >> x >> y;
    x--; y--;
    paths[i][0] = x;
    paths[i][1] = y;
  }
  int ans = 0;
  for (int i = 0; i < n; i++){
    int x = 1;
    fields[i] = x;
    for (int j = 0; j < n-1; j++){
      if (paths[j][0] == i && fields[i] == fields[paths[j][1]]){
        x++;
        ans = max(ans, x);
        fields[i] = x;
      }
      if (paths[j][1] == i && fields[i] == fields[paths[j][0]]){
        x++;
        ans = max(ans, x);
        fields[i] = x;
      }
      for (int k = 0; k < n-1; k++){
        if (paths[k][0] == j && fields[i] == fields[paths[k][1]]){
          x++;
          ans = max(ans, x);
          fields[i] = x;
        }
        if (paths[k][1] == j && fields[i] == fields[paths[k][0]]){
          x++;
          ans = max(ans, x);
          fields[i] = x;
        }
      }
    }
  }
  cout << ans << endl;
}

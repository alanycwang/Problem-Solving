#include <bits/stdc++.h>

using namespace std;

int main(){
  freopen("mixmilk.in", "r", stdin);
  freopen("mixmilk.out", "w", stdout);
  int buckets[3][2];
  for (int i = 0; i < 3; i++){
    cin >> buckets[i][0] >> buckets[i][1];
  }
  int x = 0;
  int y = 1;
  for (int i = 0; i < 100; i++){
    if (buckets[x][1] >= buckets[y][0] - buckets[y][1]){
      buckets[x][1] -= buckets[y][0] - buckets[y][1];
      buckets[y][1] = buckets[y][0];
    }
    else {
      buckets[y][1] += buckets[x][1];
      buckets[x][1] = 0;
    }
    x++;
    y++;
    if (x >= 3){
      x = 0;
    }
    if (y >= 3){
      y = 0;
    }
  }
  for (int i = 0; i < 3; i++){
    cout << buckets[i][1] << endl;
  }
}

#include <bits/stdc++.h>
#include <vector>

using namespace std;

int buckets [20][2];
int farms[2];

int main(){
  freopen("backforth.in", "r", stdin);
  freopen("backforth.out", "w", stdout);
  int ans = 0;
  vector<int> possible;
  for (int i = 0; i < 10; i++){
    cin >> buckets[i][0];
    buckets[i][1] = 0;
  }
  for (int i = 0; i < 10; i++){
    cin >> buckets[i + 10][0];
    buckets[i + 10][1] = 1;
  }
  farms[0] = 1000;
  farms[1] = 1000;
  for (int i = 0; i < 20; i++){
    if (buckets[i][1] == 0){
      farms[0] -= buckets[i][0];
      buckets[i][1] = 1;
      for (int j = 0; j < 20; j++){
        if(buckets[j][1] == 1){
          farms[0] += buckets[j][0];
          buckets[j][1] = 0;
          for (int k = 0; k < 20; k++){
            if (buckets[k][1] == 0){
              farms[0] -= buckets[k][0];
              buckets[k][1] = 1;
              for (int l = 0; l < 20; l++){
                if (buckets[l][1] == 1){
                  bool x = false;
                  farms[0] += buckets[l][0];
                  buckets[l][1] = 0;
                  for (auto m : possible){
                    if (farms[0] == m){
                      x = true;
                    }
                  }
                  if (!x){
                    ans++;
                    possible.push_back(farms[0]);
                  }
                  buckets[l][1] = 1;
                  farms[0] -= buckets[l][0];
                }
              }
              buckets[k][1] = 0;
              farms[0] += buckets[k][0];
            }
          }
          buckets[j][1] = 1;
          farms[0] -= buckets[j][0];
        }
      }
      buckets[i][1] = 0;
      farms[0] += buckets[i][0];
    }
  }
  cout << ans;
}

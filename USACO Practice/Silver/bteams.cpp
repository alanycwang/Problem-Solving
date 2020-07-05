#include <iostream>
#include <algorithm>

using namespace std;

int tskill[4] = {0, 0, 0, 0};
int sz[4] = {0, 0, 0, 0};
int cowSkills[12];
int ans = 1000000;

void recurse(int ind){
  if (ind == 12){
    for (int i = 0; i < 4; i++){
      if (sz[i] != 3){
        return;
      }
    }
    int x[4];
    for (int i = 0; i < 4; i++){
      x[i] = tskill[i];
    }
    sort(x, x+4);
    if (x[3] - x[0] < ans){
      ans = x[3] - x[0];
    }
    return;
  }
  for (int i = 0; i < 4; i++){
    sz[i]++;
    tskill[i] += cowSkills[ind];
    recurse(ind+1);
    sz[i]--;
    tskill[i] -= cowSkills[ind];
  }
}
int main(){
  for (int i = 0; i < 12; i++){
    cin >> cowSkills[i];
  }
  recurse(0);
  cout << ans;
}

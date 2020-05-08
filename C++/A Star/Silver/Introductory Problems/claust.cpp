#include <iostream>
#include <cmath>
#include <algorithm>

struct cow{
  int x;
  int y;
  int index;
};

using namespace std;

int main(){
  int n;
  long long maximum = 214748364;
  int ans[2];
  cin >> n;
  cow cows[n];
  for (int i = 0; i < n; i++){
    cin >> cows[i].x;
    cin >> cows[i].y;
    cows[i].index = i;
  }
  for (int i = 0; i < n; i++){
    for (int j = i; j < n; j++){
      long long distance = pow(cows[i].x - cows[j].x, 2) + pow(cows[i].y - cows[j].y, 2);
      if (distance < maximum && cows[i].index != cows[j].index){
        maximum = distance;
        ans[0] = cows[j].index;
        ans[1] = cows[i].index;
      }
    }
  }
  sort(ans, ans+2);
  cout << ans[0]+1 << " " << ans[1]+1;
}

#include <iostream>
#include <cmath>
#include <string>
#include <string.h>

using namespace std;

bool dp[1000001];
int last = 0;

bool win(int n){
  dp[0] = 0;
  for (int i = last + 1; i <= n; i++){
    int mind = 10;
    int maxd = 0;
    int temp = i;
    while(temp){
      if (temp%10 != 0){
        maxd = max(maxd, temp % 10);
        mind = min(mind, temp % 10);
      }
      temp -= temp%10;
      temp /= 10;
    }
    //cout << i << " " << mind << " " << maxd << endl;
    if ((maxd != 0 && !dp[i-maxd]) || (mind != 10 && !dp[i-mind])) dp[i] = true;
    else dp[i] = false;
  }
  last = n;
  return dp[n];
}

int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    int a;
    cin >> a;
    if (win(a)){cout << "YES" << endl;}
    else {cout << "NO" << endl;}
  }
}

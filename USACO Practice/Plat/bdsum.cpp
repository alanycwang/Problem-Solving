#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int n, s;
int dp[10];
bool used[10];
int sum = 0;
vector<int> perm;
bool done = false;

void f(int x) {
  if (done) return;
  if (x == n) {
    if (sum == s) {
      for (int i = 0; i < n; i++){
        cout << perm[i] << " ";
      }
      done = true;
    }
    return;
  }

  for (int i = 0; i < n; i++){
    if (!used[i]){
      used[i] = true;
      perm.push_back(i + 1);
      sum += dp[x]*(i + 1);
      f(x + 1);
      sum -= dp[x]*(i + 1);
      perm.pop_back();
      used[i] = false;
    }
  }
}

int main(){
  cin >> n >> s;

  dp[n-1] = 1;
  for (int i = 0; i < n-1; i++){
    for (int j = 0; j < n-1; j++){
      dp[j] = dp[j] + dp[j+1];
    }
  }

  f(0);
}

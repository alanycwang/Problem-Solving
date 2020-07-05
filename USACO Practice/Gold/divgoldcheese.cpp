#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  int coins[n];
  int total = 0;
  for (int i = 0; i < n; i++){
    cin >> coins[i];
    total += coins[i];
  }

  int ans = 1000000000;
  int ways = 0;

  for (int i = 0; i < (1 << n); i++){
    int sum = 0;
    for (int j = 0; j < n; j++){
      int temp = i >> j;
      if (temp & 1){
        sum += coins[j];
      }
    }
    if (abs(total - 2*sum) < ans){
      ans = abs(total - 2*sum);
      ways = 1;
    }
    else if (sum == ans){
      ways++;
    }
  }
  cout << ans << endl << ways;
}

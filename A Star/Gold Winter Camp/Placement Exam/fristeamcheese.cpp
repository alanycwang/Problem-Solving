#include <iostream>

using namespace std;

int main(){
  int n, f;
  cin >> n >> f;
  int cows[n];
  for (int i = 0; i < n; i++){
    cin >> cows[i];
  }
  long long ans = 0;
  for (int i = 0; i < ( 1 << n); i++){
    long long sum = 0;
    for (int j = 0; j < n; j++){
      long long tmp = i >> j;
      if (tmp & 1){
        sum += cows[j];
      }
    }
    if (sum % f == 0 && sum != 0){
      ans++;
    }
  }
  cout << ans%100000000;
}

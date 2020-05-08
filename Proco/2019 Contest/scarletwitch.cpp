#include <bits/stdc++.h>

using namespace std;

int main(){
  long long n;
  cin >> n;
  string a;
  cin >> a;
  int x = 0;
  long long ans = 0;
  for (long long i = 0; i < n; i++){
    if (a[i] == '1' && x != 1){
      x = 1;
    }
    if (a[i] == '0' && x == 1 && (i == n-1 || a[i+1] == '1')){
      ans++;
      //cout << a << endl;
    }
  }
  cout << ans;
  return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
  //freopen("haircut.in", "r", stdin);
  //freopen("haircut.out", "w", stdout);
  long long n;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++){
    cin >> a[i];
  }

  long long badness[n-1];
  memset(badness, 0, sizeof(badness));

  for (long long i = 0; i < n; i++){
    for (long long j = i+1; j < n; j++){
      if (a[i] > a[j] && a[j] < n){
        badness[a[j]]++;
      }
    }
  }
  int ans = 0;
  for (auto i : badness){
    cout << ans << endl;
    ans += i;
  }
  cout << ans << endl;
}

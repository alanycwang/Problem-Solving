#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n, x, y;
  cin >> n >> x >> y;
  int a[n];
  int b[n];
  for (int i = 0; i < n; i++){
    cin >> a[i] >> b[i];
  }
  sort(a, a+n);
  sort(b, b+n);
  int ans = 0;
  for (int i = 0; i < n; i++){
    if (a[i] > b[i]){
      ans += y * (a[i] - b[i]);
      continue;
    }
    ans += x * (b[i] - a[i]);
  }
  cout << ans;
}

#include <bits/stdc++.h>

using namespace std;

int cows[100000];
int ans = 1000000000;
int wait = 0;
int n, m, c;
int b;

void recurse(int x, int y, int z){
  if (x == 0){
    if (y == n){
      ans = min(ans, z);
    }
    //cout << endl;
    return;
  }
  for (int i = b; i < c + 1; i++){
    int h = cows[y + i -1];
    int l = cows[y];
    //cout << h << " " << l << endl;
    int a = max(z, h-l);
    recurse(x-1, y + i, a);
  }
}

int main(){
  freopen("convention.in", "r", stdin);
  freopen("convention.out", "w", stdout);
  cin >> n >> m >> c;
  for (int i = 0; i < n; i++){
    cin >> cows[i];
  }
  b = c - (c*m-n);
  if (b < 1){
    b = 1;
  }
  sort(cows, cows + n);
  recurse(m, 0, 0);
  cout << ans;
}

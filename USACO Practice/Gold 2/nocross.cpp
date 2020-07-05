#include <bits/stdc++.h>
using namespace std;

int fields[1001][2];
int f2[1001][1000];

int f(int x, int y){
  if (f2[x][y] != -1){
    return f2[x][y];
  }
  int a = f(x-1, y-1);
  if (abs(fields[x][0]-fields[y][1]) <= 4){
    a++;
  }
  f2[x][y] = max(f(x,y-1), max(f(x-1,y), a));
  return max(f(x,y-1), max(f(x-1,y), a));
}

int main(){
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++){
    for (int j = 0; j <= n; j++){
      f2[i][j] = -1;
    }
  }
  for (int i = 0; i <= n; i++){
    f2[0][i] = 0;
    f2[i][0] = 0;
  }
  for (int i = 0; i < 2; i++){
    for (int j = 1; j <= n; j++){
      cin >> fields[j][i];
    }
  }
  cout << f(n, n);
}

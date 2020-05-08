#include <iostream>
#include <cmath>

using namespace std;

int main(){
  freopen("teleport.in", "r", stdin);
  freopen("teleport.out", "w", stdout);
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  int solution;
  if (abs(a-x) < abs(a-y)){
    solution = abs(a-x) + abs(b-y);
  }
  else{
    solution = abs(a-y) + abs(b-x);
  }
  if (solution > abs(a-b)){
    solution = abs(a-b);
  }
  cout << solution;
}

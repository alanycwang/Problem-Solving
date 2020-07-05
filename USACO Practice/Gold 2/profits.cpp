#include <iostream>

using namespace std;

int a[100000];
int best = 0;

int f(int x){
  if (x==0){
    best = a[0];
    return a[0];
  }
  int b = max(f(x-1), 0) + a[x];
  best = max(best, b);
  return b;

}

int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  f(n-1);
  cout << best;
}

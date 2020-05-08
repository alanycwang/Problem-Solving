#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin >> n;
  int piles[n];
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    piles[i] = x;
  }
  int y = 0;
  for (auto x : piles){
    y += x;
  }
  y /= n;
  int z = 0;
  for (int i = 0; i< n; i++){
    if (y < piles[i]){
      z += piles[i] - y;
    }
  }
  cout << z;
}

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n, b;
  cin >> n >> b;
  int heights[n];
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    heights[i] = x;
  }
  sort(heights, heights+n);
  int y = 0;
  int z = 0;
  for (int i = 0; i < n; i++){
    z += heights[n-i-1];
    y++;
    if (z>=b){
      cout << y;
      break;
    }
  }
}

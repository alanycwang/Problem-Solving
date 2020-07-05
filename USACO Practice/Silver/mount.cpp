#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin >> n;
  int heights[n];
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    heights[i] = x;
  }
  int widths[n];
  int x = 0;
  int y = 0;
  int z = 1;
  for (int i = 0; i < n; i++){
    y++;
    if (heights[i] < heights [i + 1]){
      widths[x] = y;
      y = z;
      z = 1;
      x++;
    }
    if (heights[i] == heights [i - 1]){
      z ++;
    }
    else{
      z = 1;
    }
    cout << y << " " << z << " " << x << " "<< i << endl;
  }
  sort(widths, widths + x + 1);
  for (int i = 0; i < x+1; i++){
    cout << widths[i] << endl;
  }
  cout << widths[x];
}

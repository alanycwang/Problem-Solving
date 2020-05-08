#include <iostream>
#include <algorithm>

using namespace std;

struct building {
  int a, b, h;
};

int main(){
  int n;
  cin >> n;
  int ans = 0;
  building buildings[n];
  int w = 0;
  for (int i = 0; i < n; i++){
    cin >> buildings[i].a >> buildings[i].b >> buildings[i].h;
    w = max(buildings[i].b, w);
  }
  for (int i = 1; i < w; i++){
    int a = 0;
    for (int j = 0; j < n; j++){
      if (buildings[j].a <= i && buildings[j].b > i){
        a = max(a, buildings[j].h);
      }
    }
    cout << a << " " << i << endl;
    ans += a;
  }
  cout << ans;
}

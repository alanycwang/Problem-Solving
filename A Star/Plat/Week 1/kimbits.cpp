#include <iostream>

using namespace std;

int32_t n, l, j;

int32_t fact(int32_t x){
  if (x <= 1){
    return 1;
  }
  return x*fact(x-1);
}

int32_t choose(int32_t x, int32_t k){
  return fact(x)/(fact(k)*fact(x-k));
}

int32_t count(int32_t x, int32_t y){
  int32_t ans = 1;
  for (int32_t i = 1; i <= y; i++){
    if (n-x < i) break;
    ans += choose(n-x, i);
  }
  return ans;
}

int main(){
  cin >> n >> l >> j;
  string x = "";
  int32_t index = 0;
  int32_t popcount = 0;
  for (int32_t i = 0; i < n; i++){
    cout << x.length() + 1 << " " << l-popcount << " " << count(x.length() + 1, l-popcount) << endl;
    if (count(x.length()+1, l-popcount) < j-index){
      index += count(x.length()+1, l-popcount);
      popcount++;
      x += "1";
    }
    else {
      x += "0";
    }
  }
  cout << x;
}

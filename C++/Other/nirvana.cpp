#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){
  int best = 0;
  int a;
  cin >> a;
  string b = to_string(a);
  for (int i = pow(10, b.size()-1); i <= a; i++){
      string c = to_string(i);
      int d = 1;
      //cout << c << endl;
      for (int k = 0; k < c.size(); k++){
        d *= int(c[k]) - '0';
        //cout << d << endl;
      }
      //cout << endl;
      best = max(best, d);
    }
  cout << best;
  return 0;
}

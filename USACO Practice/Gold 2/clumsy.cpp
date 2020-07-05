#include <iostream>

using namespace std;

int main(){
  string a;
  cin >> a;
  int b = 0;
  int c = 0;
  for (int i = 0; i < a.length(); i++){
    if (a[i] == '('){
      b++;
    }
    else {
      b--;
    }
    if (b < 0){
      b += 2;
      c++;
    }
    //cout << i << " " << b << " " << c << endl;
  }
  c += b/2;
  cout << c;
}

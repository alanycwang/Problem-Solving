#include <iostream>

using namespace std;

int main(){
  string a;
  cin >> a;
  char ans;
  int best = 0;
  for (int i = 0; i < 26; i++){
    int x = 0;
    for (auto j:a){
      //cout << j << " " << char('a' + i) << endl;
      if (char(j) == char('a' + i)){
        x++;
      }

    }
    if (x > best){
      best = x;
      ans = 'a' + i;
    }
    //cout << x << char('a' + i) << endl;
  }
  cout << ans << endl << a;
}

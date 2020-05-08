#include <iostream>
#include <cstring>

using namespace std;

int main(){
  string A[3] = {"a", "bb", "caababc"};
  string B[4] = {"bbbbbbbb", "ab", "bc", "ca"};
  int L;
  cin >> L;
  string a;
  string b;
  cin >> a >> b;
  if (a.length() > b.length()){
    string c;
    c = a;
    a = b;
    b = c;
  }
  //cout << a << " " << b;
/*  for (int i = 0; i < b.length(); i++){
    if (b[i] == a[0]){
      b.erase(i, 1);
      a.erase(0, 1);
      continue;
    }
  }
  cout << a << endl << b << endl;*/
  for (int i = 0; i < 3; i++){
    bool e = true;
    int f = 0;
    int g = 0;
    for (int j = 0; j < b.length() - A[i].length(); j++){
      if (b[j] != A[i][f] && f != 0){
        e = false;
        break;
      }
      else if (f==0){
        g = j;
      }
      f++;
    }
    if (e){
      b.erase(g, A[i].length());
    }
  }
  cout << b;
}

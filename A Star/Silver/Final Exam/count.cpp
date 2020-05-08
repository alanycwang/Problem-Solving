#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

int main(){
  int n, l;
  cin >> n >> l;
  int ans = 0;
  string x;
  stringstream ss;
  char a;
  stringstream y;
  y << l;
  y >> a;
  //cout << a;
  for (int i = 0; i < n; ){
    ans++;
    bool pass = true;
    stringstream ss;
    ss << ans;
    ss >> x;
    //cout << x << endl;
    //cout << x.size() << endl;
    for (int j = 0; j < x.size(); j++){
      //cout << j << endl;
      //cout << x[j] << endl;
      //cout << a << endl;
      if (x[j] ==  a){
        //cout << "working";
        pass = false;
        //cout << pow(10, x.size()-j-1);
      }
    }
    ///cout << endl;
    if (pass){
      i++;
    }
  }
  cout << ans -1;
}

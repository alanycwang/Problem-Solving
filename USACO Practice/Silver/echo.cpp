#include <iostream>
#include <string>

using namespace std;

int main(){
  string moo;
  string echo;
  cin >> moo;
  cin >> echo;
  string x;
  for (int i = 0; i < moo.length(); i++){
    string moo_substr = moo.substr(0, i);
    for (int j = 0; j < echo.length(); j++){
      string echo_substr = echo.substr(echo.length()-j, j);
      if (moo_substr == echo_substr && echo_substr == echo.substr(echo.length()-echo_substr.length())){
        x = moo_substr;
      }
    }
  }
  int a = x.length();
  for (int i = 0; i < echo.length(); i++){
    string echo_substr = echo.substr(0, i);
    for (int j = 0; j < moo.length(); j++){
      string moo_substr = moo.substr(moo.length()-j, j);
      if (echo_substr == moo_substr && moo_substr == moo.substr(moo.length()-moo_substr.length())){
        x = echo_substr;
      }
    }
  }
int b = x.length();
  if (a > b){
    cout << a;
  }
  else {
    cout << b;
  }
}

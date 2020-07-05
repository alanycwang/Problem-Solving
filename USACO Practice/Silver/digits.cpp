#include <iostream>
#include <cmath>
#include <sstream>
#include <string>

using namespace std;

int convertDecimal(int x, int base){
  stringstream ss;
  ss << x;
  string y = ss.str();
  int output = 0;
  for(int i = 0; i < y.length(); i++){
    output += (y[y.length()-i-1]-'0') * pow(base, i);
  }
  return output;
}

int main(){
  int binary;
  cin >> binary;
  int trinary;
  cin >> trinary;
  stringstream ss;
  ss << binary;
  string binary_str = ss.str();
  stringstream ss2;
  ss2 << trinary;
  string trinary_str = ss2.str();
  int x[binary_str.length()];
  string binary_str_cpy;
  binary_str_cpy = binary_str;
  for (int i = 0; i < binary_str_cpy.length(); i++){
    binary_str_cpy = binary_str;
    if (binary_str_cpy[i] == '0'){
      binary_str_cpy[i] = '1';
    }
    else{
      binary_str_cpy[i] = '0';
    }
    cout << binary_str_cpy << " ";
    stringstream ss3(binary_str_cpy);
    int a;
    ss3 >> a;
    x[i] = convertDecimal(a, 2);
    cout << x[i] << endl;
  }
}

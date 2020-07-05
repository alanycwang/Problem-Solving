#include <iostream>
#include <map>
#include <string.h>

using namespace std;

map<string, long long> m;

long long dp(string str){
  if (str.length() <= 2) return 1;
  if (m.find(str) != m.end()) return m[str];
  long long ans = 1;
  for (long long i = 1; str.length() - i >= i + 1; i++){
    if (str.substr(0, i) == str.substr(i, i)){
      ans += dp(str.substr(i, str.length() - i));
    }
    if (str.substr(0, i) == str.substr(str.length() - i, i)){
      ans += dp(str.substr(i, str.length() - i));
      ans += dp(str.substr(0, str.length() - i));
    }
    if (str.substr(str.length() - i, i) == str.substr(str.length() - 2*i, i)){
      ans += dp(str.substr(0, str.length() - i));
    }
    ans = ans % 2014;
  }
  m.insert(make_pair(str, ans));
  return ans;
}

int main(){
  string s;
  cin >> s;
  cout << dp(s) - 1;
}

#include <iostream>

using namespace std;

bool similar (string a, string b){
  for (int i = 0; i < a.length(); i++){
    if (a[i] != '?' && a[i] != b[i]) return false;
  }
  return true;
}

int main(){
  int l, nw;
  cin >> l >> nw;
  string p;
  cin >> p;
  string words[nw];
  for (int i = 0; i < nw; i++){
    cin >> words[i];
  }

  string dp[l+1];
  dp[0] = "";
  for (int i = 1; i <= l; i++){
    dp[i] = "~";
  }
  for (int i = 1; i <= l; i++){
    for (int j = 0; j < nw; j++){
      if (i + words[j].length() - 1 <= l && dp[i - 1] != "~" && similar (p.substr(i-1, words[j].length()), words[j])){
        //cout << p.substr(i-1, words[j].length()) << " " << words[j] << endl;
        dp[i + words[j].length() - 1] = min(dp[i + words[j].length() - 1], dp[i - 1] + words[j]);
        //cout << dp[i + words[j].length() - 1] << endl;
      }
    }
    //cout << dp[i] << endl;
  }
  cout << dp[l];
}

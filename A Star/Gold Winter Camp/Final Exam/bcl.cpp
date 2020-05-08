#include <iostream>

using namespace std;

bool recurse(string str){
  //cout << str << " " << str[1] << " " << str[str.length() - 2] << endl;
  if (str.length() == 1){
    return false;
  }
  if (str.length() == 2 && str[0] == str[1]){
    return false;
  }
  if (str[str.length() - 2] < str[1]){
    //cout << "working" << endl;
    return true;
  }
  else if (str[str.length() - 2] == str[1]){
    return recurse(str.substr(1, str.length() - 2));
  }
  else {
    return false;
  }
}

string toString(char a){
  string s(1, a);
  return s;
}

int main(){
  int n;
  cin >> n;
  string cows;
  for (int i = 0; i < n; i++){
    string a;
    cin >> a;
    cows.append(a);
  }

  string ans;

  for (int i = 0; i < n; i++){
    //cout << ans << endl;
    if (cows[0] < cows[cows.length() - 1]){
      ans.append(toString(cows[0]));
      cows.erase(0, 1);
    }
    else if (cows[0] == cows[cows.length() - 1]){
      //cout << "working" << endl;
      if (recurse(cows)){
        ans.append(toString(cows[cows.length() - 1]));
        cows.erase(cows.length() - 1, 1);
      }
      else{
        ans.append(toString(cows[0]));
        cows.erase(0, 1);
      }
    }
    else {
      ans.append(toString(cows[cows.length() - 1]));
      cows.erase(cows.length() - 1, 1);
    }
  }
  for (int i = 0; i < ans.length(); i++){
    cout << ans[i];
    if(i%80 == 79){
      cout << endl;
    }
  }
}

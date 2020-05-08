#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool helper(string a, string b){
  return a.length() > b.length();
}
bool helper2(string a, string b){
  return a.length() < b.length();
}

string primitives[1000];

int main(){
  int n = 0;
  while (true){
    string a;
    cin >> a;
    if (a[0] == '.'){
      break;
    }
    primitives[n] = a;
    n++;
    //cout << a << " ";
  }
  sort (primitives, primitives + n, helper);
  string p;
  while (true){
    string a;
    cin >> a;
    p.append(a);
    if(cin.eof()){
      break;
    }
  }
  //cout << p;
  /*cout << endl;
  for (auto i : primitives){
    cout << i << " ";
  }*/
  int ans = 0;
  for (int i = 0; i < p.length();){
    bool found = false;
    for (int k = 0; k < n; k++){
      string j = primitives[k];
      string a = p.substr(i, j.length());
      //cout << a << " " << j << " " << i << endl;
      if (a == j){
        i += j.length();
        found = true;
        break;
      }
    }
    if (!found){
      ans = i;
      break;
    }
  }
  if (ans = 0){
    ans = p.length();
  }
  sort (primitives, primitives + n, helper2);
  for (int i = 0; i < p.length();){
    bool found = false;
    for (int k = 0; k < n; k++){
      string j = primitives[k];
      string a = p.substr(i, j.length());
      //cout << a << " " << j << " " << i << endl;
      if (a == j){
        i += j.length();
        found = true;
        break;
      }
    }
    if (!found){
      cout << max(ans, i);
      return 0;
    }
  }
  cout << p.length();
}

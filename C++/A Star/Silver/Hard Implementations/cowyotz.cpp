#include <iostream>
#include <string>

using namespace std;

int n, s, e;
string conditions[20];
int roll[20];
int ans = 0;

void recurse(int rolls){
  if (rolls >= n){
    for (int i = 0; i < e; i++){
      int modifier = 0;
      int a = 1;
      int multiplier = 2;
      for (int x = 0; x < conditions[i].size(); x++){
        if (conditions[i][x] == '+'){
          a++;
        }
      }
      bool pass = true;
      for (int j = 0; j < a; j++){
        int b = 0;
        for (int k = 0; k < n; k++){
          //cout << roll[k] << " " << conditions[i][4*j+2] << endl;
          if (roll[k]+1 == conditions[i][4*j+2+modifier] - '0'){
            b++;
          }
        }
        //cout << b << endl;
        if (b < conditions[i][4*j+modifier] - '0'){
          pass = false;
        }
      }
      if (pass){
        for (auto x:roll){
          //cout << x+1 << " ";
        }
        //cout << endl;
        ans++;
      }
      //cout << ans << endl;
    }
    return;
  }
  for (int i = 0; i < s; i++){
    roll[rolls] = i;
    recurse(rolls+1);
  }
}

int main(){
  cin >> n >> s >> e;
  for (int i = 0; i < e; i++){
    cin >> conditions[i];
  }
  recurse(0);
  cout << ans;
}

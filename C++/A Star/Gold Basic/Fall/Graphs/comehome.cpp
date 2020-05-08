#include <bits/stdc++.h>

using namespace std;

int main(){
  int paths[52][52];
  int p;
  for (int i = 0; i < 52; i++){
    for (int j = 0; j < 52; j++){
      paths[i][j] = 1000000000;
    }
  }
/*  for (int i = 0; i < 26; i++){
    for (int j = 0; j < 26; j++){
      cout << paths[i][j] << " ";
    }
  cout << endl;
  }*/
  cin >> p;
  for (int i = 0; i < p; i++){
    char a, b;
    int c;
    cin >> a >> b >> c;
    if (toupper(a) != a){
      a -= (6);
    }
    if (toupper(b) != b){
      b -= (6);
    }
    if (c < paths[a - 'A'][b - 'A']){
      paths[a - 'A'][b - 'A'] = c;
      paths[b - 'A'][a - 'A'] = c;
    }
  }
  for (int i = 0; i < 52; i++){
    paths[i][i] = 0;
  }
  for (int k = 0; k < 52; k++){
    for (int i = 0; i < 52; i++){
      for (int j = 0; j < 52; j++){
        paths[i][j] = min(paths[i][j], paths[i][k] + paths[k][j]);
      }
    }
  }
/*  for (int i = 0; i < 52; i++){
    for (int j = 0; j < 52; j++){
      cout << paths[i][j] << " ";
    }
  cout << endl;
  }*/
  int ans = 1000000000;
  char ans2;
  for (int i = 0; i < 25; i++){
    if (paths[i][25] < ans){
      ans = paths[i][25];
      ans2 = char(i + 'A');
    }
  }
  cout << ans2 << " " << ans;
}

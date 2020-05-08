#include <iostream>
#include <string.h>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  string troughs[m];
  int a[m];
  for (int i = 0; i < m; i++){
    cin >> troughs[i] >> a[i];
  }
  bool filled2[n];
  int n_working = 0;
  for (int i = 0; i < ( 1 << n); i++){
    bool filled[n];
    memset(filled, 0, sizeof(filled));
    for (int j = 0; j < n; j++){
      int tmp = i >> j;
      if (tmp & 1){
        filled[j] = true;
      }
    }
    bool solution = true;
    for (int j = 0; j < m; j++){
      int x = 0;
      for (int k = 0; k < n; k++){
        if (troughs[j][k] == '1' && filled[k]){
          x++;
        }
      }
      if (x != a[j]){
        solution = false;
      }
    }
    if(solution){
      for (int j = 0; j < n; j++){
        filled2[j] = filled[j];
      }
      n_working ++;
    }
  }
  if (n_working > 1){
    cout << "NOT UNIQUE";
  }
  else if ( n_working == 1){
    for (int i = 0; i < n; i++){
      cout << filled2[i];
    }
  }
  else{
    cout << "IMPOSSIBLE";
  }
}

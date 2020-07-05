#include <iostream>
#include <vector>

using namespace std;

int cows[1001][1001];

int main(){
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    cows[a][b] = true;
    cows[b][a] = true;
  }
  while (true){
    int x = 0;
    for (int i = 1; i < n + 1; i++){
      vector<int> y;
      for (int j = 1; j < n + 1; j++){
        if (cows[i][j]){
          y.push_back(j);
        }
      }
      /*for (auto j : y){
        cout << j << endl;
      }*/
      for (int j = 0; j < y.size(); j++){
        for (int k = j + 1; k < y.size(); k++){
          if (!cows[y[j]][y[k]]){
            cows[y[j]][y[k]] = true;
            cows[y[k]][y[j]] = true;
            x++;
          }
        }
      }
    }
    if (x == 0){
      break;
    }
  }
  /*for (int i = 1; i < n + 1; i++){
    for (int j = 1; j < n + 1; j++){
      cout << cows[i][j] << " ";
    }
    cout << endl;
  }*/
  for (int i = 0; i < q; i++){
    int a, b;
    cin >> a >> b;
    if (cows[a][b]){
      cout << "Y" << endl;
    }
    else{
      cout << "N" << endl;
    }
  }
}

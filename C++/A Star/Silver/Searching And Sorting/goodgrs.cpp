#include <iostream>
#include <algorithm>

using namespace std;

struct square {
  int production;
  int coordinate1;
  int coordinate2;
};
int main(){
  int nr, nc;
  cin >> nr >> nc;
  int cows[nr*nc];
  for (int i = 0; i < nr; i++){
    for (int j = 0; j < nc; j++){
      cin >> cows[i*nc + j];
    }
  }
  square best_square;
  best_square.production = 0;
  for (int i = 0; i < nr-2; i++){
    for (int j = 0; j < nc-2; j++){
      int x = 0;
      for (int k = 0; k < 3; k++){
        for (int l = 0; l < 3; l++){
          x += cows[(i+k)*nc + j + l];
        }
      }
      if (x > best_square.production){
        best_square.production = x;
        best_square.coordinate1 = i;
        best_square.coordinate2 = j;
      }
    }
  }
  cout << best_square.production << endl << best_square.coordinate1+1 << " " << best_square.coordinate2+1;
}

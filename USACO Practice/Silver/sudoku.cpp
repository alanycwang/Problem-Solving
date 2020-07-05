#include <iostream>

using namespace std;

int numbers[9][9];
int ans[9][9];
string working = "working";

bool check(int x, int y, int number){
  for (int j = 0; j < 9; j++){
    if (numbers[x][j] == number){
      return false;
    }
  }
  for (int k = 0; k < 9; k++){
    if (numbers[k][y] == number){
      return false;
    }
  }
  for (int l = 0; l <= 9; l+=3){
    for (int m = 0; m <= 9; m+=3){
      if (x >= l && x < l+3 && y >= m && y < m+3){
        for (int j = 0; j < 3; j++){
          for (int k = 0; k < 3; k++){
            if (j != x && k != y){
              if (numbers[l+j][m+k] == number){
                return false;
              }
            }
          }
        }
      }
    }
  }
  return true;
}

void recurse(int x, int y){
  if(x == 8 && y == 8){
    cout << "works";
    for (int i = 0; i < 9; i++){
      if (check(x, y, i)){
        numbers[x][y] = i;
        for (int j = 0; j < 9; j++){
          for (int k = 0; k < 9; k++){
            ans[j][k] = numbers[j][k];
          }
        }
        return;
      }
    }
  }
  if (numbers[x][y] == 0){
    for (int i = 0; i < 9; i++){
      if (check(x, y, i)){
        numbers[x][y] = i;
        if (x == 8){
          cout << working;
          recurse(0, y+1);
        }
        else{
          cout << working;
          recurse(x+1, y);
        }
        numbers[x][y] = 0;
      }
    }
  }
  else{
    if (x == 8){
      cout << working;
      recurse(0, y+1);
    }
    else{
      cout << working;
      recurse(x+1, y);
    }
  }
}

int main(){
  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++){
      cin >> numbers[i][j];
    }
  }
  bool end;
  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++){
      if (numbers[i][j] == 0){
        cout << "working";
        recurse(i, j);
        break;
        end = true;
      }
    }
    if (end){
      break;
    }
  }
}

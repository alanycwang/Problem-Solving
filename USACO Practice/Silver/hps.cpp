#include <iostream>

using namespace std;

bool checkForWin(char fj, char bessie){
  if (fj == 'S' && bessie == 'H'){
    return true;
  }
  else if (fj == 'P' && bessie == 'S'){
    return true;
  }
  else if (fj == 'H' && bessie == 'P'){
    return true;
  }
  else {
    return false;
  }
}

char getLetterMove(int x){
  if (x == 0){
    return 'H';
  }
  if (x == 1){
    return 'P';
  }
  if (x == 2){
    return 'S';
  }
}

int main(){
  int n;
  cin >> n;
  char plays[n];
  for (int i = 0; i < n; i++){
    char x;
    cin >> x;
    plays[i] = x;
  }
  int prefix[n][3];
  int suffix[n][3];
  int wins[3] ={0, 0, 0};
  for (int j = 0; j < 3; j++){
    for (int i = 0; i < n; i++){
      if (checkForWin(plays[i], getLetterMove(j))){
        wins[j] ++;
      }
      prefix[i][j] = wins[j];
    }
  }

  for (int j = 0; j < 3; j++){
    for (int i = 0; i < n; i++){
      if (checkForWin(plays[n-1-i], getLetterMove(j))){
        wins[j] ++;
      }
      suffix[n-1-i][j] = wins[j];
    }
  }
  int best = 0;
  for (int k = 0; k < 3; k++){
    for (int l = k; l < 3; l++){
      for (int i = 0; i < n; i++){
        int x = prefix[i][k]+suffix[i][l];
        if (x > best){
          best = x;
        }
      }
    }
  }

  cout << best;
}

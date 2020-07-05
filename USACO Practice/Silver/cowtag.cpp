#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  int cows[n][2]
  for (int i = 0; i < n; i++){
    cin << cows[i][0] << cows[i][1];
  }
  for (int i = 0;;i++){
    long long greatest = 999999999999;
    int cow;
    for (int j = 0; j < n; j++){
      if (j != i){
        long long distance = pow(cows[i][0]-cows[j][0]) + pow(cows[i][1]-pow(cows[j][1]));
        if (distance < greatest){
          greatest = distance;
          cow = j;
        }
      }
    }
    cows[j][0] = -1;
    int x;
    for (int j = 0; j < n; j++){
      if (cows[n][0] == -1){
        x++;
      }
    }
    if (x = n-1){
      break;
    }
  }
  for (int i = 0; i < n; i++){
    if (cows[i][0] != -1){
      cout << i;
    }
  }
}

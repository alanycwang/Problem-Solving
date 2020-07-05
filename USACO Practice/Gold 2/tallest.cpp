#include <iostream>

using namespace std;

int cows[10001];

int main(){
  int n, z, h, r;
  cin >> n >> z >> h >> r;
  cows[z] = h;
  int input[r][2];
  for (int i = 0; i < n + 1; i++){
    cows[i] = h;
  }
  for (int i = 0; i < r; i++){
    cin >> input[i][0] >> input[i][1];
  }
  for (int i = 0; i < r; i++){
    int a = input[i][0];
    int b = input[i][1];
    if (cows[a] > cows[b]){
      cows[a] = cows[b];
    }
    if (a < b){
      for (int j = a + 1; j < b; j++){
        if (cows[j] >= cows[a]){
          cows[j] = cows[a] - 1;
        }
      }
    }
    else if(a > b){
      for (int j = b + 1; j < a; j++){
        if (cows[j] >= cows[a]){
          cows[j] = cows[a] - 1;
        }
      }
    }
    /*for (int i = 1; i < n + 1; i++){
      cout << cows[i] << endl;
    }*/
  }
  for (int i = r - 2; i >= 0; i--){
    int a = input[i][0];
    int b = input[i][1];
    if (cows[a] > cows[b]){
      cows[a] = cows[b];
    }
    if (a < b){
      for (int j = a + 1; j < b; j++){
        if (cows[j] >= cows[a]){
          cows[j] = cows[a] - 1;
        }
      }
    }
    else if(a > b){
      for (int j = b + 1; j < a; j++){
        if (cows[j] >= cows[a]){
          cows[j] = cows[a] - 1;
        }
      }
    }
    /*for (int i = 1; i < n + 1; i++){
      cout << cows[i] << endl;
    }*/
  }
  for (int i = 1; i < n + 1; i++){
    cout << cows[i] << endl;
  }
}

#include<iostream>
#include<algorithm>

using namespace std;

int main(){
  int n;
  cin >> n;
  int ecards[n];
  bool cards[2*n];
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    ecards[i] = x;
  }
  sort(ecards, ecards + n);
  int x = 0;
  for (int i = 0; i < 2*n; i++){
    if (ecards[x] == i+1){
      cards[i] = false;
      x++;
    }
    else {
      cards[i] = true;
    }
  }
  int output = 0;
  int y = 0;
  int z = 0;
  for (int i = 0; i < 2*n; i++){
    if((cards[i] == true && y > z) || (cards[i] == true && y == 0)){
      output ++;
      z++;
    }
    else {
      y++;
    }
  }
  cout << output;
}

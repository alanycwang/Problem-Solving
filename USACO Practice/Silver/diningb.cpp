#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin >> n;
  int cows[n];
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    cows[i] = x;
  }
  int x = 0;
  int prefix[n+1];
  for (int i = 0; i < n + 1; i++){
    if (i != 0 && cows[i-1] == 2){
      x++;
    }
    prefix[i] = x;
  }
  int y = 0;
  int suffix[n+1];
  for (int i = 0; i < n + 1; i++){
    if (i != 0 && cows[n-i] == 1){
      y++;
    }
    suffix[n-i]= y;
  }
  int changes[n+1];
  for(int i = 0; i < n + 1; i++){
    changes[i] = suffix[i] + prefix[i];
  }
  sort(changes, changes + n + 1);
  cout << changes[0];
}

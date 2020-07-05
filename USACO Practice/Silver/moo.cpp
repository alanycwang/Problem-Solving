#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getSize(int size){
  if (size == 0){
    return 3;
  }
  return size + 3 + 2*getSize(size-1);
}

char find(int pos, int k){
  if (k == 0){
    if (pos == 1){
      return 'm';
    }
    else {
      return 'o';
    }
  }
  int x = getSize(k-1);
  if (pos <= x){
    return find(pos, k-1);
  }
  else if (pos > x && pos <= x + k + 3){
    if (pos == x + 1){
      return 'm';
    }
    else{
      return 'o';
    }
  }
  else if (pos > x + k + 3){
    return find(pos - (x + k + 3), k-1);
  }
}
int main(){
  int n;
  cin >> n;
  int x = 0;
  int i = 0;
  for (; ; i++){
    x = getSize(i);
    if (x > n){
      break;
    }
  }
  cout << find(n, i);
}

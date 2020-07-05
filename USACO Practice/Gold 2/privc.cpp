#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int b[n];
  memcpy(&b, &a, sizeof(a));
  sort (b, b+n);
/*  for (int i = 0; i < n; i++){
    cout << b[i] << " ";
  }*/
  for (int i = 0; i < n; i++){
    if (a[i] != b[1]){
      
    }
  }
}

#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  for (int i  = 0; i < n; i++){
    cin >> a[i];
  }
  int ans; = 0;
  sorted = false;
  while(!sorted){
    sorted = true;
    ans++;
    for (int i = 0; i < n-2; i++){
      if (a[i + 1] < a[i]){
        int b = a[i + 1];
        a[i + 1] = a[i];
        a[i] = b;
      }
      for (int i = n-2; i > 0; i--){
        if (a[i + 1] < a[i]){
          int b = a[i + 1];
          a[i + 1] = a[i];
          a[i] = b;
        }
      }
    }
  }
}

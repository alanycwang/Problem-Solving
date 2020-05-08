#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  int ans;
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  for (int i = 1;; i++){
    bool b = false;
    for (int j = 1; j < n; j++){
      //cout << float(i%a[j])/a[j] << endl;
      if (float(i%a[j])/a[j] != float(i%a[0])/a[0]){
        //cout << (float(i%a[j])/a[j] != c) << endl;
        b = true;
        break;
      }
    }
    if (!b){
      ans = i;
      break;
    }
    //cout << endl;
  }
  cout << ans;
  bool b = false;
  for (int i = 0; i < n; i++){
    if (a[i] % 2 == 0){
      b = true;
      break;
    }
  }
  if (b){
    cout << " " << 1;
  }
  else{
    cout << " " << 2;
  }
}

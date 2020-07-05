#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  int cows[n];
  int index[n];
  for (int i = 0; i < n; i++){
    cin >> cows[i];
  }
  int last = 0;
  for (int i = 0; i < (1 << n); i++){
    int count = 0;
    int weight = 0;
    for (int j = 0; j < n; j++){
      bool pass = true;
      int tmp = i >> j;
      if (tmp & 1){
        string a, b;
        a = to_string(cows[j]);
        b = to_string(weight);
        int c = a.size();
        if (a.size() > b.size()){
          c = b.size();
        }
        for (int k = 0; k < c; k++){
          if ((a[a.size() - k - 1] - '0')+(b[b.size() - k - 1] - '0') >= 10){
            pass = false;
            break;
          }
        }
        if (pass){
          weight += cows[j];
          count ++;
        }
      }
    }
    if (count > last){
      last = count;
    }
  }
  cout << last;
}

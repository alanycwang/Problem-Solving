#include <iostream>

using namespace std;

int numbers[10];
int m, n;
int ans[10];

void getNumbers(int pos){
  if (pos == n){
    for (int i = 0; i < n; i++){
      cout << ans[i];
    }
    cout << endl;
    return;
  }
  for (int i = 0; i < m; i++){
    ans[pos] = numbers[i];
    getNumbers(pos+1);
  }
}

int main(){
  cin >> m;
  for (int i = 0; i < m; i++){
    int x;
    cin >> x;
    numbers[i] = x;
  }
cin >> n;
getNumbers(0);
}

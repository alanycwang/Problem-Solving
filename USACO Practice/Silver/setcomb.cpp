#include <iostream>

using namespace std;

int numbers[10];
int m, n;
int ans[10];
bool a[10] = {true, true, true, true, true, true, true, true, true, true};
int last = 0;

void getNumbers(int pos){
  if (pos == n){
    for (int i = 0; i < n; i++){
      cout << ans[i];
    }
    cout << endl;
    return;
  }
  for (int i = last; i < m; i++){
    if (a[i] != false){
      ans[pos] = numbers[i];
      a[i] = false;
      last = i;
      getNumbers(pos+1);
      a[i] = true;
    }
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

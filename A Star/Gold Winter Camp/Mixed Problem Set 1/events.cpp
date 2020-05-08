#include <iostream>

using namespace std;

void f

int main(){
  int n; cin >> n;
  int events[n][2
  int len = 0;
  for (int i = 0; i < n; i++){
    cin >> events[i][0] >> events[i][1];
    len = max(len, events[i][0] + events[i][1]);
  }

}

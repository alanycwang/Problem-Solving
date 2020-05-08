#include <iostream>
#include <algorithm>

using namespace std;

bool helper (int a[4], int b[4]){
  return a[0] < b[0];
}

int main(){
  int n;
  cin >> n;
  int enclosures[n][4];
  for (int i = 0; i < n; i++){
    cin >> enclosures[i][0] >> enclosures[i][1] >> enclosures[i][2] >> enclosures[i][3];
  }
  int ans = n;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (enclosures[i][0] < enclosures[j][0] && enclosures[i][1] < enclosures[j][1] && enclosures[i][2] > enclosures[j][2] && enclosures[i][3] > enclosures[j][3]){
        n--;
      }
    }
  }
  cout << n << endl;
}

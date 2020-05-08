/*
ID: alanycw1
LANG: C++
TASK: friday
*/
#include <iostream>

using namespace std;

int main(){
  freopen("friday.in", "r", stdin);
  freopen("friday.out", "w", stdout);
  int n;
  int days[7] = {0, 0, 0, 0, 0, 0, 0};
  cin >> n;
  int day = 0;
  int dayofweek = 2;
  int lengths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  for (int i = 1900; i < 1900+n; i++){
    bool leapyear = false;
    if (i%4 == 0 && i%100 != 0 || i%1000 == 0){
      leapyear = true;
    }
    for (int j = 0; j < 12; j++){
      int length = lengths[j];
      if (j == 1 && leapyear){
        length = 29;
      }
      for (int k = 0; k < length; k++){
        if (dayofweek == 7){
          dayofweek = 0;
        }
        if (k == 12){
          days[dayofweek]++;
        }
        dayofweek++;
      }
    }
  }
  for (int i = 0; i < 7; i++){
    cout << days[i];
    if (i != 6){
      cout << " ";
    }
  }
  cout << endl;
}

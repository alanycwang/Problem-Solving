//UNFINISHED
#include <iostream>

using namespace std;

struct shift{
  int start;
  int end;
};
int main(){
  int n;
  cin >> n;
  shift shifts[n];
  for (int i = 0; i < n; i++){
    int x;
    int y;
    cin >> x >> y;
    shifts[i].start = x;
    shifts[i].end = y;
  }
}

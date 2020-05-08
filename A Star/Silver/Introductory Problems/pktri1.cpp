#include <iostream>

using namespace std;

int main(){
  string input;
  int n;
  int s;
  getline(cin, input);
  sscanf(input.c_str(), "%d %d",&n, &s);
  int x = s;
  int y = s;
  for (int i = 0; i < n; i++){
    y++;
    if ( y == 10){
      y = 1;
    }
    for (int k  = 0; k < i; k++) {
      cout << "  ";
    }
    for (int j = 0; j < n - i; j++){
      for (int h = 0; h < j + i; h++){
        x++;
        if ( x == 10){
          x = 1;
        }
      }
      cout << x << " ";
    }
    for (int h = 0; h < i; h++){
      y++;
      if ( y == 10){
        y = 1;
      }
    }
    x=y;
    cout << endl;
  }
}

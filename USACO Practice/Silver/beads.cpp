#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
  int n;
  cin >> n;
  string necklace;
  cin >> necklace;
  char color1, color2;
  int greatest = 0;
  int x, y, z;
  for(int i = 0; i < n; i++){
    color1 = necklace[0];
    color2 = necklace[n-1];
    for (int j = 0; j > - 1; j++){
      if (color1 == 'w' && necklace[j] != 'w'){
        color1 = necklace[j];
      }
      if (necklace[j] != color1 && necklace[j] != 'w'){
        x = j;
        break;
      }
    }
    for (int j = 0; j > -1; j++){
      if (color2 == 'w' && necklace[n-j-1] != 'w'){
        color2 = necklace[n-j-1];
      }
      if (necklace[n-j-1] != color2 && necklace[n-j-1] != 'w'){
        y = j;
        break;
      }
    }
    int z = x + y;
    if (z > n){
      z = n;
    }
    if (z > greatest){
      greatest = z;
    }
    string a;
    stringstream ss;
    ss << necklace[n-1];
    ss >> a;
    a.append(necklace);
    a.erase(n, 1);
    necklace = a;
  }
  cout << greatest;
}

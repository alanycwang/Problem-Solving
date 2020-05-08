#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int divisorSum(int x){
  int y = 0;
  for(int i = 0; i < x; i++){
    if (i != 0 && x%i == 0){
      y += i;
    }

  }
  return y;
}

int main(){
  int y;
  cin >> y;
  int i = y;
  while (true){
    if (i==divisorSum(divisorSum(i))){
      cout << i << " " << divisorSum(i);
      break;
    }
    i++;
  }
}

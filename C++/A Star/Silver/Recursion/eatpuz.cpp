#include <iostream>

using namespace std;

int b, c;
int buckets[21];
int greatest = 0;
bool y[21] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};

void recur(int x){
  if (x > greatest){
    greatest = x;
  }
  for (int i = 0; i < b; i++){
    if (x + buckets[i] < c && y[i] == false){
      y[i] = true;
      recur(x+buckets[i]);
      y[i] = false;
    }
  }
}

int main(){
  cin >> c >> b;
  for (int i = 0; i < b; i++){
    int x;
    cin >> x;
    buckets[i] = x;
  }
  recur(0);
  cout << greatest;
}

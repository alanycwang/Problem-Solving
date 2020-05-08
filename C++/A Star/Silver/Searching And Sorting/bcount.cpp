#include <iostream>

using namespace std;

struct cow{
  int index;
  int breed;
};

int main(){
  int n, q;
  cin >> n >> q;
  cow cows[n];
  for (int i = 0; i < n; n++){
    int x;
    cin >> x;
    cows[i].index = i;
    cows[i].breed = x;
  }
  cout << n << " " << q << endl;
  for (const auto& i : cows){
    cout << i.breed << endl;
  }
}

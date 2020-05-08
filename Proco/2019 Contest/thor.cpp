#include <iostream>
#include <cmath>

using namespace std;

int main(){
  long long a[2];
  cin >> a[0] >> a[1];
  cout << int(pow(a[1]/a[0], 3));
}

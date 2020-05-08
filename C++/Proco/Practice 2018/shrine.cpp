#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int n;
  cin >> n;
  int arr1[3];
  int arr2[3];
  for (int i = 0; i < 3; i++){
    cin >> arr1[i];
  }
  for (int i = 0; i < 3; i++){
    cin >> arr2[i];
  }
  int sum = 0;
  for (int i = 0; i < 3; i++){
    sum += abs(arr1[i] - arr2[i]);
  }
  cout << sum;
  return 0;
}

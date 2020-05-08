include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  //getting inputs n and s
  int n, s;
  cin >> n >> s;

  //getting cow lengths
  int cow_lengths[n];
  for (int i = 0; i < n; i++){
    int input;
    cin >> input;
    cow_lengths[i] = input;
  }
  sort (cow_lengths, cow_lengths + n);
  int high = n-1;
  int mid;
  int x = 0;
  int target;
  int low;
  for (int i = 0; i < n; i++){
    target = s-cow_lengths[i];
    low = i+1;
    if (cow_lengths[low] <= target){
      while (low < high){
        mid = (low + high + 1)/2;
        if (cow_lengths[mid] <= target){
          low = mid;
        }
        else {
          high = (mid - 1);
        }

      }
    }
    while (cow_lengths[high] > target && high > i){
      high --;
    }
    if (high > i){
        x+=(high-i);
    }
  }
  cout << x;
}

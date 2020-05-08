#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n, q;
  cin >> n >> q;
  int locations[n];
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    locations[i] = x;
  }
  int outputs[q];
  sort(locations, locations+n);
  for (int i = 0; i < q; i++){
    int high2;
    int x;
    int y;
    cin >> x >> y;
    int high = n-1;
    int mid;
    int target;
    int low;
    target = y;
    low = 0;
    if (locations[low] <= target ){
      while (low < high){
        mid = (low + high + 1)/2;
        if (locations[mid] <= target){
          low = mid;
        }
        else {
          high = (mid - 1);
        }

      }
    }
    high2 = high;
    high = n-1;
    target = x;
    low = 0;
    if (locations[high] >= target ){
      while (low < high){
        mid = (low + high)/2;
        if (locations[mid] >= target){
          high = mid;
        }
        else {
          low = (mid + 1);
        }

      }
    }
    if (x > locations[n-1] || y < locations [0]){
      outputs[i] = 0;
    }
    else {
      outputs[i] = high2-high + 1;
    }
  }
  for (const auto& x : outputs){
    cout << x << endl;
  }
}

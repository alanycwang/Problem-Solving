#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  int sides[n];
  for (int i = 0; i < n; i++){
    cin >> sides[i];
  }
  if (n <= 2){
    cout << -1 << " " << -1;
    return 0;
  }
  int ans1 = -1;
  int ans2 = -1;
  for (int i = 0; i < (1 << n); i++){
    vector<int> rods;
    for (int j = 0; j < n; j++){
      int tmp = i >> j;
      if (tmp & 1){
        rods.push_back(sides[j]);
        //cout << sides[j] << endl;
      }
    }
    int largest = 0;
    int sum = 0;
    for (auto j : rods){
      largest = max(largest, j);
      //cout << j << endl;
      sum += j;
    }
    sum -= largest;
    //cout << largest << endl;
    if (sum > largest){
      ans1 = max(sum + largest, ans1);
      ans2 = max(ans2, int(rods.size()));
    }
    //cout << ans1 << endl << endl;
  }
  if (ans1 < 0){
    cout << -1 << " " << -1 << endl;
    return 0;
  }
  cout << ans1 << " " << ans2 << endl;
  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin >> n;
  if (n == 1){
    cout << 0;
    return 0;
  }
  vector<int> a;
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    a.push_back(x);
  }
  int ans = 0;
  for (int i = 0; i < n-1; i++){
    sort(a.begin(), a.begin()+n-i);
    int x = a[0] + a[1];
    a.erase(a.begin());
    a[0] = x;
    ans += x;
/*    for (int j:a){
      cout << j << " ";
    }
    cout << endl;*/
  }
  cout << ans;
}

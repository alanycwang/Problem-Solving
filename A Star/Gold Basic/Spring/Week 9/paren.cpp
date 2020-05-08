#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int n;
  cin >> n;
  bool s[n];
  for (int i = 0; i < n; i++){
    cin >> s[i];
  }
  long long depth = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++){
    if (s[i] == 0){
      depth++;
    }
    else if (s[i] == 1){
      depth--;
      if (i > 0 && s[i-1] == 0){
        ans += pow(2, depth);
      }
    }
    cout << depth << " " << ans << endl;
  }
  cout << ans;
}

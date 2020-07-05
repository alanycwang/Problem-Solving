#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  pair<int, int> s;
  cin >> s.first >> s.second;
  int ans = 1000000000;
  pair<int, int> ans2;
  for (int i = 0; i < m; i++){
    pair<int, int> temp;
    cin >> temp.first >> temp.second;
    pair<int, int> b, l;
    if (temp.first < s.first) {
      b = temp;
      l = s;
    }
    else {
      l = temp;
      b = s;
    }
    int total = 2*(l.first - b.first);
    if (l.second <= b.second) total += b.second - l.second;
    else if (l.second - total > b.second) total += l.second - total - b.second;
    else if (b.second%2 == 1) total -= abs(b.second%2 - l.second%2);
    else total += l.second%2;
    if (total < ans) {
      ans = total;
      ans2 = temp;
    }
    //cout << total << endl;
  }
  cout << ans2.first << " " << ans2.second << endl;
  cout << ans+1;
}

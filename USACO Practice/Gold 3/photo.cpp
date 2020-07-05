#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int n;
map<int, vector<int>> cows;

bool comp(int a, int b) {
  int cnt = 0;
  for (int i = 0; i < 5; i++) if (cows[a][i] < cows[b][i]) cnt++;
  return cnt >= 3;
}

int main() {
  cin >> n;
  int ans[n];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < n; j++) {
      int temp;
      cin >> temp;
      if (i == 0) {
        ans[j] = temp;
        vector<int> empty;
        cows.insert(make_pair(temp, empty));
      }
      cows[temp].push_back(j);
    }
  }

  sort(ans, ans + n, comp);
  for (int i = 0; i < n; i++) cout << ans[i] << endl;
}

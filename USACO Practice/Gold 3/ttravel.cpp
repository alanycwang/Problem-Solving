#include <iostream>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;
  pair<char, int> queries[n];
  bool save[n];
  memset(save, 0, sizeof(save));
  for (int i = 0; i < n; i++) {
    cin >> queries[i].first;
    if (queries[i].first != 's') cin >> queries[i].second;
    if (queries[i].first == 't') save[queries[i].second - 2] = true;
  }

  vector<int> cows;
  map<int, vector<int>> saves;
  for (int query = 0; query < n; query++) {
    if (queries[query].first == 'a') cows.push_back(queries[query].second);
    else if (queries[query].first == 's') cows.pop_back();
    else if (queries[query].first == 't') cows = saves[queries[query].second];

    if (save[query]) saves.insert(make_pair(query + 2, cows));
    if (cows.empty()) cout << -1 << endl;
    else cout << cows[cows.size() - 1] << endl;
  }
}

#include <iostream>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

struct Pie {
  int first;
  int second;
  int index;
};

bool comp(Pie a, Pie b) {
  return a.second < b.second;
}

bool comp2(Pie a, Pie b) {
  return a.first < b.first;
}

Pie pies[2][100000];
int ans[100000];
bool visited[2][100000];

int main() {
  int n, d;
  cin >> n >> d;
  queue<pair<pair<int, int>, int>> q;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> pies[i][j].first >> pies[i][j].second;
      pies[i][j].index = j;
    }
  }

  sort(pies[0], pies[0] + n, comp);
  sort(pies[1], pies[1] + n, comp2);

  for (int i = 0; i < n; i++) if (pies[0][i].second == 0) {
    visited[0][i] = true;
    q.push(make_pair(make_pair(0, i), 0));
  }

  for (int i = 0; i < n; i++) if (pies[1][i].first == 0) {
    visited[1][i] = true;
    q.push(make_pair(make_pair(1, i), 0));
  }


  for (int i = 0; i < n; i++) ans[i] = -2;

  while(!q.empty()) {
    pair<pair<int, int>, int> pie = q.front();
    q.pop();

    int value;
    if (pie.first.first == 0) value = pies[pie.first.first][pie.first.second].first;
    else value = pies[pie.first.first][pie.first.second].second;

    //cout << pies[pie.first.first][pie.first.second].first << " " << pies[pie.first.first][pie.first.second].second << " " << pie.first.first << " " << pie.first.second << " " << pie.second << endl;

    if (pie.first.first == 0 && ans[pies[pie.first.first][pie.first.second].index] == -2) {
      ans[pies[pie.first.first][pie.first.second].index] = pie.second;
      //cout << pie.second << endl;
    }

    int low = 0;
    int high = n-1;
    while (low < high) {
      int mid = (low + high + 1)/2;
      int temp;
      if (pie.first.first == 0) temp = pies[!pie.first.first][mid].first;
      else temp = pies[!pie.first.first][mid].second;
      if (temp <= value) low = mid;
      else if (temp > value) high = mid - 1;
    }


    cout << "working" << endl
    //cout << high << endl;

    for (int i = 0;;i++) {
      int temp;
      if (pie.first.first == 0) temp = pies[!pie.first.first][high - i].first;
      else temp = pies[!pie.first.first][high - i].second;
      if (high-i >= 0 && !visited[!pie.first.first][high - i] && value - temp <= d) {
        visited[!pie.first.first][high - i] = true;
        q.push(make_pair(make_pair(!pie.first.first, high - i), pie.second + 1));
      }
      else if (value - temp > d) break;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] + 1 << endl;
  }
}

#include <iostream>

using namespace std;

int h, w;
char map[1000][1000];
pair<int, int> edges[4] = {make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1)};
pair<int, int> corners[4] = {make_pair(-1, -1), make_pair(1, -1), make_pair(1, 1), make_pair(-1, 1)};
bool started = false;
pair<int, int> start;

void dfs(int x, int y) {
  if (x <= 0 || x >= h - 1 || y <= 0 || y >= w - 1 || map[x][y] != '.') return;

  int n = 0;
  bool filled[4];
  for (int i = 0; i < 4; i++) {
    filled[i] = false;
    if (map[x + edges[i].first][y + edges[i].second] == 'A') {
      filled[i] = true;
      n++;
    }
  }

  if (n == 3) goto recurse;
  for (int i = 0; i < 4; i++) {
    if (filled[i] && filled[(i + 1 + 4)%4] && map[x + corners[i].first][y + corners[i].second] == '.') goto recurse;
  }
  return;

  recurse:
  map[x][y] = 'A';
  for (int i = 0; i < 4; i++) {
    dfs(x + edges[i].first, y + edges[i].second);
  }
  return;
}

int perimeter(int x, int y, int dir) {
  if (started && start.first == x && start.second == y) return 0;
  started = true;
  //map[x][y] = 'F';

  if (map[x + edges[(dir - 1 + 4)%4].first][y + edges[(dir - 1 + 4)%4].second] == '.') {
    //cout << "right" << endl;
    return 1 + perimeter(x + edges[(dir - 1 + 4)%4].first, y + edges[(dir - 1 + 4)%4].second, (dir - 1 + 4)%4);
  }
  if (map[x + edges[dir].first][y + edges[dir].second] == '.') {
    //cout << "forward" << endl;
    return 1 + perimeter(x + edges[dir].first, y + edges[dir].second, dir);
  }
  //cout << "left" << endl;
  return 1 + perimeter(x + edges[(dir + 1 + 4)%4].first, y + edges[(dir + 1 + 4)%4].second, (dir + 1 + 4)%4);
}

int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> map[i][j];
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      dfs(i, j);
    }
  }

  //goto test;
  for (int i = 1; i < h; i++) {
    for (int j = 1; j < w; j++) {
      if (map[i][j] == 'A') {
        start = make_pair(i - 1, j);
        cout << perimeter(i - 1, j, 1);
        //goto test;
        return 0;
      }
    }
  }

  test:
  cout << endl;
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cout << map[i][j];
    }
    cout << endl;
  }
}

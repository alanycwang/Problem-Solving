#include <iostream>
#include <string.h>

using namespace std;

int m, n, num_waypoints;
int graph[500][500];
bool waypoints[500][500];
bool visited[500][500];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int start[2];

int dfs(int d, int x, int y) {
  int count = 0;
  for (int i = 0; i < 4; i++) {
    if (x + dir[i][0] >= 0 && x + dir[i][0] < m && y + dir[i][1] >= 0 && y + dir[i][1] < n && !visited[x + dir[i][0]][y + dir[i][1]] && abs(graph[x][y] - graph[x + dir[i][0]][y + dir[i][1]]) <= d) {
      visited[x + dir[i][0]][y + dir[i][1]] = true;
      if (waypoints[x + dir[i][0]][y + dir[i][1]]) count++;
      count += dfs(d, x + dir[i][0], y + dir[i][1]);
    }
  }
  //cout << count << endl;
  return count;
}

int main() {
  cin >> m >> n;
  for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> graph[i][j];
  for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
    cin >> waypoints[i][j];
    if (waypoints[i][j]) {
      num_waypoints++;
      start[0] = i;
      start[1] = j;
    }
  }

  int high = 1000000000;
  int low = 0;
  while (high > low) {
    memset(visited, 0, sizeof(visited));
    visited[start[0]][start[1]] = true;
    int mid = (high + low)/2;
    if (1 + dfs(mid, start[0], start[1]) >= num_waypoints) high = mid;
    else low = mid + 1;
  }

  cout << low << endl;
}

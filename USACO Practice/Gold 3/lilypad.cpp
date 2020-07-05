#include <iostream>
#include <deque>
#include <string.h>

using namespace std;

int m, n;
int moves[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
int graph[30][30];
int ways[30][30];
bool visited[30][30];
int dist[30][30];

deque<pair<int, int>> dq;

int main() {
  memset(dist, -1, sizeof(dist));
  cin >> m >> n;
  for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
    cin >> graph[i][j];
    if (graph[i][j] == 3) {
      ways[i][j] = 1;
      dq.push_back(make_pair(i, j));
      visited[i][j] = true;
      dist[i][j] = 0;
    }
  }

  bool found = false;
  pair<int, int> ans;
  int ans2;

  while(!dq.empty()) {
    pair<int, int> loc = dq.front();
    dq.pop_front();
    if (found && dist[loc.first][loc.second] > ans2) break;
    //cout << loc.first << " " << loc.first << " " << loc.second << endl;
    if (graph[loc.first][loc.second] == 4) {
      ans2 = dist[loc.first][loc.second];
      ans = make_pair(loc.first, loc.second);
      found = true;
      continue;
    }
    for (int i = 0; i < 8; i++) if (loc.first + moves[i][0] >= 0 && loc.first + moves[i][0] < m && loc.second + moves[i][1] >= 0 && loc.second + moves[i][1] < n && graph[loc.first + moves[i][0]][loc.second + moves[i][1]] != 2) {
      //ways[loc.first + moves[i][0]][loc.second + moves[i][1]] += ways[loc.first][loc.second];
      //cout << loc.first + moves[i][0] << " " << loc.second + moves[i][1] << endl;
      //cout << ways[loc.first + moves[i][0]][loc.second + moves[i][1]] << endl;
      if (!visited[loc.first + moves[i][0]][loc.second + moves[i][1]]) {
        //cout << loc.first + moves[i][0] << " " << loc.second + moves[i][1] << endl;
        visited[loc.first + moves[i][0]][loc.second + moves[i][1]] = true;
        if (!found && graph[loc.first + moves[i][0]][loc.second + moves[i][1]] == 0) {
          dq.push_back(make_pair(loc.first + moves[i][0], loc.second + moves[i][1]));
          dist[loc.first + moves[i][0]][loc.second + moves[i][1]] = dist[loc.first][loc.second] + 1;
        }
        else if (graph[loc.first + moves[i][0]][loc.second + moves[i][1]] >= 1) {
          dq.push_front(make_pair(loc.first + moves[i][0], loc.second + moves[i][1]));
          dist[loc.first + moves[i][0]][loc.second + moves[i][1]] = dist[loc.first][loc.second];
        }
      }
      if (dist[loc.first + moves[i][0]][loc.second + moves[i][1]] == dist[loc.first][loc.second] && graph[loc.first + moves[i][0]][loc.second + moves[i][1]] >= 1) ways[loc.first + moves[i][0]][loc.second + moves[i][1]] = max(ways[loc.first + moves[i][0]][loc.second + moves[i][1]], ways[loc.first][loc.second]);
      else if (dist[loc.first + moves[i][0]][loc.second + moves[i][1]] - 1 == dist[loc.first][loc.second] && graph[loc.first + moves[i][0]][loc.second + moves[i][1]] == 0) ways[loc.first + moves[i][0]][loc.second + moves[i][1]] += ways[loc.first][loc.second];
    }
    /*for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cout << ways[i][j] << " ";
      }
      cout << endl;
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        printf("%2d ", dist[i][j]);
      }
      cout << endl;
    }*/
  }



  if (!found) {
    cout << - 1;
    return 0;
  }
  cout << ans2 << endl << ways[ans.first][ans.second];
}

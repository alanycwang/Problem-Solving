#include <iostream>
#include <vector>
#include <string.h>
#include <deque>

using namespace std;

int m, n;
int graph[30][30];
vector<pair<int, int>> connected;
bool vis[30][30];
int moves[8][2] = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
int edges[30][30][30][30];
int ways[30][30];
deque<pair<int, pair<int, int>>> dq;

void recurse(int x, int y) {
    for (auto move : moves) {
        if (x + move[0] >= 0 && x + move[0] < m && y + move[1] >= 0 && y + move[1] < n && !vis[x + move[0]][y + move[1]]) {
            if (graph[x + move[0]][y + move[1]] == 1) {
                recurse(x + move[0], y + move[1]);
            }
            else if (graph[x + move[0]][y + move[1]] != 0) {
                vis[x + move[0]][y + move[1]] = true;
                connected.push_back(make_pair(x + move[0], y + move[1]));
            }
        }
    }
}

void ff(int x, int y) {
    connected.clear();
    vis[x][y] = true;
    recurse(x, y);
    for (auto i : connected) {
        for (auto j: connected) {
            edges[i.first][i.second][j.first][j.second] = 0;
            edges[j.first][j.second][i.first][i.second] = 0;
        }
    }
    //cout << "working" << endl;
}

int main() {
    pair<int, int> end;
    cin >> m >> n;
    for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) {
        cin >> graph[i][j];
        if (graph[i][j] == 3) {
            dq.push_back(make_pair(0, make_pair(i, j)));
            ways[i][j] = 1;
        }
        if (graph[i][j] == 4) end = make_pair(i, j);
    }
    memset(edges, -1, sizeof(edges));
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (graph[i][j] == 1 && !vis[i][j]) {
        vis[i][j] = true;
        ff(i, j);
    }
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (graph[i][j] != 2) for (auto move : moves) if (edges[i][j][i + move[0]][j + move[1]] == -1 && graph[i + move[0]][j+move[0]] != 2) edges[i][j][i + move[0]][j + move[1]] = 1;

    bool found = false;

    memset(vis, 0, sizeof(vis));
    pair<int, pair<int, int>> temp = dq.front(); dq.pop_front();
    vis[temp.second.first][temp.second.second] = true;
    while (!dq.empty()) {
        pair<int, pair<int, int>> loc = dq.front();
        if (graph[loc.second.first][loc.second.second] == 4) {
            found = true;
            cout << loc.first << endl;
            continue;
        }
        for (auto move : moves) {
            if (loc.second.first + move[0] >= 0 && loc.second.first + move[0] < m && loc.second.second + move[1] >= 0 && loc.second.second + move[1] < n){
                if (!vis[loc.second.first + move[0]][loc.second.second + move[1]] && edges[loc.second.first][loc.second.second][loc.second.first + move[0]][loc.second.second + move[1]] == 0) {
                    vis[loc.second.first + move[0]][loc.second.second + move[1]] = true;
                    dq.push_front(make_pair(loc.first, make_pair(loc.second.first + move[0], loc.second.second + move[1])));
                    ways[loc.second.first + move[0]][loc.second.second + move[1]] = ways[loc.second.first][loc.second.second];
                } else if (!found && !vis[loc.second.first + move[0]][loc.second.second + move[1]] && edges[loc.second.first][loc.second.second][loc.second.first + move[0]][loc.second.second + move[1]] == 1) {
                    vis[loc.second.first + move[0]][loc.second.second + move[1]] = true;
                    dq.push_back(make_pair(loc.first + 1,make_pair(loc.second.first + move[0], loc.second.second + move[1])));
                    ways[loc.second.first + move[0]][loc.second.second + move[1]] += ways[loc.second.first][loc.second.second];
                }
            }
        }
    }
    cout << ways[end.first][end.second];
}
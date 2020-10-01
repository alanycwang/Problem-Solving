//
// Created by alany on 8/29/2020.
//

#include <iostream>
#include <set>
#include <queue>
#include <cstring>

using namespace std;

int m, n;
int graph[30][30];
pair<int, int> start, target;
bool visited[30][30];
int dist[30][30];
int moves[8][2] = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
set<pair<int, int>> edges[30][30];
set<pair<int, int>> adj;
long long ways[30][30];

void recurse(int x, int y) {
    for (auto move : moves) if (x + move[0] >= 0 && x + move[0] < m && y + move[1] >= 0 && y + move[1] < n) {
        if (graph[x + move[0]][y + move[1]] != 2 && graph[x + move[0]][y + move[1]] != 1) adj.insert(make_pair(x + move[0], y + move[1]));
        else if (!visited[x + move[0]][y + move[1]] && graph[x + move[0]][y + move[1]] == 1) {
            visited[x + move[0]][y + move[1]] = true;
            recurse(x + move[0], y + move[1]);
        }
    }
}

void ff(int x, int y) {
    recurse(x, y);
    for (auto i : adj) for (auto j : adj) {
        edges[i.first][i.second].insert(j);
        //if (i == make_pair(5, 1)) cout << j.first << " " << j.second << endl;
    }
    /*if (x == 7 && y == 2) {
        for (auto i : adj) {
            cout << i.first << " " << i.second << endl;
        }
    }*/
    set<pair<int, int>> temp;
    adj = temp;
}

void ff2(int x, int y) {
    for (auto move : moves) if (x + move[0] >= 0 && x + move[0] < m && y + move[1] >= 0 && y + move[1] < n && graph[x + move[0]][y + move[1]] != 1 && graph[x + move[0]][y + move[1]] != 2) {
        edges[x][y].insert(make_pair(x + move[0], y + move[1]));
        /*if (x == 5 && y == 1) {
            cout << x + move[0] << " " << y + move[1] << endl;
        }*/
    }
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
        cin >> graph[i][j];
        if (graph[i][j] == 3) start = make_pair(i, j);
        else if (graph[i][j] == 4) target = make_pair(i, j);
    }

    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
        if ((graph[i][j] == 1) && !visited[i][j]) ff(i, j);
    }

    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
        if ((graph[i][j] == 0  || graph[i][j] == 3 || graph[i][j] == 4)) ff2(i, j);
    }

    ways[start.first][start.second] = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(start.first, start.second));
    memset(visited, 0, sizeof(visited));
    memset(dist, -1, sizeof(dist));
    dist[start.first][start.second] = 0;
    visited[start.first][start.second] = true;
    while (!q.empty()) {
        //cout << "working" << endl;
        pair<int, int> loc = q.front();
        q.pop();
        /*cout << dist[loc.first][loc.second] << " " << loc.first << " " << loc.second << " " << ways[loc.first][loc.second] << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << ways[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;*/

        if (graph[loc.first][loc.second] == 4) {
            cout << dist[loc.first][loc.second] - 1 << endl << ways[loc.first][loc.second];
            return 0;
        }
        for (auto i : edges[loc.first][loc.second]) {
            if (i == loc) continue;
            if (dist[i.first][i.second] != dist[loc.first][loc.second]) ways[i.first][i.second] += ways[loc.first][loc.second];
            if (!visited[i.first][i.second]) {
                visited[i.first][i.second] = true;
                //if (loc.second == make_pair(5, 1)) cout << i.first << " " << i.second << endl;
                q.push(make_pair(i.first, i.second));
                dist[i.first][i.second] = dist[loc.first][loc.second] + 1;
            }
        }
    }

    cout << -1;
}


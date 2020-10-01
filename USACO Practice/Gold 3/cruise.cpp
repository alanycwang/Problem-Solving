//
// Created by alany on 9/15/2020.
//

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

long long n, m, k;
long long graph[1001][2];
bool sequence[501];
long long graph2[1001];
bool visited[1001];
vector<long long> cycle;

void dfs(long long loc) {
    if (visited[loc]) {
        return;
    }
    visited[loc] = true;
    cycle.push_back(graph2[loc]);
    dfs(graph2[loc]);
}

int main() {
    cin >> n >> m >> k;
    for (long long i = 0; i < n; i++) {
        cin >> graph[i][0] >> graph[i][1];
        graph[i][0]--;
        graph[i][1]--;
    }
    for (long long i = 0; i < m; i++) {
        char temp;
        cin >> temp;
        if (temp == 'L') sequence[i] = 0;
        else sequence[i] = 1;
    }

    //cout << "working" << endl;

    for (long long i = 0; i < n; i++) {
        long long loc = i;
        for (long long j = 0; j < m; j++) {
            loc = graph[loc][sequence[j]];
        }
        graph2[i] = loc;
    }
    dfs(0);

    long long idx = 0;
    for (long long i = 0; i < cycle.size(); i++) {
        if(cycle[i] == cycle[cycle.size() - 1]) {
            //cout << i << " " << cycle[cycle.size() - 1] << endl;
            idx = i;
            break;
        }
    }

    //cout << idx << endl;
    //cout << cycle.size() << endl;
    if (idx < k) k -= int(idx);

    if (idx < k) for (long long i = 0; i < idx; i++) {
        cycle.erase(cycle.begin());
    }
    //cout << cycle.size() << endl;
    //cout << k << endl;
    if (cycle.size() > 1) cout << cycle[int((k - 1)%(cycle.size() - 1))] + 1 << endl;
    else cout << cycle[0] + 1;

    /*for (long long i = 0; i < n; i++) {
        cout << graph2[i] << " ";
    }
    cout << endl;
    for (auto i : cycle) {
        cout << i << " ";
    }*/
}

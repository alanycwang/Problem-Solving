//
// Created by alany on 9/28/2020.
//

#include <iostream>
#include <set>

using namespace std;

int n;
set<int> graph[100000]; //bool—true: incoming node

bool merge(int x) {
    bool found = false;
    for (auto i : graph[x]) {
        if (graph[i].size() == 1 && *graph[i].begin() > i) return true;
        if (i < x && found) return true;
        if (i < x) found = true;
    }
    for (auto i : graph[x]) {
        if (i < x) return false;
    }
    return true;
}

bool split(int x) {
    bool found = false;
    for (auto i : graph[x]) {
        if (graph[i].size() == 1 && *graph[i].begin() < i) return true;
        //cout << i << endl;
        if (i > x && found) return true;
        if (i > x) found = true;
    }
    for (auto i : graph[x]) {
        if (i > x) return false;
    }

    return true;
}



int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1].insert(b-1);
        graph[b-1].insert(a-1);
    }
    //cout << split(3) << endl << endl;
    int m = -1;
    int s = -1;
    for (int i = 0; i < n; i++) {
        if (merge(i)) m = i;
        if (split(i)) {
            s = i;
            break;
        }
    }

    for (int i = m; i <= s; i++) {
        cout << i + 1 << endl;
    }
}

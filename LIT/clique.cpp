//
// Created by alany on 8/21/2020.
//

#include <iostream>
#include <set>
#include <map>

using namespace std;

int n, m;
long long currencies[20];
set<int> children[20];
bool visited[20];

long long w(set<int> c, int idx) {
    map<int, int> dp;
    dp.insert(make_pair(0, 1));
    for (auto i : c) {
        for (auto j : dp) {
            if (j.first + currencies[i] <= currencies[idx]) {
                if (dp.find(j.first + currencies[i]) != dp.end()) {
                    dp[j.first + currencies[i]] = (dp[j.first + currencies[i]] + j.second)%1000000007;
                }
                else {
                    dp.insert(make_pair((j.first + currencies[i])%1000000007, j.second));
                }
            }
        }
    }
    return (dp[currencies[idx]]%1000000007 + 1000000007)%1000000007;
}

/*long long recurse(int idx) {
    //cout << idx << " " << memoize[idx] << endl;
    if (memoize[idx] != -1) return memoize[idx];
    long long ways = 1;
    for (auto i : children[idx]) {
        ways *= recurse(i);
        ways %= 1000000007;
    }
    ways *= w(children[idx], idx);
    cout << w(children[idx], idx) << " " << idx << " " << currencies[idx] << endl;
    //for (auto i : children[idx]) cout << i << " ";
    //cout << endl;
    memoize[idx] = ways % 1000000007;
    return ways % 1000000007;
}*/

void recurse(int idx) {
    //cout << idx << endl;
    for (auto i : children[idx]) {
        if (!visited[i]) {
            visited[i] = true;
            recurse(i);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> currencies[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        children[b-1].insert(a-1);
    }
    recurse(n-1);
    visited[n-1] = true;
    long long ans = 1;
    for (int i = 1; i < n; i++) {
        if (visited[i]) {
            ans *= w(children[i], i);
            ans %= 1000000007;
        }
    }
    cout << ans;
}
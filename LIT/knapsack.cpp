//
// Created by alany on 8/21/2020.
//

#include <vector>
#include <set>
#include <iostream>
#include <map>

using namespace std;

int currencies[5];

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
    return dp[currencies[idx]]%1000000007;
}

int main() {
    set<int> temp;
    temp.insert(1);
    temp.insert(2);
    temp.insert(3);
    currencies[0] = 27;
    currencies[1] = 1;
    currencies[2] = 3;
    currencies[3] = 9;
    cout << (w(temp, 0));
}
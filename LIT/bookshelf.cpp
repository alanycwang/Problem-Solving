//
// Created by alany on 8/21/2020.
//

#include <iostream>
#include <algorithm>

using namespace std;

int r, b, s;
pair<int, bool> books[1000];
int sum = 0;
int ans = 0;
int last = 1000000000;
bool vis[1000];

bool helper (pair<int, bool> a, pair<int, bool> b) {
    return a.first < b.first;
}

void recurse (bool red) {
    //cout << "working " << sum << endl;
    if (sum > s) return;
    else if (sum == s) {
        //cout << "found" << endl;
        ans++;
        return;
    }
    for (int i = 0; i < r + b; i++) {
        //cout << books[i].first << endl;
        if (books[i].first > last) break;
        if (books[i].second == red && !vis[i]) {
            //cout << books[i].first << endl;
            sum += books[i].first;
            int temp = last;
            last = books[i].first;
            vis[i] = true;
            recurse (!red);
            sum -= books[i].first;
            vis[i] = false;
            last = temp;
        }
    }
}

int main() {
    cin >> r >> b >> s;
    for (int i = 0; i < r; i++) {
        int temp;
        cin >> temp;
        books[i] = make_pair(temp, true);
    }
    for (int i = 0; i < b; i++) {
        int temp;
        cin >> temp;
        books[r + i] = make_pair(temp, false);
    }
    sort(books, books + r + b, helper);
    recurse(true);
    recurse(false);
    cout << ans;
}
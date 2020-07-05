#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    pair<int, int> drops[n];
    for (int i = 0; i < n; i++) cin >> drops[i].first >> drops[i].second;

    sort(drops, drops + n);
    multiset<int> ms;
    int f = 0;
    int b = 0;
    int ans = 1000000000;
    while (b < n) {
        if (ms.size() > 0 && *ms.rbegin() - *ms.begin() >= d) {
            ans = min(ans, drops[b-1].first - drops[f].first);
            ms.erase(ms.find(drops[f].second));
            f++;
        }
        else {
            ms.insert(drops[b].second);
            b++;
        }
        /*cout << *ms.rbegin() << " " << *ms.begin() << endl;
        for (auto i : ms) cout << i << " ";
        cout << endl;*/
    }
    if (ans == 1000000000) {
        cout << -1;
        return 0;
    }
    cout << ans;
}

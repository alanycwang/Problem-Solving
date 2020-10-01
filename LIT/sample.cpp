//
// Created by alany on 8/21/2020.
//

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        ans += temp;
    }
    cout << ans;
}
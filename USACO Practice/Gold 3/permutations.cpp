//
// Created by alany on 9/30/2020.
//
#include <iostream>
#include <map>
#include <vector>

using namespace std;

string word;
int l;
map<char, int> letters;

uint64_t choose(int n, int k) {
    uint64_t ans = 1;
    for (int i = 0; i < k; i++) ans *= n-i;
    for (int i = 2; i <= k; i++) ans /= i;
    return uint64_t(ans);
}

int recurse(map<char, int>::iterator idx, vector<int> sizes, int left) {
    if (idx == letters.end()) {
        int ans = 1;
        int temp = l;
        for (auto & i : sizes) {
            ans *= choose(temp, i);
            temp -= i;
        }
        if (temp < 0) return 0;
        for (int i = 0; i < temp; i++) ans *= left - i;
        return ans;
    }

    int ans = 0;
    for (int i = 1; i <= idx->second; i++) {
        if (i == 1) ans += recurse(next(idx), sizes, left + 1);
        else {
            sizes.push_back(i);
            ans += recurse(next(idx), sizes, left);
            sizes.pop_back();
        }
    }
    return ans;
}

int main() {
    cin >> word;
    cin >> l;
    for (auto & letter : word) {
        if (letters.find(letter) != letters.end()) letters[letter]++;
        else letters.insert(make_pair(letter, 1));
    }
    int left = letters.size();
    for (map<char, int>::reverse_iterator it = letters.rbegin(); it != letters.rend(); it++) if (it->second <= 1) letters.erase(it->first);
    if (letters.begin()->second <= 1) letters.erase(letters.begin());
    //for (auto & letter : letters) cout << letter.first << " " << letter.second << endl;
    vector<int> temp;

    cout << recurse(letters.begin(), temp, left - letters.size());
}

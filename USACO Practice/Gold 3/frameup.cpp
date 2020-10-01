//
// Created by alany on 9/30/2020.
//

#include <iostream>
#include <set>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int h, w;
char graph[30][30];
set<int> overlaps[26]; //all the letters that i covers
int corners[26][4]; //low x, low y, high x, high y
pair<int, int> dir[4] = {make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0)};
vector<int> lst;
set<char> found;

void recurse(int len) {
    /*for (auto i : lst) {
        cout << i;
    }
    cout << endl;*/
    if (len == found.size()) {
        for (auto i : lst) cout << char(i + 'A');
        cout << endl;
        return;
    }
    for (auto & letter : found) {
        bool f = false;
        for (auto & l : overlaps[letter - 'A']) if (find(lst.begin(), lst.end(), l) == lst.end()) f = true;
        if (f || find(lst.begin(), lst.end(), letter - 'A') != lst.end()) continue;
        lst.push_back(int(letter - 'A'));
        recurse(len + 1);
        lst.erase(lst.end() - 1);
    }
}

int main() {
    memset(corners, -1, sizeof(corners));
    cin >> h >> w;
    for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) {
        cin >> graph[i][j];
        if (graph[i][j] != '.') {
            found.insert(graph[i][j]);
            if (corners[graph[i][j] - 'A'][0] == -1) {
                corners[graph[i][j] - 'A'][0] = i;
                corners[graph[i][j] - 'A'][1] = j;
            }
            corners[graph[i][j] - 'A'][2] = i;
            corners[graph[i][j] - 'A'][3] = max(corners[graph[i][j] - 'A'][3], j);
            corners[graph[i][j] - 'A'][1] = min(corners[graph[i][j] - 'A'][1], j);
        }
    }

    /*for (auto & corner : corners) {
        for (int j : corner) {
            cout << j << " ";
        }
        cout << endl;
    }*/

    for (int i = 0; i < 26; i++) {
        if (corners[i][0] == -1) continue;
        int dim[2] = {corners[i][2] - corners[i][0], corners[i][3] - corners[i][1]};
        //cout << dim[0] << " " << dim[1] << endl;
        pair<int, int> loc = make_pair(corners[i][0], corners[i][1]);
        //cout << "working" << endl;
        for (int j = 0; j < 4; j++) for (int k = 0; k < dim[(j+1)%2]; k++) {
            //cout << loc.first << " " << loc.second << endl;
            if (graph[loc.first][loc.second] != i + 'A') overlaps[int(graph[loc.first][loc.second] - 'A')].insert(i);
            loc.first += dir[j].first;
            loc.second += dir[j].second;
        }
    }

    //cout << "working" << endl;

    /*for (int i = 0; i < 26; i++) {
        cout << char(i + 'A') << " ";
        for (auto & overlap : overlaps[i]) {
            cout << char(overlap + 'A') << " ";
        }
        cout << endl;
    }*/

    //for (int i = 0; i < 26; i++) overlaps[i].insert(i);

    //cout << "working" << endl;

    recurse(0);
}


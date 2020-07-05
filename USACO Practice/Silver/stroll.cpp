#include <iostream>

using namespace std;

int p;
int nodes[1000][3];
int ans = 0;
int length = 0;

void recurse(int node){
    if (node == 0) {
        if (length > ans){
            ans = length;
        }
        return;
    }
    for (int i = 0; i < p; i++){
        if (nodes[i][0] == node){
            length++;
            recurse(nodes[i][1]);
            recurse(nodes[i][2]);
            length--;
        }
    }
}

int main(){
    cin >> p;
    for (int i = 0; i < p; i++){
        cin >> nodes[i][0] >> nodes[i][1] >> nodes[i][2];
    }
    recurse(1);
    cout << ans;
}
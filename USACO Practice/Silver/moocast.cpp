#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

int cows[10000][4];
int reached = 0;
int n;
int ans = 0;
bool visited[10000];

void recurse(int cow){
    for (int i = 0; i < n; i++){
        long long a = pow(cows[cow][0]-cows[i][0], 2);
        long long b = pow (cows[cow][1]-cows[i][1], 2);
        long long x = a+b;
        long long y = pow(cows[cow][2], 2);
        if (cow != i && x <= y && !visited[i]){
            visited[i] = true;
            reached++;
            recurse(i);
        }
    }
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> cows[i][0] >> cows[i][1] >> cows[i][2];
    }
    for (int i = 0; i < n; i++){
        visited[i] = true;
        recurse(i);
        if (reached > ans){
            ans = reached;
        }
        reached = 0;
        memset(visited, 0, sizeof(visited));
    }
    cout << ans + 1;
}
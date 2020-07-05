#include <iostream>
#include <cmath>

using namespace std;

int n, m;
char cow[50][50];
long long minimum = 99999999999;
bool visited[50][50];
bool visited2[50][50];


void recurse(int x, int y, char group){
    if (cow[x+1][y] == 'X' && !visited[x+1][y]){
        visited[x+1][y] = true;
        cow[x+1][y] = group;
        recurse(x+1, y, group);
    }
    if (cow[x-1][y] == 'X' && !visited[x-1][y]){
        visited[x-1][y] = true;
        cow[x-1][y] = group;
        recurse(x-1, y, group);
    }
    if (cow[x][y+1] == 'X' && !visited[x][y+1]){
        visited[x][y+1] = true;
        cow[x][y+1] = group;
        recurse(x, y+1, group);
    }
    if (cow[x][y-1] == 'X' && !visited[x][y-1]){
        visited[x][y-1] = true;
        cow[x][y-1] = group;
        recurse(x, y-1, group);
    }
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> cow[i][j];
        }
    }
    char group = '1';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cow[i][j] == 'X' && !visited[i][j]) {
                visited[i][j] = true;
                cow[i][j] = group;
                recurse(i, j, group);
                group = '2';
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (cow[i][j] == '1'){
                for (int k = 0; k < n; k++){
                    for (int l = 0; l < m; l++){
                        if (cow[k][l] == '2'){
                            int length = abs(i-k) + abs(j-l);
                            if(length < minimum){
                                minimum = length;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << minimum-1;
}
#include <bits/stdc++.h>

using namespace std;

bool q;
int dist = 0;
int n, k;
bool visited[100][10];
string board[100];

void drop(){
  for (int i = 9; i > -1; i--){
    for (int j = n-2; j < -1; j--){
      if (board[i][j+1] == '0'){
        board[i][j+1] = board[i][j];
        board[i][j] = '0';
      }
    }
  }
}

void recurse(int x, int y, char z){
  int chx[4] = {x + 1, x-1, x, x};
  int chy[4] = {y, y, y+1, y - 1};
  for (int i = 0; i < 4; i++){
    if (chx[i] >= 0 && chy[i] >= 0 && chx[i] < n && chy[i] < 10 && !visited[chx[i]][chy[i]] && map[chx[i]][chy[i]] == z){
      visited[chx[i]][chy[i]] = true;
      dist++;
      if (dist >= k){
        q = true;
      }
      recurse(chx[i], chy[i], z);
    }
  }
  if (q){
    board[x][y] = '0';
  }
}

int main(){
  cin >> n >> k;
  for (int i = 0; i < n; i++){
    cin >> board[i];
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 10; j++){

    }
  }
  cout << board[0][1] << endl;
  drop();
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 10; j++){
      cout << board[i][j];
    }
    cout << endl;
  }
}

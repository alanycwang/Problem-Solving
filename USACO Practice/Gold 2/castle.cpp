#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>

using namespace std;

int m, n;
int map[50][50];
bool visited[50][50];

int dfs(int x, int y){
  bool walls[4];
  int a = map[x][y];
  int b = 0;
  if (a % 2 != 0 && a != 0){
    walls[0] = true;
    a--;
  }
  else {
    walls[0] = false;
  }
  if (a % 4 != 0 && a != 0){
    walls[1] = true;
    a -= 2;
  }
  else {
    walls[1] = false;
  }
  if (a % 8 != 0 && a != 0){
    walls[2] = true;
    a -= 4;
  }
  else {
    walls[2] = false;
  }
  if (a != 0){
    walls[3] = true;
  }
  else {
    walls[3] = false;
  }
  int chx[4] = {x, x - 1, x, x + 1};
  int chy[4] = {y - 1, y, y + 1, y};
  for (int i = 0; i < 4; i++){
    if (!walls[i] && chx[i] >= 0 && chx[i] < n && chy[i] >= 0 && chy[i] < m && !visited[chx[i]][chy[i]]){
      visited[chx[i]][chy[i]] = true;
      b++;
      b += dfs(chx[i], chy[i]);
    }
  }
  return b;
}

int main(){
  int best = 0;
  vector<int> rooms;
  int n_rooms = 0;
  cin >> m >> n;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> map[i][j];
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (!visited[i][j]){
        visited[i][j] = true;
        rooms.push_back(dfs(i, j) + 1);
        n_rooms++;
      }
    }
  }
  cout << n_rooms << endl;
  int best2 = 0;
  for (auto x : rooms){
    best2 = max(x, best2);
  }
  cout << best2 << endl;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      bool walls[4];
      int a = map[i][j];
      if (a % 2 != 0 && a != 0){
        walls[0] = true;
        a--;
      }
      else {
        walls[0] = false;
      }
      if (a % 4 != 0 && a != 0){
        walls[1] = true;
        a -= 2;
      }
      else {
        walls[1] = false;
      }
      if (a % 8 != 0 && a != 0){
        walls[2] = true;
        a -= 4;
      }
      else {
        walls[2] = false;
      }
      if (a != 0){
        walls[3] = true;
      }
      else {
        walls[3] = false;
      }
      for (int k = 0; k < 4; k++){
        if (walls[k]){
          memset(visited, 0, sizeof(visited));
          int b = 0;
          b++;
          int c = pow(2, k);
          map[i][j] -= c;
          visited[i][j] = true;
          b += dfs(i, j);
          best = max(b, best);
          map[i][j] += c;
        }
      }
    }
  }
  cout << best;
}

#include <iostream>

using namespace std;

int m, n;
int pond[30][30];
bool visited[30][30];
int least = 1000000000;
int count = 0;

void dfs (int x, int y, int dist){
  if (dist > least){return;}
  if (pond[x][y] == 4){
    if (dist == least){
      count++;
    }
    else if (dist < least){
      least = dist;
      count = 1;
    }
    return;
  }
  int chx[8] = {x-2, x-2, x+2, x+2, x-1, x-1, x+1, x+1};
  int chy[8] = {y-1, y+1, y-1, y+1, y-2, y+2, y-2, y+2};
  for (int i = 0; i < 8; i++){
    if (chx[i] >= 0 && chx[i] < m && chy[i] >= 0 && chy[i] < n && !visited[chx[i]][chy[i]] && pond[chx[i]][chy[i]] != 2){
      visited[chx[i]][chy[i]] = true;
      if (pond[chx[i]][chy[i]] == 0){
        dfs(chx[i], chy[i], dist + 1);
      }
      else if (pond[chx[i]][chy[i]] == 1 || pond[chx[i]][chy[i]] == 4){
        dfs(chx[i], chy[i], dist);
      }
      visited[chx[i]][chy[i]] = false;
    }
  }
}

int main(){
  cin >> m >> n;
  pair<int, int> start;int chx[8] = {-2, -2, 2, 2, -1, 1, -1, 1};
  int chy[8] = {-1, 1, -1, 1, -2, 2, -2, 2};
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      cin >> pond[i][j];
      if (pond[i][j] == 3){
        start = make_pair(i, j);
      }
    }
  }

  visited[start.first][start.second] = true;
  dfs(start.first, start.second, 0);

  if (least == 1000000000){cout << -1 << endl; return 0;}
  cout << least << endl << count;
}

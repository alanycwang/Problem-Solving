#include <iostream>
#include <queue>

using namespace std;

bool visited[30][30];

struct location{
  int x, y, dist;
};

int main(){
  int m, n, m1, m2, bx, by, dx, dy;
  cin >> m >> n >> m1 >> m2;
  int pond[m][n];
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      cin >> pond[i][j];
      if (pond[i][j] == 3){
        bx = i;
        by = j;
      }
      else if (pond[i][j] == 4){
        dx = i;
        dy = j;
      }
    }
  }
  queue<location> q;
  location a;
  a.x = bx;
  a.y = by;
  a.dist = 0;
  q.push(a);
  while (!q.empty()){
    location b = q.front();
    q.pop();
    if (b.x == dx && b.y == dy){
      cout << b.dist;
      break;
    }
    int mx[8] = {m2, m1, m2, -m2, -m1, m1, -m2, -m1};
    int my[8] = {m1, m2, -m1, m1, m2, -m2, -m1, -m2};
    for (int i = 0; i < 8; i++){
      if (b.x + mx[i] >= 0 && b.x + mx[i] < m && b.y + my[i] >= 0 && b.y + my[i] < n && !visited[b.x + mx[i]][b.y + my[i]] && (pond[b.x + mx[i]][b.y + my[i]] == 1 || pond[b.x + mx[i]][b.y + my[i]] == 4)){
        location c;
        c.x = b.x + mx[i];
        c.y = b.y + my[i];
        c.dist = b.dist+1;
        visited[c.x][c.y] = true;
        q.push(c);
      }
    }
  }
}

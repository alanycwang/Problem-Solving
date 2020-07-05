#include <iostream>
#include <queue>

using namespace std;
struct location{
  int distance, x, y;
};

bool visited[150][150];

int main(){
  int m, n;
  cin >> n >> m;
  char pasture[m][n];
  int k[2];
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      cin >> pasture[i][j];
      if (pasture[i][j] == 'K'){
        k[0] = i;
        k[1] = j;
      }
    }
  }
  //cout << endl;
  /*for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      cout << pasture[i][j];
    }
    cout << endl;
  }*/
  queue<location> q;
  location a;
  a.x = k[0];
  a.y = k[1];
  a.distance = 0;
  q.push(a);
  while(!q.empty()){
    location b = q.front();
    //cout << b.x << " " << b.y << " " << b.distance << endl;
    q.pop();
    int mx[8] = {1, 2, 1, -1, 2, -2, -2, -1};
    int my[8] = {2, 1, -2, 2, -1, 1, -1, -2};
    if (pasture[b.x][b.y] == 'H'){
      //cout << pasture[b.x][b.y] << " " << b.x << " " << b.y << endl;
      cout << b.distance;
      return 0;
    }
    for (int i = 0; i < 8; i++){
      if (b.x + mx[i] >= 0 && b.y + my[i] >= 0 && b.x + mx[i] < m && b.y + my[i] < n && pasture[b.x+mx[i]][b.y + my[i]] != '*' && !visited[b.x+mx[i]][b.y + my[i]]){
        location c;
        visited[b.x+mx[i]][b.y + my[i]] = true;
        c.x = b.x + mx[i];
        c.y = b.y + my[i];
        c.distance = b.distance + 1;
        q.push(c);
      }
    }
  }
}

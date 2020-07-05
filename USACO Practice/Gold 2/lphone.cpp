#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

struct laser{
  int x, y, turns, direction;
};

int main(){
  int w;
  int h;
  cin >> w >> h;
  char pasture[h][w];
  laser a;
  bool start = false;
  bool visited[h][w];
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cin >> pasture[i][j];
      if (pasture[i][j] == 'C' && !start){
        a.x = i;
        a.y = j;
        visited[i][j] = true;
        start = true;
      }
    }
  }
  a.turns = 0;
  a.direction = -1;
  queue<laser> q;
  q.push(a);
  while(!q.empty()){
    laser b = q.front();
    //cout << b.x << " " << b.y << " " << b.turns << endl;
    q.pop();
    int movex[4] = {-1, 1, 0, 0};
    int movey[4] = {0, 0, 1, -1};
    if (pasture[b.x][b.y] == 'C'){
      if (b.x != a.x || b.y != a.y){
        cout << b.turns-1;
        return 0;
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 1; j < 100; j++){
        int locationx = movex[i] * j + b.x;
        int locationy = movey[i] * j + b.y;

        if (i != b.direction && locationx >= 0 && locationy >= 0 && locationx < h && locationy < w && visited[locationx][locationy] == false){
          //cout <<"neighbor " << locationx << " " << locationy << " " << b.turns+1 << endl;
          if (pasture[locationx][locationy] == '*'){
            break;
          }
          visited[locationx][locationy] = true;
          laser c;
          c.x = locationx;
          c.y = locationy;
          c.turns = b.turns+1;
          //cout << "neighbor"<< c.x << " " << c.y << c.turns << endl;
          c.direction = i;
          q.push(c);
        }
      }
    }
    //cout << endl;
  }
}

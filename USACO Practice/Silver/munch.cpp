#include <iostream>
#include <string>
#include <queue>

using namespace std;

bool visited[101][101];

struct location{
  int x;
  int y;
  int distance;
};

int main(){
  int r, c;
  cin >> r >> c;
  string pasture[r];
  for (int i = 0; i < r; i++){
    cin >> pasture[i];
  }
  visited[0][0] = true;
  queue<location> q;
  location a;
  a.x = 0;
  a.y = 0;
  a.distance = 0;
  q.push(a);
  while (!q.empty()){
    location b = q.front();
    q.pop();
    location c;
    //cout << b.x << " " << b.y << endl;
    if (pasture[b.x][b.y] == 'C'){
      cout << b.distance;
      break;
    }
    if(!visited[b.x+1][b.y] && (pasture[b.x+1][b.y] == '.' || pasture[b.x+1][b.y] == 'C')){
      c.x = b.x+1;
      c.y = b.y;
      c.distance = b.distance+1;
      visited[b.x+1][b.y] = true;
      q.push(c);
    }
    if(!visited[b.x][b.y+1] && pasture[b.x][b.y+1] != '*' && (pasture[b.x][b.y+1] == '.' || pasture[b.x][b.y+1] == 'C')){
      c.x = b.x;
      c.y = b.y+1;
      c.distance = b.distance+1;
      visited[b.x][b.y+1] = true;
      q.push(c);
    }
    if(b.x != 0 && !visited[b.x-1][b.y] && pasture[b.x-1][b.y] != '*' && (pasture[b.x-1][b.y] == '.' || pasture[b.x-1][b.y] == 'C')){
      c.x = b.x-1;
      c.y = b.y;
      c.distance = b.distance+1;
      visited[b.x-1][b.y] = true;
      q.push(c);
    }
    if(b.y != 0 && !visited[b.x][b.y-1] && pasture[b.x][b.y-1] != '*' && (pasture[b.x][b.y-1] == '.' || pasture[b.x][b.y-1] == 'C')){
      c.x = b.x;
      c.y = b.y-1;
      c.distance = b.distance+1;
      visited[b.x][b.y+1] = true;
      q.push(c);
    }
  }
}

#include <iostream>
#include <queue>
using namespace std;

struct location{
  int x, y, time;
};

bool visited[300][300];

int main(){
  int n, m;
  cin >> n >> m;
  string maze[n];
  for (int i = 0; i < n; i++){
    cin >> maze[i];
  }
  queue<location> q;
  location a;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (maze[i][j] == '@'){
        a.x = i;
        a.y = j;
        break;
      }
    }
  }
  a.time = 0;
  q.push(a);
  while (!q.empty()){

    location b = q.front();
    q.pop();
    int mx[4] = {0, 0, 1, -1};
    int my[4] = {1, -1, 0, 0};
    if (maze[b.x][b.y] == '='){
      cout << b.time;
      break;
    }
    for (int i = 0; i < 4; i++){
      int movex = b.x + mx[i];
      int movey = b.y + my[i];
      if (movex >= 0 && movey >= 0 && movex < n && movey < m && !visited[movex][movey] && maze[movex][movey] != '#'){
        visited[movex][movey] = true;
        if (maze[movex][movey] >= 'A' && maze[movex][movey] <= 'Z'){
          bool stop = false;
          for (int j = 0; j < n; j++){
            for (int k = 0; k < m; k++){
              if (maze[j][k] == maze[movex][movey]){
                if (j != movex || k != movey){
                  movex = j;
                  movey = k;
                  //visited[movex][movey] = true;
                  stop = true;
                  break;
                }
              }
            }
            if (stop){
              break;
            }
          }
        }
        location c;
        c.x = movex;
        c.y = movey;
        c.time = b.time+1;
        cout << c.x << " " << c.y << endl;
        q.push(c);
      }
    }
  }
}

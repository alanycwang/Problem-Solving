#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

struct startLocation{
  int x, y, b;
};

int h, w, n, x, y;
int map[1002][1002];
bool stop = false;
queue<startLocation> q;

void ff(int x1, int y1, int b){
  //cout << "working" << endl;
  //cout << x1 << " " << y1 << " " << b << endl;
  if (stop){
    return;
  }
  if (x1 == 0 && y1 == 0){
    cout << b-1;
    stop = true;
    return;
  }
  if (map[x1][y1] == -1){
    startLocation c;
    c.x = x1;
    c.y = y1;
    c.b = b+1;
    q.push(c);
    map[x1][y1] = b+1;
    return;
  }
  map[x1][y1] = b;
  int modx[4] = {x1 + 1, x1 - 1, x1, x1};
  int mody[4] = {y1, y1, y1 + 1, y1 - 1};
  for (int i = 0; i < 4; i++){
    if (modx[i] >= 0 && modx[i] <= h && mody[i] >= 0 && mody[i] <= w && (map[modx[i]][mody[i]] <=0)){
      ff(modx[i], mody[i], b);
    }
  }
}

int main(){
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++){
    int x2, y2;
    cin >> x2 >> y2;
    map[x2][y2] = -1;
    if (x2 > h){
      h = x2;
    }
    if (y2 > w){
      w = y2;
    }
  }
  h++;
  w++;
  startLocation a;
  a.x = x;
  a.y = y;
  a.b = 1;
  q.push(a);
  while (!q.empty()){
    if (stop){
      break;
    }
    startLocation d = q.front();
    q.pop();
    int x1 = d.x;
    int y1 = d.y;
    int b = d.b;
    map[x1][y1] = b;

    ff(d.x, d.y, d.b);
/*    queue<pair<int, int>> q2;
    pair<int, int> a2;
    a2.first = x1;
    a2.second = y1;
    q2.push(a2);
    while(!q2.empty()){
      //cout << "working" << endl;
      pair<int, int> b2 = q2.front();
      q2.pop();
      if (stop){
        break;
      }
      if (b2.first == 0 && b2.second == 0){
        cout << b;
        stop = true;
        break;
      }
      if (map[b2.first][b2.second] == -1){
        startLocation c;
        c.x = b2.first;
        c.y = b2.second;
        c.b = b+1;
        q.push(c);
        continue;
      }
      //if (map[b2.first][b2.second] == -1){
        //cout << "not working" << endl;
      //}
      else {map[x1][y1] = b; visited[x1][y1] = true;}
      int modx[4] = {b2.first + 1, b2.first - 1, b2.first, b2.first};
      int mody[4] = {b2.second, b2.second, b2.second + 1, b2.second - 1};
      for (int i = 0; i < 4; i++){
        if (modx[i] >= 0 && modx[i] <= h && mody[i] >= 0 && mody[i] <= w && !visited[modx[i]][mody[i]]){
          pair<int, int> c2;
          c2.first = modx[i];
          c2.second = mody[i];
          q2.push(c2);
        }
      }
    }*/
  }
}

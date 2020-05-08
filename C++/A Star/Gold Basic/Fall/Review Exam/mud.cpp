#include <iostream>
#include <queue>

using namespace std;

bool map[1001][1001];

struct location{
  int x, y, t;
};

int main(){
  int x, y, n;
  cin >> x >> y >> n;
  int w = max(0, x);
  int h = max(0, y);
  int w2 = min(0, x);
  int h2 = min(0, y);
  for (int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    //cout << a << b << endl;
    map[a+500][b+500] = true;
    w = max(w, a);
    h = max(h, b);
    w2 = min(w2, a);
    h2 = min(h2, b);
  }
  queue<location> q;
  location a;
  a.x = 0;
  a.y = 0;
  a.t = 0;
  map[0][0] = true;
  q.push(a);
  //cout << w << " " << h <<  " " << w2 << " " << h2 << endl;
  w++;
  h++;
  w2--;
  h2--;
  while(!q.empty()){
    //cout << "working" << endl;
    location b = q.front();
    q.pop();
    //cout << b.x << " " << b.y << " " << b.t << endl;
    if (b.x == x && b.y == y){
      cout << b.t;
      return 0;
    }
    int chx[4] = {b.x + 1, b.x - 1, b.x, b.x};
    int chy[4] = {b.y, b.y, b.y + 1, b.y - 1};
    for (int i = 0; i < 4; i++){
      //cout << chx[i] << " " << chy[i] << endl;
      if(chx[i] >= w2 && chy[i] >=  h2 && chx[i] <= w && chy[i] <= h && !map[chx[i] + 500][chy[i] + 500]){
        map[chx[i] + 500][chy[i] + 500] = true;
        location c;
        c.x = chx[i];
        c.y = chy[i];
        c.t = b.t + 1;
        q.push(c);
      }
    }
  }
}

#include <iostream>

using namespace std;

bool room[101][101];
bool visited[101][101];
int switches[20001][4];
int n, m;
int ans = 0;


void recurse(int x, int y){
  //cout << ans << endl;
  //cout << x << " " << y << " " << ans <<endl;
  for (int i = 0; i < m; i++){
    if (switches[i][0] == x+1 && switches[i][1] == y+1){
      if (room[switches[i][2]-1][switches[i][3]-1] == false && visited[switches[i][2]-1][switches[i][3]-1] == false){
        room[switches[i][2]-1][switches[i][3]-1] = true;
        //cout << "++" << switches[i][2]-1 << " " << switches[i][3]-1 << endl;

        //cout << "working";
        if ((switches[i][2] < n && visited[switches[i][2]][switches[i][3]-1] == true) || (switches[i][3] < n && visited[switches[i][2]-1][switches[i][3]] == true)
            || (switches[i][2]-2 >= 0 && visited[switches[i][2]-2][switches[i][3]-1] == true)|| (switches[i][3]-2 >= 0 && visited[switches[i][2]-1][switches[i][3]-2] == true)) {
            //cout << "move" << endl;
            visited[switches[i][2] - 1][switches[i][3] - 1] = true;
            recurse(switches[i][2] - 1, switches[i][3] - 1);
        }
      }
    }
  }
  if (x+1 < n && room[x+1][y] == true && visited[x+1][y] == false){
    visited[x+1][y] = true;
    recurse(x+1, y);
  }
  if (y+1 < n && room[x][y+1] == true && visited[x][y+1] == false){
    visited[x][y+1] = true;
    recurse(x, y+1);
  }
  if (y != 0 && room[x][y-1] == true && visited[x][y-1] == false){
    visited[x][y-1] = true;
    recurse(x, y-1);
  }
  if (x != 0 && room[x-1][y] == true && visited[x-1][y] == false){
    visited[x-1][y] = true;
    recurse(x-1, y);
  }
}

int main(){
  cin >> n;
  cin >> m;
  for (int i = 0; i < m; i++){
    for (int j = 0; j < 4; j++){
      cin >> switches[i][j];
    }
  }
  room[0][0] = true;
  visited[0][0] = true;
  recurse(0, 0);
  for(int i = 0; i < n; i++){
    for (int j = 0; j < n; j++) {
      if (room[i][j] == true) {
        ans++;
      }
    }
  }
  cout << ans;
}
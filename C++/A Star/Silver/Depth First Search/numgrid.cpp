#include <iostream>

using namespace std;

bool room[101][101];
bool visited[101][101];
int switches[20001][5];
int n, m;
int ans = 0;


void recurse(int x, int y){
  cout << ans << endl;
  //cout << x << " " << y << " " << ans <<endl;
  for (int i = 0; i < m; i++){
    if (switches[i][0] == x+1 && switches[i][1] == y+1){
      if (room[switches[i][2]-1][switches[i][3]-1] == false && visited[switches[i][2]-1][switches[i][3]-1] == false){
        room[switches[i][2]-1][switches[i][3]-1] = true;
        ans ++;
        //cout << "++" << switches[i][2]-1 << " " << switches[i][3]-1 << endl;

        //cout << "working";
        if (room[switches[i][2]][switches[i][3]-1] == true || room[switches[i][2]-1][switches[i][3]] == true
            || room[switches[i][2]-2][switches[i][3]-1] == true || room[switches[i][2]-1][switches[i][3]-2] == true){
          //cout << "move" << endl;
          visited[switches[i][2]-1][switches[i][3]-1] = true;
          recurse(switches[i][2]-1, switches[i][3]-1);
        }
      }
    }
  }
  if (room[x+1][y] == true && visited[x+1][y] == false){
    visited[x+1][y] = true;
    recurse(x+1, y);
  }
  if (room[x][y+1] == true && visited[x][y+1] == false){
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
  recurse(0, 0);
  cout << ans+1;
}

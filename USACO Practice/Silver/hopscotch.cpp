#include <iostream>

using namespace std;

int r, c;
char grid[15][15];
char current;
int goal[2];
int ans = 0;

void recurse(int x, int y){
  if (x == goal[0] && y == goal[1]){
    ans ++;
    return;
  }
  for (int i = x+1; i < r; i++){
    for (int j = y+1; j < c; j++){
      if (grid[i][j] != current){
        char a = current;
        current = grid[i][j];
        recurse(i, j);
        current = a;
      }
    }
  }
}

int main(){
  cin >> r >> c;
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      cin >> grid[i][j];
    }
  }
  current = grid[0][0];
  goal[0] = r-1;
  goal[1] = c-1;
  recurse(0, 0);
  cout << ans;
}

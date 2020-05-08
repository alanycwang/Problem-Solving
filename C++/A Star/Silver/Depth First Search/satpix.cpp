#include <iostream>

using namespace std;

int w, h;
char picture[80][1000];
bool visited[80][1000];
int ans = 0;
int length = 0;

void recurse(int x, int y){
  int z = 0;
  if (picture[x+1][y] == '*' && visited[x+1][y] == false){
    visited[x+1][y] = true;
    length++;
    recurse(x+1, y);
  }
  else{
    z++;
  }
  if (picture[x-1][y] == '*' && visited[x-1][y] == false){
    visited[x-1][y] = true;
    length++;
    recurse(x-1, y);
  }
  else{
    z++;
  }
  if (picture[x][y+1] == '*' && visited[x][y+1] == false){
    visited[x][y+1] = true;
    length++;
    recurse(x, y+1);
  }
  else{
    z++;
  }
  if (picture[x][y-1] == '*' && visited[x][y-1] == false){
    visited[x][y-1] = true;
    length++;
    recurse(x, y-1);
  }
  else{
    z++;
  }
  if (z == 4){
    if (length > ans){
      ans = length;
    }
  }
}

int main(){
  cin >> w >> h;
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cin >> picture[j][i];
    }
  }
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      if (picture[j][i] == '*' && visited[j][i] == false){
        recurse(j, i);
        length = 0;
      }
    }
  }
  cout << ans;
}

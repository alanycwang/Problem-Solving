#include <iostream>

using namespace std;

int n;
char horseshoes[5][5];
bool visited[5][5];
char current = '(';
string path;

void recurse(int x, int y){
  visited[x][y] = true;
  if (horseshoes[x-1][y] == current && visited[x-1][y] == false){
    recurse(x-1, y);
  }
  if (horseshoes[x+1][y] == current && visited[x+1][y] == false){
    recurse(x+1, y);
  }
  if (horseshoes[x][y-1] == current && visited[x][y-1] == false){
    recurse(x, y-1);
  }
  if (horseshoes[x][y+1] == current && visited[x][y+1] == false){
    recurse(x, y+1);
  }

  if (horseshoes[x-1][y] != current && visited[x-1][y] == false){
    if (current == '('){
      current = ')';
      recurse(x-1, y);
      current = '(';
    }
  }
  if (horseshoes[x+1][y] != current && visited[x+1][y] == false){
    if (current == '('){
      current = ')';
      recurse(x+1, y);
    }
  }
  if (horseshoes[x][y-1] != current && visited[x][y-1] == false){
    if (current == '('){
      current = ')';
      recurse(x, y-1);
    }
  }
  if (horseshoes[x][y+1] != current && visited[x][y+1] == false){
    if (current == '('){
      current = ')';
      recurse(x, y+1);
    }
  }
}

int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> horseshoes[i][j];
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; i++){
      recurse(i, j);
    }
  }
  cout << path;
}

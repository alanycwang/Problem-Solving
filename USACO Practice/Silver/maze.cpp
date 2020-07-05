#include <iostream>
#include <string>

using namespace std;

int last = 100000;
string path;
string ans;
int s[2];
int f[2];
int n, m;
char maze[100][100];
bool visited[100][100];

void recurse(int x, int y){
  visited[x][y] = true;
  if(x == f[0] && y == f[1]){
    if (path.length() < last){
      last = path.length();
      ans = path;
    }
    return;
  }
  if (maze[x+1][y] == '.' && visited[x+1][y] == false || maze[x+1][y] == 'F' && visited[x+1][y] == false){
    path.push_back('D');
    recurse(x+1, y);
    path.erase(path.length()-1, 1);
  }
  if (maze[x-1][y] == '.'  && visited[x-1][y] == false|| maze[x-1][y] == 'F' && visited[x-1][y] == false){
    path.push_back('U');
    recurse(x-1, y);
    path.erase(path.length()-1, 1);
  }
  if (maze[x][y+1] == '.' && visited[x][y+1] == false || maze[x][y+1] == 'F' && visited[x][y+1] == false){
    path.push_back('R');
    recurse(x, y+1);
    path.erase(path.length()-1, 1);
  }
  if (maze[x][y-1] == '.'  && visited[x][y-1] == false|| maze[x][y-1] == 'F' && visited[x][y-1] == false){
    path.push_back('L');
    recurse(x, y-1);
    path.erase(path.length()-1, 1);
  }
}

string solve(){
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      char x;
      cin >> x;
      maze[i][j] = x;
      if (x == 'S'){
        s[0] = i;
        s[1] = j;
      }
      else if (x == 'F'){
        f[0] = i;
        f[1] = j;
      }
    }
  }
  recurse(s[0], s[1]);
  return ans;
}

int main(){
  cout << solve() << endl;
}

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

void solve(){
  int last = 0;
  int w, h;
  cin >> w >> h;
  char picture[h][w];
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cin >> picture[i][j];
    }
  }
  bool visited[h][w];
  memset(visited, 0, sizeof(visited));
  queue<pair<int, int>> q;
  pair<int, int> a;

  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      if (picture[i][j] == '.' && !visited[i][j]){
        a.first = i;
        a.second = j;
        q.push(a);
        int size = 0;
        while(!q.empty()){
          pair<int, int> b = q.front();
          q.pop();
          size++;
          int movex[8] = {b.first + 1, b.first-1, b.first, b.first, b.first+1, b.first-1, b.first+1, b.first-1};
          int movey[8] = {b.second, b.second, b.second + 1, b.second - 1, b.second+1, b.second+1, b.second-1, b.second-1};
          for (int k = 0; k < 8; k++){
            if (movey[k] >= 0 && movex[k] >= 0 && movey[k] < w && movex[k] < h && !visited[movex[k]][movey[k]] && picture[movex[k]][movey[k]] == '.'){
              visited[movex[k]][movey[k]] = true;
              pair<int, int> c;
              c.first = movex[k];
              c.second = movey[k];
              q.push(c);
            }
          }
        }
        if (size > last){
          last = size;
        }
        /*for (int k = 0; k < h; k++){
          for (int l = 0; l < w; l++){
            cout << visited[k][l] << " ";
          }
          cout << endl;
        }
        cout << endl;*/
      }
    }
  }
  cout << last-1;
}

int main(){
  solve();
}

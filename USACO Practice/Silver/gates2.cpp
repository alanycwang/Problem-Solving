#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

void solve(){
  int ans = 0;
  bool farm[2000][2000];
  int n;
  cin >> n;
  string d;
  cin >> d;
  farm [1000][1000] = true;
  int current_x = 1000;
  int current_y = 1000;
  for (int i = 0; i < n; i++){
    if (d[i] == 'N'){
      current_x+=1;
      farm[current_x][current_y] = true;
      current_x+=1;
      farm[current_x][current_y] = true;
    }
    else if (d[i] == 'S'){
      current_x-=1;
      farm[current_x][current_y] = true;
      current_x-=1;
      farm[current_x][current_y] = true;
    }
    else if (d[i] == 'E'){
      current_y+=1;
      farm[current_x][current_y] = true;
      current_y+=1;
      farm[current_x][current_y] = true;
    }
    else if (d[i] == 'W'){
      current_y-=1;
      farm[current_x][current_y] = true;
      current_y-=1;
      farm[current_x][current_y] = true;
    }
  }
  queue<pair<int, int>> q;
  pair <int, int> a;
  for (int i = 0; i < 2000; i++){
    for (int j = 0; j < 2000; j++){
      if (!farm[i][j]){
        a.first = i;
        a.second = j;
        q.push(a);
        farm[i][j] = true;
        while (!q.empty()){
          pair<int, int> b = q.front();
          q.pop();
          int movex[4] = {b.first + 1, b.first-1, b.first, b.first};
          int movey[4] = {b.second, b.second, b.second + 1, b.second - 1};
          for (int k = 0; k < 4; k++){
            if (movey[k] >= 0 && movex[k] >= 0 && movey[k] < 2000 && movex[k] < 2000 && !farm[movex[k]][movey[k]]){
              farm[movex[k]][movey[k]] = true;
              pair<int, int> c;
              c.first = movex[k];
              c.second = movey[k];
              q.push(c);
            }
          }
        }
        ans ++;
      }
    }
  }
  cout << ans-1;
}

int main(){
  solve();
}

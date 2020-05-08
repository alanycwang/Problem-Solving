#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  int barns[n+1][2];
  int x = 0; int y = 0;
  for (int i = 0; i < n; i++){
    cin >> barns[i][0] >> barns[i][1];
    x = max(barns[i][0], x);
    y = max(barns[i][1], y);
  }
  barns[n][1] = barns[0][1];
  barns[n][0] = barns[0][0];
  x++;
  y++;
  int ans = 0;
  bool visited[x][y];
  for (int i = 0; i < n; i++){
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push(make_pair(barns[i][0], barns[i][1]));
    queue<int> q2;
    q2.push(0);
    visited[barns[i][0]][barns[i][1]] = true;
    while (!q.empty()){
      pair<int, int> a= q.front(); q.pop();
      int b = q2.front(); q2.pop();
      if (a.first == barns[i+1][0] && a.second == barns[i+1][1]){
        ans += b;
        break;
      }
      int chx[4] = {a.first + 1, a.first - 1, a.first, a.first};
      int chy[4] = {a.second, a.second, a.second + 1, a.second - 1};
      for (int j = 0; j < 4; j++){
        if (chx[j] < x && chy[j] < y && chx[j] >= 0 && chy[j] >= 0 && !visited[chx[j]][chy[j]]){
          bool skip = false;
          for (int k = 0; k < n; k++){
            if (chx[j] == barns[j][0] && chy[j] == barns[k][1]){
              skip = true;
              break;
            }
          }
          if (skip){
            continue;
          }
          visited[chx[j]][chy[j]] = true;
          q.push(make_pair(chx[j], chy[j]));
          q2.push(b + 1);
        }
      }
    }
  }
  cout << ans;
}

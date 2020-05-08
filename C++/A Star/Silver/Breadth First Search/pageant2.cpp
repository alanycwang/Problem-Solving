#include <iostream>
#include <queue>
#include <string.h>
#include <cmath>

using namespace std;

void solve(){
  int n, m;
  cin >> n >> m;
  char cow[n][m];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> cow[i][j];
    }
  }
  bool end = false;
  pair<int, int> a;
  queue<pair<int, int>> q;
  char letter = '1';
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (cow[i][j] == 'X'){
        a.first = i;
        a.second = j;
        q.push(a);
        while (!q.empty()){
          pair<int, int> b = q.front();
          q.pop();
          cow[b.first][b.second] = letter;
          int movex[4] = {b.first + 1, b.first-1, b.first, b.first};
          int movey[4] = {b.second, b.second, b.second + 1, b.second - 1};
          for (int k = 0; k < 4; k++){
            if (movey[k] >= 0 && movex[k] >= 0 && movey[k] < m && movex[k] < n && cow[movex[k]][movey[k]] == 'X'){
              pair<int, int> c;
              c.first = movex[k];
              c.second = movey[k];
              q.push(c);
            }
          }
        }
        end = true;
        break;
      }
    }
    if (end){
      break;
    }
  }
  int minimum = 100;
  for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
          if (cow[i][j] == '1'){
              for (int k = 0; k < n; k++){
                  for (int l = 0; l < m; l++){
                      if (cow[k][l] == 'X'){
                          int length = abs(i-k) + abs(j-l);
                          if(length < minimum){
                              minimum = length;
                          }
                      }
                  }
              }
          }
      }
  }
  cout << minimum-1;
}

int main(){
  solve();
}

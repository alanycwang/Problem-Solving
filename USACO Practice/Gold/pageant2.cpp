#include <iostream>
#include <string.h>
#include <queue>
#include <cmath>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  string graph[n];
  for (int i = 0; i < n; i++){
    cin >> graph[i];
  }

  char letter = 'a';
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (graph[i][j] == 'X'){
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        graph[i][j] = letter;
        while(!q.empty()){
          pair<int, int> temp;
          temp = q.front();
          q.pop();
          int newx[4] = {temp.first, temp.first, temp.first + 1, temp.first - 1};
          int newy[4] = {temp.second + 1, temp.second - 1, temp.second, temp.second};
          for (int k = 0; k < 4; k++){
            if (newx[k] >= 0 && newy[k] >= 0 && newx[k] < n && newy[k] < m && graph[newx[k]][newy[k]] == 'X'){
              q.push(make_pair(newx[k], newy[k]));
              graph[newx[k]][newy[k]] = letter;
            }
          }
        }
        letter++;
      }
    }
  }

  int graph2[letter - 'a'][letter - 'a'];
  for (int i = 0; i < letter - 'a'; i++){
    for (int j = 0; j < letter - 'a'; j++){
      graph2[i][j] = 1000000000;
    }
    graph2[i][i] = 0;
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (graph[i][j] != '.'){
        for (int k = 0; k < n; k++){
          for (int l = 0; l < m; l++){
            if (graph[k][l] != '.' && graph[k][l] != graph[i][j]){
              graph2[graph[i][j] - 'a'][graph[k][l] - 'a'] = min(abs(i - k) + abs(j - l) - 1, graph2[graph[i][j] - 'a'][graph[k][l] - 'a']);
            }
          }
        }
      }
    }
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (graph[i][j] == '.'){
        bool vis[3] = {false, false, false};
        int newx[4] = {i, i, i+1, i-1};
        int newy[4] = {j+1, j-1, j, j};
        for (int k = 0; k < 4; k++){
          if (newx[k] >= 0 && newy[k] >= 0 && newx[k] < n && newy[k] < m && graph[newx[k]][newy[k]] != '.'){
            vis[graph[newx[k]][newy[k]] - 'a'] = true;
          }
        }
        bool cont = true;
        for (int k = 0; k < 3; k++){
          if (!vis[k]){
            cont = false;
            break;
          }
        }
        if (cont){
          cout << 1;
          return 0;
        }
      }
    }
  }

/*  for (int i = 0; i < letter - 'a'; i++){
    for (int j = 0; j < letter - 'a'; j++){
      printf("%3d ", graph2[i][j]);
    }
    cout << endl;
  }*/

/*  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cout << graph[i][j];
    }
    cout << endl;
  }*/

  bool visited[letter - 'a'];
  memset(visited, 0, sizeof(visited));
  int dist[letter - 'a'];
  for (int i = 0; i < letter - 'a'; i++){
    dist[i] = 1000000000;
  }
  dist[0] = 0;
  int ans = 0;
  for (int i = 0; i < letter - 'a'; i++){
    int mind = 1000000000;
    int minj = -1;
    for (int j = 0; j < letter - 'a'; j++){
      if (!visited[j] && dist[j] < mind){
        mind = dist[j];
        minj = j;
      }
    }
    visited[minj] = true;
    ans += mind;
    for (int j = 0; j < letter - 'a'; j++){
      dist[j] = min(dist[j], graph2[minj][j]);
    }
  }
  cout << ans;
}

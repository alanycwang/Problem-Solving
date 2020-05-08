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

  queue<pair<pair<int, int>, int>> q2[3];
  bool visited[n][m][3];
  memset(visited, 0, sizeof(visited));
  int dist[n][m];
  memset(dist, 0, sizeof(dist));

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
            if (newx[k] >= 0 && newy[k] >= 0 && newx[k] < n && newy[k] < m){
              if (graph[newx[k]][newy[k]] == 'X'){
                q.push(make_pair(newx[k], newy[k]));
                graph[newx[k]][newy[k]] = letter;
              }
              else if (graph[newx[k]][newy[k]] == '.'){
                q2[letter-'a'].push(make_pair(make_pair(newx[k], newy[k]), 0));
              }
              visited[newx[k]][newy[k]][letter - 'a'] = true;
            }
          }
        }
        letter++;
      }
    }
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      dist[i][j] = 1;
    }
  }

  for (int i = 0; i < 3; i++){
    while (!q2[i].empty()){
      pair<pair<int, int>, int> a = q2[i].front();
      q2[i].pop();
      int newx[4] = {a.first.first, a.first.first, a.first.first + 1, a.first.first - 1};
      int newy[4] = {a.first.second + 1, a.first.second - 1, a.first.second, a.first.second};
      for (int j = 0; j < 4; j++){
        if (newx[j] >= 0 && newy[j] >= 0 && newx[j] < n && newy[j] < m && !visited[newx[j]][newy[j]][i]){
          q2[i].push(make_pair(make_pair(newx[j], newy[j]), a.second + 1));
          dist[newx[j]][newy[j]]+=a.second;
          visited[newx[j]][newy[j]][i] = true;
        }
      }
    }
  }
  int ans = 1000000000;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if(graph[i][j] == '.'){
        ans = min(ans, dist[i][j]);
      }
      //printf("%3d ", dist[i][j]);
    }
    //cout << endl;
  }

/*  int graph2[letter - 'a'][letter - 'a'];
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

  int ans2 = 0;

  bool visited2[letter - 'a'];
  memset(visited2, 0, sizeof(visited2));
  int dist2[letter - 'a'];
  for (int i = 0; i < letter - 'a'; i++){
    dist2[i] = 1000000000;
  }
  dist2[0] = 0;
  for (int i = 0; i < letter - 'a'; i++){
    int mind = 1000000000;
    int minj = -1;
    for (int j = 0; j < letter - 'a'; j++){
      if (!visited2[j] && dist2[j] < mind){
        mind = dist2[j];
        minj = j;
      }
    }
    visited2[minj] = true;
    ans2 += mind;
    for (int j = 0; j < letter - 'a'; j++){
      dist2[j] = min(dist2[j], graph2[minj][j]);
    }
  }*/

  cout << min(ans, ans2);
}

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int main(){
  int w, h;
  cin >> w >> h;
  int graph[h][w];
  pair<int, int> start;
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cin >> graph[i][j];
      if (graph[i][j] == 2){
        start = make_pair(i, j);
      }
    }
  }

  bool visited[h][w];
  bool visited2[h][w];
  memset(visited, 0, sizeof(visited));
  memset(visited2, 0, sizeof(visited2));
  queue<pair<pair<int, int>, int>> q;
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q2;
  visited[start.first][start.second] = true;
  q.push(make_pair(start, 0));
  while(!q.empty()){
    pair<pair<int, int>, int> temp = q.front();
    q.pop();
    if (graph[temp.first.first][temp.first.second] == 4){
      q2.push(make_pair(temp.second, temp.first));
      //cout << temp.first.first << " " << temp.first.second << " " << temp.second << endl;
      visited2[temp.first.first][temp.first.second] = true;
    }
    int chx[4] = {temp.first.first + 1, temp.first.first - 1, temp.first.first, temp.first.first};
    int chy[4] = {temp.first.second, temp.first.second, temp.first.second + 1, temp.first.second - 1};
    for (int i = 0; i < 4; i++){
      if (chx[i] >= 0 && chx[i] < h && chy[i] >= 0 && chy[i] < w && graph[chx[i]][chy[i]] % 4 == 0 && !visited[chx[i]][chy[i]]){
        q.push(make_pair(make_pair(chx[i], chy[i]), temp.second + 1));
        visited[chx[i]][chy[i]] = true;
      }
    }
  }


  while(!q2.empty()){
    pair<int, pair<int, int>> temp = q2.top();
    q2.pop();
    //cout << temp.second.first << " " << temp.second.second << " " << temp.first << endl;
    if (graph[temp.second.first][temp.second.second] == 3){
      cout << temp.first;
      return 0;
    }
    int chx[4] = {temp.second.first + 1, temp.second.first - 1, temp.second.first, temp.second.first};
    int chy[4] = {temp.second.second, temp.second.second, temp.second.second + 1, temp.second.second - 1};
    for (int i = 0; i < 4; i++){
      if (chx[i] >= 0 && chx[i] < h && chy[i] >= 0 && chy[i] < w && graph[chx[i]][chy[i]] % 3 == 0 && !visited2[chx[i]][chy[i]]){
        q2.push(make_pair(temp.first + 1, make_pair(chx[i], chy[i])));
        visited2[chx[i]][chy[i]] = true;
      }
    }
  }
}

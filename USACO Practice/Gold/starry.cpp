#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <string.h>
#include <algorithm>

using namespace std;

int chx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int chy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool helper(pair<int, int> a, pair<int, int> b){
  if(a.first == b.first){
    return a.second < b.second;
  }
  return a.first < b.first;
}

void print_shape(vector<pair<int, int>> a){
  int currenti = 0;
  int currentj = 0;
  for (int k = 0; k < a.size(); k++){
    if (a[k].first != currenti){
      cout << endl;
      currenti++;
      currentj = 0;
      if (a[k].second != 0){
        for (int l = 0; l < a[k].second; l++){
          cout << ".";
          currentj++;
        }
      }
      cout << "*";
      currentj++;
    }
    else if (a[k].second != currentj){
      for (int l = currentj; l < a[k].second; l++){
        cout << ".";
        currentj++;
      }
      cout << "*";
      currentj++;
    }
    else {
      cout << "*";
      currentj++;
    }
  }
  cout << endl << endl;
}

vector<pair<int, int>> transform(vector<pair<int, int>> shape, int rotation, int reflection){
  for (int i = 0; i < shape.size() && rotation > 0; i++){
    if (rotation >= 1){
      int temp = shape[i].first;
      shape[i].first = -shape[i].second;
      shape[i].second = temp;
    }
    if (rotation >= 2){
      int temp = shape[i].first;
      shape[i].first = -shape[i].second;
      shape[i].second = temp;
    }
    if (rotation == 3) {
      int temp = shape[i].first;
      shape[i].first = -shape[i].second;
      shape[i].second = temp;
    }
  }
  if (reflection){
    for (int i = 0; i < shape.size(); i++){
      shape[i].second = -shape[i].second;
    }
  }
  int minx = 1000000000;
  int miny = 1000000000;
  for (int k = 0; k < shape.size(); k++){
    minx = min(minx, shape[k].first);
    miny = min(miny, shape[k].second);
  }
  for (int k = 0; k < shape.size(); k++){
    shape[k].first -= minx;
    shape[k].second -= miny;
  }
  sort(shape.begin(), shape.begin() + shape.size(), helper);
  return shape;
}

bool compare(vector<pair<int, int>> a, vector<pair<int, int>> b){
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 2; j++){
      if (transform(a, i, j) == b){
        return true;
      }
    }
  }
  return false;
}

int main(){
  int n, m;
  cin >> n >> m;
  string graph[n];
  for (int i = 0; i < n; i++){
    cin >> graph[i];
  }
  bool visited[n][m];
  memset(visited, 0, sizeof(visited));
  vector<vector<pair<int, int>>> found;
  int ans = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (graph[i][j] == '*' && !visited[i][j]){
        vector<pair<int, int>> shape;
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        visited[i][j] = true;
        shape.push_back(make_pair(0, 0));
        while(!q.empty()){
          pair<int, int> temp = q.front(); q.pop();
          for (int k = 0; k < 8; k++){
            if(temp.first + chx[k] >= 0 && temp.first + chx[k] < n && temp.second + chy[k] >= 0 && temp.second + chy[k] < m && graph[temp.first + chx[k]][temp.second + chy[k]] == '*' && !visited[temp.first + chx[k]][temp.second + chy[k]]){
              visited[temp.first + chx[k]][temp.second + chy[k]] = true;
              q.push(make_pair(temp.first + chx[k], temp.second + chy[k]));
              shape.push_back(make_pair(temp.first + chx[k]-i, temp.second + chy[k]-j));
            }
          }
        }
        int minx = 1000000000;
        int miny = 1000000000;
        for (int k = 0; k < shape.size(); k++){
          minx = min(minx, shape[k].first);
          miny = min(miny, shape[k].second);
        }
        for (int k = 0; k < shape.size(); k++){
          shape[k].first -= minx;
          shape[k].second -= miny;
        }
        sort(shape.begin(), shape.begin() + shape.size(), helper);
        bool same = false;
        for (int k = 0; k < found.size(); k++){
          if (compare(found[k], shape)){
            same = true;
            break;
          }
        }
        if (!same){
          found.push_back(shape);
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}

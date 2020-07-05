#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>

using namespace std;

int main(){
  int n;
  cin >> n;
  set<int> temp;
  vector<vector<int>> islands;
  vector<int> temp2;
  for (int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if(temp.find(a) != temp.end()){
      temp.erase(a);
      temp2.push_back(a);
    }
    else{
      temp.insert(a);
    }
    if(temp.find(b) != temp.end()){
      temp.erase(b);
      temp2.push_back(b);
    }
    else{
      temp.insert(b);
    }
    if (temp.empty()){
      islands.push_back(temp2);
      temp2.erase(temp2.begin(), temp2.end());
    }
  }
  int graph[n][n];
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> graph[i][j];
    }
  }
/*for (auto i : islands){
    for (auto j : i){
      cout << j << " ";
    }
    cout << endl;
  }*/

  int graph2[islands.size()][islands.size()];
  for (int i = 0; i < islands.size(); i++){
    graph2[i][i] = 0;
    for (int j = i+1; j < islands.size(); j++){
      int dist = 1000000000;
      for (int k = 0; k < islands[i].size(); k++){
        for (int l = 0; l < islands[j].size(); l++){
          dist = min(dist, graph[islands[i][k]][islands[j][l]]);
        }
      }
      graph2[i][j] = dist;
      graph2[j][i] = dist;
    }
  }
/*  for (int i = 0; i < islands.size(); i++){
    for (int j = 0; j < islands.size(); j++){
      printf("%3d ", graph2[i][j]);
    }
    printf("\n");
  }*/
  int ans = 1000000000;
  for (int i = 0; i < islands.size(); i++){
    int sum = 0;
    for (int j = 0; j < islands.size(); j++){
      if (i != j){
        //cout << i << " " << j << endl;
        sum += graph2[i][j] * 2;
      }
    }
    //cout << sum << endl;
    ans = min(ans, sum);
  }
  cout << ans;
}

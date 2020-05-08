#include <iostream>
#include <set>
#include <queue>

using namespace std;

bool visited[20000];

int main(){
  int n, m;
  cin >> n >> m;
  set<int> paths[n];
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    paths[a-1].insert(b-1);
    paths[b-1].insert(a-1);
  }
  visited[0] = true;
  queue<pair<int, int>> q;
  int ans;
  int ans2 = 0;
  int ans3 = 0;
  pair<int, int> a;
  a.first = 0;
  a.second = 0;
  visited[0] = true;
  q.push(a);
  while (!q.empty()){
    pair<int, int> b = q.front();
    /*cout << b.first << " " << b.second << endl;
    cout << ans << " " << ans2 << " " << ans3 << endl;*/
    q.pop();
    if (ans2 < b.second){
      ans = b.first;
      ans2 = b.second;
      ans3 = 1;
    }
    if (ans2 == b.second){
      ans = min(ans, b.first);
      ans3++;
    }
    for (auto i : paths[b.first]){
      if (!visited[i]){
        visited[i] = true;
        pair<int, int> c;
        c.first = i;
        c.second = b.second + 1;
        q.push(c);
      }
    }
  }
  cout << ans + 1 << " " << ans2 << " " << ans3 - 1;
}

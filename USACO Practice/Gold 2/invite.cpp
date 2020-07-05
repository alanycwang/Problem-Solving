#include <iostream>
#include <set>
#include <queue>

using namespace std;

bool visited[1000000];

int main(){
  int n, g;
  cin >> n >> g;
  set<int> groups[g];
  for (int i = 0; i < g; i++){
    int s;
    cin >> s;
    for (int j = 0; j < s; j++){
      int a;
      cin >> a;
      groups[i].insert(a);
    }
  }
  queue<int> q;
  q.push(1);
  int ans = 1;
  while (!q.empty()){
    int a = q.front();
    q.pop();
    for (int i = 0; i < g; i++){
      groups[i].erase(a);
      if (groups[i].size() == 1){
        set<int>::iterator b;
        b = groups[i].begin();
        if (!visited[*b]){
          visited[*b] = true;
          ans ++;
          cout << *b << endl;
          q.push(*b);
        }
      }
    }
  }
  cout << ans;
  return 0;
}

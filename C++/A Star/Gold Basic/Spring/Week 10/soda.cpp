#include <iostream>
#include <queue>

using namespace std;

int main(){
  int n;
  cin >> n;
  priority_queue<pair<int, int>> pq;
  for (int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    pq.push(make_pair(a, -1));
    pq.push(make_pair(b, 1));
  }
  int a = 0;
  int ans = 0;
  for (int i = 0; i < 2*n; i++){
    a += pq.top().second;
    //cout << a << endl;
    pq.pop();
    ans = max(ans, a);
  }
  cout << ans;
}

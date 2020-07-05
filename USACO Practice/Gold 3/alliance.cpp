#include <iostream>
#include <set>

using namespace std;

long long n, m, count, count2;
multiset<long long> paths[100000];
bool visited[100000];
long long ans = 1;

void dfs(long long node) {
  if (visited[node]) return;
  visited[node] = true;
  count++;

  for (auto i : paths[node]) {
    count2++;
    dfs(i);
  }
}

int main() {
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long a, b;
    cin >> a >> b;
    paths[a - 1].insert(b - 1);
    paths[b - 1].insert(a - 1);
  }

  //cout << endl;

  for (long long i = 0; i < n; i++) {
    if (!visited[i]) {
      count = 0;
      count2 = 0;
      dfs(i);
      count2 /= 2;
      if (count == count2) ans = (ans*2)%1000000007;
      else ans = (ans*count)%1000000007;
      //cout << count << " " << count2 << endl;
    }
  }

  cout << ans;
}

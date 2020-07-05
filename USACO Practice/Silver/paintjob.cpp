#include <iostream>
#include <queue>

using namespace std;

bool visited[10000];

struct paint{
  int color;
  int combinations;
};

int main(){
  int a, b, n, p;
  cin >> a >> b;
  cin >> n >> p;
  int buckets[n];
  for (int i = 0; i < n; i++){
    cin >> buckets[i];
  }
  queue<paint> q;
  paint c;
  c.color = a;
  c.combinations = 0;
  q.push(c);
  while(!q.empty()){
    paint d = q.front();
    q.pop();
    if (d.color == b){
      cout << d.combinations;
      return 0;
    }
    for(int i = 0; i < n; i++){
      if (!visited[(d.color*buckets[i])%p]){
        paint e;
        visited[(d.color*buckets[i])%p] = true;
        e.color = (d.color*buckets[i])%p;
        e.combinations = d.combinations+1;
        q.push(e);
      }
    }
  }
  cout << -1;
}

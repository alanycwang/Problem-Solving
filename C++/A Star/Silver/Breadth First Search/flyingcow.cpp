#include <iostream>
#include <queue>

using namespace std;

bool visited[1000001];

struct location{
  int distance;
  int number;
};

int main(){
  int n;
  cin >> n;
  queue<location> q;
  location a;
  a.distance = 0;
  a.number = 1;
  q.push(a);
  while (!q.empty()){
    location next = q.front();
    q.pop();
    if (next.number == n){
      cout << next.distance;
      break;
    }
    if (next.number*3 > 0 && next.number*3 < 1000001 && !visited[next.number*3]){
      location x;
      x.distance = next.distance+1;
      x.number = next.number*3;
      visited[next.number*3] = true;
      q.push(x);
    }
    if (next.number+1 > 0 && next.number+1 < 1000001 && !visited[next.number+1]){
      location x;
      x.distance = next.distance+1;
      x.number = next.number+1;
      visited[next.number+1] = true;
      q.push(x);
    }
    if (next.number-1 > 0 && next.number-1 < 1000001 && !visited[next.number-1]){
      location x;
      x.distance = next.distance+1;
      x.number = next.number-1;
      visited[next.number-1] = true;
      q.push(x);
    }
  }
}

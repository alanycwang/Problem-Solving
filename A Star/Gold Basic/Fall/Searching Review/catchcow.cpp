#include <iostream>
#include <queue>

using namespace std;

bool visited[100001];

struct fj{
  int location;
  int minutes;
};

int main(){
  int n, k;
  cin >> n >> k;
  visited[n] = true;
  queue<fj> q;
  fj a;
  a.location = n;
  a.minutes = 0;
  q.push(a);

  while(!q.empty()){
    fj x = q.front();
    if (x.location == k){
      cout << x.minutes;
      break;
    }
    //cout << x.location << " " << x.minutes << endl;
    q.pop();
    fj b;
    b.minutes = x.minutes + 1;
    if (x.location * 2 <= 100000 && x.location != 0 && !visited[x.location*2]){
      b.location = x.location*2;
      visited[x.location*2] = true;
      q.push(b);
    }
    if (x.location < 100000 && !visited[x.location + 1]){
      b.location = x.location + 1;
      visited[x.location + 1] = true;
      q.push(b);
    }
    if (x.location > 0 && !visited[x.location - 1]){
      b.location = x.location - 1;
      visited[x.location - 1] = true;
      q.push(b);
    }
  }
}

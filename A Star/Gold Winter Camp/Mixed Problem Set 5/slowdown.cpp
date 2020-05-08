#include <iostream>
#include <string.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  pair<char, double> op[n];
  for (int i = 0; i < n; i++){
    cin >> op[i].first >> op[i].second;
  }

  double dist = 0;
  double spd = 1;
  double t = 0;
  bool visited[n];
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < n; i++){
    int nxt = -1;
    double mind = -1;
    for (int j = 0; j < n; j++){
      if (!visited[j] && op[j].first == 'T' && (mind == -1 || dist + (op[j].second - t) / spd < mind)){
        mind = dist + (op[j].second - t) / spd;
        nxt = j;
      }
      else if (!visited[j] && op[j].first == 'D' && (mind == -1 || op[j].second < mind)){
        mind = op[j].second;
        nxt = j;
      }
    }
    visited[nxt] = true;
    //cout << nxt << endl;
    if (op[nxt].first == 'T'){
      dist += (op[nxt].second - t) / spd;
      t = op[nxt].second;
      spd++;
    }
    else{
      t += (op[nxt].second - dist) * spd;
      dist = op[nxt].second;
      spd++;
    }
    //cout << dist << " " << t << " " << spd << " " << nxt << endl;
  }
  cout << int(t + (1000 - dist)*spd + 0.5);
}

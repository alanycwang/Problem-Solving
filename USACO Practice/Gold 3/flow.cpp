#include <iostream>
#include <string.h>

using namespace std;

int edges[52][52];

int main() {
  int n;
  cin >> n;
  int count = 0;
  for (int i = 0; i < n; i++) {
    char a, b;
    int c;
    cin >> a >> b >> c;
    if (a > 'Z') a = 26 + a - 'a';
    else a = a - 'A';
    if (b > 'Z') b = 26 + b - 'a';
    else b = b - 'A';
    if (edges[a][b] == 0) count+=2;
    edges[a][b] += c;
    edges[b][a] += c;
    //cout << edges[a][b] << endl;
  }
  while (count > 2) {
    //cout << count << endl;
    for (int i = 1; i < 52; i++) {
      if (i == 25) continue;
      int a = -1;
      int b = -1;
      int cnt = 0;
      for (int j = 0; j < 52; j++) {
        if (edges[i][j]) {
          if (a == -1) a = j;
          else b = j;
          cnt++;
        }
        if (cnt > 2) goto skip;
      }
      //cout << i << " " << a << " " << b << endl;
      if (a == -1) continue;
      if (b == -1) {
        edges[i][a] = 0;
        edges[a][i] = 0;
        count -=2;
        continue;
      }
      if (edges[a][b] == 0) count-=2;
      else count-=4;
      edges[a][b] += min(edges[i][a], edges[i][b]);
      edges[b][a] = edges[a][b];
      edges[i][a] = 0;
      edges[i][b] = 0;
      edges[a][i] = 0;
      edges[b][i] = 0;
      skip:
      continue;
    }
  }
  //cout << edges[1][25] << endl;
  cout << edges[0][25];
}

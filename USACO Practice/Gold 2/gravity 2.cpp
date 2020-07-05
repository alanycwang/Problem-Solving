#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct vertex {int x, y;};
struct edge {int s, e, c;};

class Graph {
public:
  Graph(int n_, int m_) {
    m = m_;
    n = n_;
    map = new string[n];
  }
  ~Graph() {
    delete [] map;
  }
  void SetRow(int i, const string& row) {
    map[i] = row;
  }
  char GetCell(int x, int y) {
    if (x < 0 || x > n || y < 0 || y > m)
      return ' ';
    return map[x][y];
  }
  int Index(x, y) {
    return x * m + y;
  }
  void DetectEdge(int x, int y) {
    char cell = GetCell(x, y);

  }
  void BuildGraph() {
    // Add every cell as a node in the V
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        v.push_back({i, j});
      }
    }

    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
          DetectEdge(i, j);
      }
    }
  }
public:
  int m;
  int n;
  string *map;
  vector<vertex> v;
  vector<edge> e;
  int start;
  int end;
}

int main(){
  int n, m;
  cin >> n >> m;
  Graph g = new Graph(n, m);
  string row;
  for (int i = 0; i < n; i++){
      cin >> row;
      g.SetRow(i, row);
  }
/*  cout << n << " " << m << endl;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cout << map[i][j];
    }
    cout << endl;
  }*/

}

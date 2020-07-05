#include <iostream>
#include <set>

using namespace std;

int main(){
  int n;
  cin >> n;
  int points[n][2];
  for (int i = 0; i < n; i++){
    cin >> points[i][0] >> points[i][1];
  }
  int x = 0;
  bool y = false;
  set<double> slopes;
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      bool next = false;
      if (points[i][1] - points[j][1] == 0){
        if (!y){
          x++;
          y = true;
        }
        continue;
      }
      double slope = double(points[i][0] - points[j][0])/(points[i][1] - points[j][1]);
      //cout << i << " " << j << " " << slope << endl;
      slopes.insert(slope);
    }
  }
  cout << slopes.size() + x;
}

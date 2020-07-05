#include <iostream>

using namespace std;

int points = 0;;
int last = 0;
int r;
int nodes[600];

void recurse(int row, int x){
  cout << row << " " << x << endl;
  if (row == r){
    points += nodes[x];
    if (points > last){
      last = points;
    }
    points-= nodes[x];

    return;
  }
  points += nodes[x];
  recurse(row+1, x+row);
  recurse(row+1, x+row+1);
  points -= nodes[x];
}

int main(){
  cin >> r;
  int x = 1;
  for (int i = 0; i < r; i++){
    for (int j = r-1-i; j < r; j++){
      cin >> nodes[x];
      x++;
    }
  }
  recurse(1, 1);
  cout << last;
}

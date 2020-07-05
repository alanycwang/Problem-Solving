#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  int instructions[n];
  for (int i = 0; i < n; i++){
    instructions[i] = 0;
  }
  for (int i = 0; i < k; i++){
    int x, y;
    cin >> x >> y;
    instructions[x-1]++;
    instructions[y]--;
  }
  int x = 0;
  int stacks[n];
  for (int i = 0; i < n; i++){
    stacks[i] = 0;
    x += instructions[i];
    stacks[i] += x;
  }
  sort(stacks, stacks+n);
  int median = n/2;
  cout << stacks[median];
}

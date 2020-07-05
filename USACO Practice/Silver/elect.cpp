#include <iostream>
#include <algorithm>

using namespace std;

struct cow{
  int voters1;
  int voters2;
  int index;
};

bool comp (cow a, cow b) {
  return a.voters1 > b.voters1;
}
bool comp2 (cow a, cow b) {
  return a.voters2 > b.voters2;
}

int main(){
  int n, k;
  cin >> n >> k;
  cow cows[n];
  for (int i = 0; i < n; i++){
    int r1, r2;
    cin >> r1 >> r2;
    cows[i].index = i+1;
    cows[i].voters1 = r1;
    cows[i].voters2 = r2;
  }
  sort(cows, cows+n, comp);
  cow cows2[k];
  for (int i = 0; i < k; i++){
    cows2[i].index = cows[i].index;
    cows2[i].voters2 = cows[i].voters2;
  }
  sort(cows2, cows2+k, comp2);
  cout << cows2[0].index;
}

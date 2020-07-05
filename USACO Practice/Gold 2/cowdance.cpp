#include <iostream>
#include <algorithm>

using namespace std;

int n, t;
int times[10000];
int m = 1000000;
bool test(int k){
  m = 1000000;
  int x = 0;
  int stages[k];
  for (int i = 0; i < k; i++){
    stages[i] = times[x];
    //cout << stages[i] << endl;
    m = min(m, stages[i]);
    //cout << m;
    x++;
  }
  //cout << m;
  int length = 0;
  while (x < n){
    length += m;
    int l = m;
    m = 1000000;
    for (int i = 0; i < k; i++){
      stages[i] -= l;
      if (stages[i] == 0){
        stages[i] = times[x];
        x++;
      }
      m = min(m, stages[i]);
    }
    /*for (int i = 0; i < k; i++){
      cout << stages[i] << " ";
    }
    cout << x << endl;*/
  }
  int a = 0;
  for (int i = 0; i < k; i++){
    a = max(a, stages[i]);
  }
  length += a;
  //cout << length;
  return (length <= t);
}

int main(){
  cin >> n >> t;
  for (int i = 0; i < n; i++){
    cin >> times[i];
  }
  int high = n;
  int low = 1;
  int mid;
  while (low < high){
    mid = (low + high + 1)/2;
    if (!test(mid)){
      low = mid;
    }
    else{
      high = mid - 1;
    }
  }
  cout << low + 1;
}

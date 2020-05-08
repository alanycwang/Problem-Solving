#include <bits/stdc++.h>

using namespace std;

int cows[100001];

void merge(int cow1, int cow2){
  cows[cow2] = cows[cow1];
}

int main(){
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++){
    cows[i] = i;
  }
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    merge(a-1, b-1);
  }

  for (int i = 0; i < n; i++){
    cout << cows[i] << endl;
  }
}

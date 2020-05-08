#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

pair<int, int> cows[50000];
int f1[50000];
int n;

bool helper(pair<int, int> a, pair<int, int> b){
  return (a.second < b.second);
}

int f(int x){
  if (f1[x] != -1){
    //cout << x << endl;
    return f1[x];
  }
  //cout << endl;
  int a = -1;
  for (int i = n-1; i >=0; i--){
    //cout << i << " ";
    if (cows[i].second <= cows[x].first){
      //cout << "working" << endl;
      a = i;
      break;
    }
  }
  int b = f(x-1);
  if (a > -1){
    b = max(b, f(a) + 1);
  }
  f1[x] = b;
  //cout << x << " " << b << " " << cows[x].first << " " << cows[x].second << endl;
  //cout << b << endl;
  return b;
}

int main(){
  memset(f1, -1, sizeof(f1));
  f1[0] = 1;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> cows[i].first >> cows[i].second;
  }
  sort(cows, cows+n, helper);
/*  for (int i = 0; i < n; i++){
    cout << cows[i].first << " " << cows[i].second << endl;
  }*/
  int ans = 0;
  for (int i = 0; i < n; i++){
    ans = max(ans, f(i));
    //cout << endl;
  }
  cout << ans;

}

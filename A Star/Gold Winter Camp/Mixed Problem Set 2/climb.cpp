#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cows[25000][2];

bool helper (int a, int b){
  return cows[a][0] < cows[b][0];
}

bool helper2 (int a, int b){
  return cows[a][1] > cows[b][1];
}

int main(){
  int n; cin >> n;
  vector<int> s;
  vector<int> l;
  for (int i = 0; i < n; i++){
    cin >> cows[i][0] >> cows[i][1];
    if (cows[i][0] < cows[i][1]){
      s.push_back(i);
    }
    else {
      l.push_back(i);
    }
  }
  sort(s.begin(), s.begin() + s.size(), helper);
  sort(l.begin(), l.begin() + l.size(), helper2);
  for (int i = 0; i < l.size(); i++){
    s.push_back(l[i]);
  }
  vector<int> times;
  int t = 0;
  for (int i = 0; i < n; i++){
    t += cows[s[i]][0];
    times.push_back(t);
  }
  t = times[0];
  for (int i = 1; i < n; i++){
    t = max(times[i], t + cows[s[i-1]][1]);
  }
  t += cows[s[n-1]][1];
  cout << t << endl;
}

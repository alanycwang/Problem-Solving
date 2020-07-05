#include <iostream>
#include <vector>

using namespace std;

void solve(){
  int f, m, n;
  cin >> f >> m >> n;
  int force[n];
  int mass[n];
  vector<int> parts;
  vector<int> ans;
  for (int i = 0; i < n; i++){
    cin >> force[i] >> mass[i];
  }

  float max = float(f)/m;

  for (int i = 0; i < (1 << n); i++){
    int sum = 0;
    int sum2 = 0;
    for (int j = 0; j < n; j++){
      int tmp = i >> j;
      if (tmp & 1){
        sum += force[j];
        sum2 += mass[j];
        parts.push_back(j+1);
      }
    }
    if (float(sum + f)/(sum2 + m) > max){
      max = float(sum + f)/(sum2+m);
      ans.clear();
      //cout << max << endl;
      for (auto x : parts){
        ans.push_back(x);
        //cout << x << endl;;
      }
    //  cout << endl;
    }
    parts.clear();
  }
  if (ans.size() == 0){
    cout << "NONE";
  }
  else{
    for (auto x : ans){
      cout << x << endl;
    }
  }
}

int main(){
  solve();
}

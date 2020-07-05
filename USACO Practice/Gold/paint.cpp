#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector<pair<int, bool>> points;
  int loc = 0;
  for (int i = 0; i < n; i++){
    int a; char b;
    cin >> a >> b;
    if (b == 'R'){
      points.push_back(make_pair(loc, true));
      loc += a;
      points.push_back(make_pair(loc, false));
    }
    else{
      points.push_back(make_pair(loc, false));
      loc -= a;
      points.push_back(make_pair(loc, true));
    }
  }
  sort(points.begin(), points.begin() + points.size());
  int ans = 0;
  int modifier = 0;
  for (int i = 1; i < 2 * n; i++){
    if(points[i-1].second){
      modifier++;
    }
    else{
      modifier--;
    }
    if (modifier >= k){
      ans += points[i].first - points[i-1].first;
    }
  }
  cout << ans;
}

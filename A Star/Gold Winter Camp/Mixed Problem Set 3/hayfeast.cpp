#include <iostream>
#include <vector>

using namespace std;

long long n, m;
pair<long long, long long> bales[100000];

bool valid (long long s){
  vector<pair<long long, long long>> temp;
  for (long long i = 0; i < n; i++){
    if (bales[i].second <= s){temp.push_back(make_pair(bales[i].first, bales[i].second));}
    else{
      long long sum = 0;
      //cout << temp.size() << endl;
      for (long long j = 0; j < temp.size(); j++){
        sum += temp[j].first;
      }
      if (sum >= m) return true;
      else temp.erase(temp.begin(), temp.end());
    }
  }
  long long sum = 0;
  for (long long j = 0; j < temp.size(); j++){
    sum += temp[j].first;
  }
  if (sum >= m) return true;
  return false;
}

int main(){
  cin >> n >> m;
  long long high = 0;
  for (long long i = 0; i < n; i++){
    cin >> bales[i].first >> bales[i].second;
    high = max(high, bales[i].second);
  }
  long long low = 0;
  long long mid;
  while (high > low){
    mid = int((high + low)/2);
    //cout << mid << endl;
    if (valid(mid)){
      high = mid;
    }
    else {
      low = mid + 1;
    }
    //cout << endl << endl << endl;
  }
  cout << low;
}

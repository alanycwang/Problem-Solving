#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int numbers[100000];
bool a = false;

void recurse(vector<int> b){
  if (b.size() == n){
    a = true;
    for (int i = 0; i < n; i++){
      int c = i+1;
      int d = i-1;
      if (d < 0){
        d = b.size()-1;
      }
      if (c > b.size()-1){
        c = 0;
      }
      if (b[i] >= b[c] + b[d]){
        a = false;
        break;
      }
    }
    return;
  }
  vector<int> c;
  for (auto i : b){
    c.push_back(i);
  }
  for(int i = 0; i < n; i++){
    if (find(b.begin(), b.end(), numbers[i]) == b.end()){
      c.push_back(numbers[i]);
      recurse(c);
      if (a){
        return;
      }
      c.erase(c.begin() + c.size());
    }
  }
}

int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> numbers[i];
  }
  if (a){
    cout << "YES";
  }
  else{
    cout << "NO";
  }
}

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin >> n;
  stack<int> stack;
  int x = 1;
  int y = 0;
  for (int i = 0; i < n; i++){
    string a;
    cin >> a;
    if (a == "ADD"){
      stack.push(x);
      x++;
      y++;
    }
    else if (a == "REMOVE"){
      stack.pop();
      y--;
    }
  }
  cout << y << endl;
  int ans[y];
  for (int i = 0; i < y; i++){
    ans[i] = stack.top();
    stack.pop();
  }
  sort(ans, ans+y);
  for (const auto& i : ans){
    cout << i << endl;
  }
}

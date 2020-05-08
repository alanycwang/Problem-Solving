#include <iostream>
#include <stack>
#include <set>
#include <map>
#include <string.h>

using namespace std;

void print_stack(stack<int> s){
  stack<int> a = s;
  while(!a.empty()){
    cout << a.top() << " ";
    a.pop();
  }
  cout << endl;
}

int main(){
  int n; cin >> n;
  pair<char, int> op[n];
  set<int> m;
  map<int, stack<int>> h;
  for (int i = 0; i < n; i++){
    cin >> op[i].first;
    if (op[i].first != 's'){
      cin >> op[i].second;
      if (op[i].first == 't'){
        m.insert(op[i].second);
      }
    }
  }
  stack<int> current;
  h[0] = current;
  for (int t = 0; t < n; t++){
    if(op[t].first == 'a'){
      current.push(op[t].second);
    }
    else if(op[t].first == 's'){
      current.pop();
    }
    else if(op[t].first == 't'){
      current = h.find(op[t].second-1)->second;
    }
    if(m.find(t+2) != m.end()){
      h[t+1] = current;
      //cout << "saved" << " " << t << endl;
    }
    if(current.empty()){
      cout << -1 << endl;
    }
    else{
      cout << current.top() << endl;
    }
    //print_stack(current);
  }


}

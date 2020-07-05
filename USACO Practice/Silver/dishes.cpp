#include <iostream>
#include <stack>

using namespace std;

int main(){
  int ndishes;
  cin >> ndishes;
  stack<int> dishes;
  stack<int> washed;
  stack<int> dried;
  for (int i = 0; i < ndishes; i++){
    dishes.push(ndishes-i);
  }
  while(true){
    if(cin.eof()){
      break;
    }
    int x, y;
    cin >> x >> y;
    if (x == 1){
      for (int i = 0; i < y; i++){
        washed.push(dishes.top());
        dishes.pop();
      }
    }
    else if (x == 2){
      for (int i = 0; i < y; i++){
        dried.push(washed.top());
        washed.pop();
      }
    }
  }
  for (int i = 0; i < ndishes; i++){
    cout << dried.top() << endl;
    dried.pop();
  }
}

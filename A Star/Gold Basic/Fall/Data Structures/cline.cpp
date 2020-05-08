#include <iostream>
#include <deque>

using namespace std;

int main(){
  int n;
  cin >> n;
  deque<int> cows;
  int x = 1;
  int size = 0;
  for (int i = 0; i < n; i++){
    char e[2];
    int f;
    cin >> e[0] >> e[1];
    if (e[0] == 'A'){
      if (e[1] == 'L'){
        cows.push_front(x);
        x++;
      }
      else if (e[1] == 'R'){
        cows.push_back(x);
        x++;
      }
    }
    else if(e[0] == 'D'){
      cin >> f;
      if (e[1] == 'L'){
        for (int j = 0; j < f; j++){
          cows.pop_front();
        }
      }
      else if (e[1] == 'R'){
        for (int j = 0; j < f; j++){
          cows.pop_back();
        }
      }
    }
    //cout << cows << endl;
  }
  int c = cows.size();
  for (int i = 0; i < c; i++){
    cout << cows.front() << endl;
    cows.pop_front();
  }
}

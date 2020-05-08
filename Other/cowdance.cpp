#include <iostream>
#include <string.h>

using namespace std;

int main(){
  freopen("cowdance.in", "r", stdin);
  freopen("cowdance.out", "w", stdout);
  int n, t;
  cin >> n >> t;
  int lengths[n];
  for (int i = 0; i < n; i++){
    cin >> lengths[i];
  }
  for (int i = 1; i < n+1; i++){
    int count = 0;
    int current[i];
    memset(current, 0, sizeof(current));
    for (int j = 0; j < t; j++){
      for (int k = 0; k < i; k++){
        current[k]--;
        if (current[k] <= 0 && current[k] < n){
          current[k] = lengths[count];
          count++;
          /*cout << i << endl;
          cout << count << lengths[count] << endl;
          for (int j = 0; j < i; j++){
            cout << current[j] << " ";
          }
          cout << endl << endl;*/
        }
      }
    }
    bool working = true;
    for (int j = 0; j < i; j++){
      if (current[j] > 0){
        working = false;
        break;
      }
    }
    if (working){
      cout << i;
      break;
    }
  }
}

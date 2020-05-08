#include <iostream>

using namespace std;

int main(){
  int n, m, q;
  cin >> n >> m >> q;
  int p[m];
  for (int i = 0; i < m; i++){
    cin >> p[i];
  }
  int p2[m];
  for (int i = 0; i < m; i++){
    p2[p[i]-1] = i+1;
  }
  for (int i = 0; i < q; i++){
    int temp;
    cin >> temp;
    int loc = 1;
    int total = temp;
    while(total <= n){
      if (loc > m){
        loc += n-total;
        break;
      }
      if (total < m){
        loc++;
        total++;
      }
      else {
        loc = p2[loc-1];
        if (total < n){
          loc++;
        }
        total++;
      }
    }
    cout << loc << endl;
  }
}

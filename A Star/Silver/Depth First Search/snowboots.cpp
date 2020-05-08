#include <iostream>

using namespace std;

int n, b;
int depths[250];
int boots[250][2];
int ans = 99999999;
bool visited[250][250];


void dfs(int boot, int pos){
    if (pos >= n-1){
        if (boot < ans){
          ans = boot;
        }
        return;
    }
    if (depths[pos] <= boots[boot][0]){
      for (int i = 0; i < boots[boot][1]; i++){
         if (depths[pos+i+1] <= boots[boot][0]){
            if (!visited[boot][pos+i+1]){
              visited[boot][pos+i+1] = true;
              dfs(boot, pos+i+1);
            }
        }
    }
  }
   if (boot != b-1){
     if (!visited[boot+1][pos]){
       visited[boot+1][pos] = true;
       dfs(boot+1, pos);
     }
   }
}
int main(){
    cin >> n >> b;
    for (int i = 0; i < n; i++){
        cin >> depths[i];
    }
    for (int i = 0; i < b; i++){
        cin >> boots[i][0] >> boots[i][1];
    }
    dfs(0, 0);
    cout << ans;
}

#include <iostream>
#include <algorithm>

using namespace std;

bool helper(int a[2], int b[2]){
  return a[1] < b[1];
}

int main(){
  int n, q;
  cin >> n >> q;
  int graph[n][n];
  for (int i = 0; i < n-1; i++){
    int a, b, c;
    graph[a-1][b-1] = c;
    graph[b-1][a-1] = c;
  }
  int questions[q][2];
  for (int i = 0; i < q; i++){
    cin >> questions[i][0] >> questions[i][1];
  }
  sort(questions, questions + n, helper);
  int tree[n][2];
  for (int i = 0; i < q; i++){
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        if (j != k && graph[j][k] < questions[i][1]){

        }
      }
    }
  }
}

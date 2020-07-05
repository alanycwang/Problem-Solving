#include <iostream>

using namespace std;

int INF = 1000000000;

int main(){
  int p, f, c;
  cin >> p >> f >> c;
  int favorite[f];
  int edges[p][p];
  for (int i = 0; i < f; i++){
    cin >> favorite[i];
    favorite[i]--;
  }

  for (int i = 0; i < p; i++){
    for (int j = 0; j < p; j++){
      edges[i][j] = INF;
    }
  }

  for (int i = 0; i < c; i++){
    int a, b, d;
    cin >> a >> b >> d;
    edges[a-1][b-1] = min(edges[a-1][b-1], d);
    edges[b-1][a-1] = min(edges[b-1][a-1], d);
  }

  for (int k = 0; k < p; k++){
    for (int i = 0; i < p; i++){
      for (int j = 0; j < p; j++){
        edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);
      }
    }
  }

  for (int i = 0; i < p; i++){
    edges[i][i] = 0;
  }
/*  for (int i = 0; i < p; i++){
    for (int j = 0; j < p; j++){
      cout << edges[i][j] << " ";
    }
    cout << endl;
  }*/
  int ans;
  float avg = INF;
  for (int i = 0; i < p; i++){
    float x = 0;
    for (int j = 0; j < f; j++){
      x += edges[i][favorite[j]];
      //cout << edges[i][favorite[j]] << " " ;
    }
    if (avg > x){
      ans = i;
      avg = x;
    }
    //cout << x << " " << i << endl << endl;
  }
  cout << ans + 1;
}

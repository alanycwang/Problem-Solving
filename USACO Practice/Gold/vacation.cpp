#include <iostream>
#include <string.h>

using namespace std;

int main(){
  long long n, m, z, q;
  cin >> n >> m >> z >> q;
  long long graph[n][n];
  for (long long i = 0; i < n; i++){
    for (long long j = 0; j < n; j++){
      graph[i][j] = 1000000000;
    }
    graph[i][i] = 0;
  }
  for (long long i = 0; i < m; i++){
    long long a, b, c;
    cin >> a >> b >> c;
    graph[a-1][b-1] = c;
  }

  long long dist[n][z];
  for (long long i = 0; i < n; i++){
    for (long long j = 0; j < z; j++){
      dist[i][j] = 1000000000;
    }
  }
  for (long long i = 0; i < z; i++){
    dist[i][i] = 0;
    bool visited[n];
    memset(visited, 0, sizeof(visited));
    for (long long j = 0; j < n; j++){
      long long mink = -1;
      for (long long k = 0; k < n; k++){
        if (!visited[k] && (mink == -1 || dist[k][i] < dist[mink][i])){
          mink = k;
        }
      }
      if (mink != -1){
        visited[mink] = true;
        for (long long k = 0; k < n; k++){
          dist[k][i] = min(dist[k][i], graph[mink][k] + dist[mink][i]);
        }
      }
    }
  }

  long long dist2[n][z];
  for (long long i = 0; i < n; i++){
    for (long long j = 0; j < z; j++){
      dist2[i][j] = 1000000000;
    }
  }
  for (long long i = 0; i < z; i++){
    dist2[i][i] = 0;
    bool visited[n];
    memset(visited, 0, sizeof(visited));
    for (long long j = 0; j < n; j++){
      long long mink = -1;
      for (long long k = 0; k < n; k++){
        if (!visited[k] && (mink == -1 || dist2[k][i] < dist2[mink][i])){
          mink = k;
        }
      }
      if (mink != -1){
        visited[mink] = true;
        for (long long k = 0; k < n; k++){
          dist2[k][i] = min(dist2[k][i], graph[k][mink] + dist2[mink][i]);
        }
      }
    }
  }

/*  for (long long i = 0; i < z; i++){
    for (long long j = 0; j < n; j++){
      cout << dist[j][i] << " ";
    }
    cout << endl;
  }
  for (long long i = 0; i < z; i++){
    for (long long j = 0; j < n; j++){
      cout << dist2[j][i] << " ";
    }
    cout << endl;
  }*/

  long long ans = 0;
  long long ans2 = 0;

  for (long long i = 0; i < q; i++){
    long long a, b;
    cin >> a >> b;
    long long mindist = 1000000000;
    for (long long j = 0; j < z; j++){
        mindist = min(mindist, dist2[a-1][j] + dist[b-1][j]);
    }
    if (mindist < 1000000000){
      ans++;
      ans2 += mindist;
    }
  }
  cout << ans << endl << ans2;
}

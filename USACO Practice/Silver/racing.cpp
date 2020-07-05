#include <iostream>

using namespace std;

int getTerrainTime(char a, int u, int f, int d){
  if (a == 'u'){
    return u;
  }
  else if (a == 'f'){
    return f;
  }
  else{
    return d;
  }
}

char flipTerrain(char a){
  if (a == 'u'){
    return 'd';
  }
  if (a == 'f'){
    return 'f';
  }
  else{
    return 'u';
  }
}

int main(){
  int m, t, u, f, d;
  cin >> m >> t >> u >> f >> d;
  char terrain[t];
  for (int i = 0; i < t; i++){
    char x;
    cin >> x;
    terrain[i] = x;
  }
  int output = 0;
  int x = 0;
  for (int i = 0; i < t; i++){
    x += getTerrainTime(terrain[i], u, f, d);
    x += getTerrainTime(flipTerrain(terrain[i]), u, f, d);
    if (x <= m){
      output = i+1;
    }
  }
  cout << output;
}

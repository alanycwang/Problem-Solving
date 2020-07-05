#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int q;
int w[20];
int r = 0;

struct Part{
  int force;
  int mass;
  float acceleration;
  int index;
};

Part parts[20];

bool sortparts(const Part& a, const Part& b) {
  return a.acceleration > b.acceleration;
}

int recur(int f, int m, Part parts[20], int y){
  int force = f;
  int mass = m;
  force += parts[y].force;
  mass += parts[y].mass;
  //cout << f << " " << m << " " << force << " " << mass << " " << y << endl;
  float a = float(force)/mass;

  if (a > float(f)/m){
    w[r] = parts[y].index;
    r++;
    q++;
    if (y < n){
      recur(force, mass, parts, y+1);
    }
  }
  //cout << a << endl;
  return a;
}

int main(){

  int f, m;
  cin >> f >> m >> n;
  for (int i = 0; i < n; i++){
    int force;
    int mass;
    cin >> force >> mass;
    parts[i].force = force;
    parts[i].mass = mass;
    parts[i].acceleration = float(force)/float(mass);
    parts[i].index = i + 1;
  }
  sort(parts, parts+n, sortparts);
  recur(f, m, parts, 0);
  if (q == 0){
    cout << "NONE";
  }
  sort(w, w+q);
  for (int i = 0; i < q; i++){
    cout << w[i] << endl;
  }
}

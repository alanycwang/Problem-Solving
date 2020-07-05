#include <iostream>
#include <algorithm>

using namespace std;

struct Part{
  int force;
  int mass;
  float acceleration;
  int index;
};

bool sortparts(const Part& a, const Part& b) {
  return a.acceleration > b.acceleration;
}

int main(){
  int f, m, n;
  cin >> f >> m >> n;
  Part parts[n];
  for (int i = 0; i < n; i++){
    int force;
    int mass;
    cin >> force >> mass;
    parts[i].force = force;
    parts[i].mass = mass;
    parts[i].acceleration = float(force)/float(mass);
    parts[i].index = i + 1;
  }
  sort(parts, parts + n, sortparts);
  int array[n];
  int force = f;
  int mass = m;
  float acceleration;
  float last_a = f/m;
  int last_index = -1;
  int i = 0;
  for (; i < n; i++){
    force += parts[i].force;
    mass += parts[i].mass;
    acceleration = float(force)/mass;
    if (acceleration < last_a){
      break;
    } else if (acceleration > last_a) {
      last_index = i;
    }
    last_a = acceleration;
    array[i] = parts[i].index;
  }
  if (last_index >= 0){
    sort(array, array + last_index + 1);
    for (int j = 0; j <= last_index; j++){
      cout << array[j] << endl;
    }
  }
  else {
    cout << "NONE";
  }
}

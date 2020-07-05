#include <iostream>
#include <vector>

using namespace std;

int n, m;

bool visited[10];
int numbers[10];
int numbers2[10];
int numbers3[9];
bool stop = false;

int simulate(int a){
  /*for (int i = 0; i < 10; i++){
    cout << numbers2[i] << " ";
  }*/
  //cout << endl;
  if (a == 1){
    //cout << numbers2[0] << endl;
    return numbers2[0];
  }
  for (int i = 0; i < a - 1; i++){
    numbers3[i] = (numbers2[i] + numbers2[i + 1]);
  }
  for (int i = 0; i < a; i++){
    numbers2[i] = numbers3[i];
  }
  return(simulate(a-1));
}

void recurse (int a){
  /*for (auto i : numbers){
    cout << i << " ";
  }
  cout << endl;
  cout << a << endl << endl;*/
  if (stop){
    return;
  }
  if (a == 0){
    for (int i = 0; i < n; i++){
      numbers2[i] = numbers[i];
    }
    int b = simulate(n);
    if (b == m){
      for (int i = 0; i < n; i++){
        cout << numbers[i] << " ";
      }
      stop = true;
    }
    return;
  }
  for (int i = 1; i < n + 1; i++){
    if (visited[i]){
      continue;
    }
    visited[i] = true;
    numbers[n-a] = i;
    recurse (a-1);
    numbers[n-a] = 0;
    visited[i] = false;
  }
}

int main(){
  cin >> n >> m;
  recurse(n);
}

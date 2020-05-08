#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numbers;
vector<int> a;
vector<int> b;

//WORKING DO NOT EDIT
vector<int> merge(vector<int> a, vector<int> b){
  vector<int> c;
  while (a.size() > 0 && b.size() > 0){
    if (a[0] > b[0]){
      c.push_back(b[0]);
      b.erase(b.begin());
    }
    else{
      c.push_back(a[0]);
      a.erase(a.begin());
    }
  }
  while(a.size() > 0){
    c.push_back(a[0]);
    a.erase(a.begin());
  }
  while(b.size() > 0){
    c.push_back(b[0]);
    b.erase(b.begin());
  }
  return c;
}

void mergeSort(int l, int r, vector<int> vector){
  cout << l << " " << r << endl;
  if (l == r){
    return;
  }
  int x = 0;
  for (int i = l; i <= (l+r-1)/2; i++){
    a[x] = numbers[i];
    x++;
  }
  x=0;
  for (int i = (l+r-1)/2+1; i < r; i++){
    b[x] = numbers[i];
    x++;
  }
  mergeSort(l, (l+r-1)/2, a);
  mergeSort((l+r-1)/2+1, r, b);
  vector = merge(a, b);
}

int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    numbers.push_back(x);
  }
  mergeSort(0, n-1, numbers);
  for (auto q : numbers){
    cout << q << " ";
  }
}

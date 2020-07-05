#include <iostream>
#include <set>

using namespace std;

int main(){
  multiset<int> ms;
  ms.insert(1);
  ms.insert(1);
  ms.erase(ms.find(1));
  for (auto i : ms) {
    cout << i << endl;
  }

  cout << *ms.end();
}

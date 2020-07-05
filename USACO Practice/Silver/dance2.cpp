#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
  int n;

  cin >> n;
  vector<string> cows;
  int lengths[n];
  for (int i = 0; i < n; i++){
    cin >> lengths[i];
    string x;
    cin >> x;
    cows.push_back(x);
  }
  for (int i = 0; i < n; i++){
    int score = 0;
    bool skip = false;
    for (int j = 0; j < lengths[i]; j++){
      if (cows[i][j] == '<'){
        score--;
      }
      else if (cows[i][j] == '>'){
        score++;
      }
      if (score < 0){
        cout << "illegal" << endl;
        skip = true;
        break;
      }
    }
    if (skip){
      continue;
    }
    if (score == 0){
      cout << "legal" << endl;
    }
    else {
      cout << "illegal" << endl;
    }
  }

}

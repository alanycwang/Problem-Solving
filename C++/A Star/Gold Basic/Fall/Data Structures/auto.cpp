#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct word{
  string word;
  int index;
};

bool helper(word a, word b){
  return a.word < b.word;
}

int main(){
  int w, n;
  cin >> w >> n;
  word words[w];
  for (int i = 0; i < w; i++){
    cin >> words[i].word;
    words[i].index = i;
  }
  sort(words, words + w, helper);
  /*for (auto i : words){
    cout << i.word << endl;
  }*/
  for (int i = 0; i < n; i++){
    //cout << "working" << endl;
    int k;
    string a;
    cin >> k >> a;
    //cout << a << endl;
    int c = 0;
    bool end2 = false;
    for (int j = 0; j < w; j++){
      //cout << words[j].word << c+1 << endl;
      //cout << "working" << endl;
      bool end = false;
      string b = words[j].word;
      for (int l = 0; l < a.size(); l++){
        if (b[l] != a[l]){
          end = true;
          break;
        }
      }
      if (j == w - 1){
        cout << -1 << endl;
      }
      if (end){
        if (end2){
          cout << -1 << endl;
          break;
        }
        continue;
      }
      else {
        c++;
        end2 = true;
        if (c == k){
          cout << words[j].index + 1 << endl;
          break;
        }
      }
    }
  }
}

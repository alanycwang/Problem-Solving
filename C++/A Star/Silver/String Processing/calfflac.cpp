#include <iostream>

using namespace std;

string input;
string clean;
int index[100000];
int ans = 0;
string ans2;

void is_palind(int x, int y){
  int length = 0;
  int begin;
  int end;
  if (clean[x] == clean[y]){
    if (x == y){
      length++;
    }
    else{
      length += 2;
    }
    for (int i = 1;;i++){
      if (x!= 0 && clean[x-i] == clean[y+i]){
        length+=2;
      }
      else {
        begin = x-(i-1);
        end = y+i-1;
        break;
      }
    }
  }

  if (begin < end){
    if (length > ans){
      ans = length;
      ans2.clear();
      for (int i = 0; i < index[end]-index[begin]+1; i++){
        ans2.push_back(input[i+index[begin]]);
      }
    }
  }
}

int main(){
  string temp;
  while(true){
    getline(cin, temp);
    if(cin.eof()){break;}
    input += temp + '\n';
  }
  int x = 0;
  for (int i = 0; i < input.size(); i++){
    if (input[i] >= 'A' && input[i] <='Z' || input[i] >= 'a' && input[i] <='z'){
      clean.push_back(toupper(input[i]));
      index[x] = i;
      x++;
    }
  }
  for (int i = 0; i < clean.size(); i++){
    is_palind(i, i);
    is_palind(i, i+1);
  }
  cout << ans << endl << ans2;
}

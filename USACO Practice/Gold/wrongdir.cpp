#include <iostream>
#include <set>

using namespace std;

int main(){
  string command;
  cin >> command;
  pair<int, int> location;
  int direction = 0;
  int directionx[4] = {1, 0, -1, 0};
  int directiony[4] = {0, 1, 0, -1};
  for (int i = 0; i < command.length(); i++){
    if (command[i] == 'R'){
      direction++;
    }
    else if(command[i] == 'F'){
      location.first += directionx[direction];
      location.second += directiony[direction];
    }
    else{
      direction--;
      direction = direction % 4;
    }
  }
  //cout << location.first << " " << location.second << endl;
  set<pair<int, int>> visited;
  for (int i = 0; i < command.length(); i++){
    int commands[3] = {'R', 'F', 'L'};
    for (int j = 0; j < 3; j++){
      if (command[i] != commands[j]){
        if (j == 0){
          visited.insert(make_pair())
        }
      }
    }
  }
}

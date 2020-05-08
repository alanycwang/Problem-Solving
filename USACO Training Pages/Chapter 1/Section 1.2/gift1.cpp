/*
ID: alanycw1
LANG: C++
TASK: gift1
*/
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> book;

vector<string> getPeople(ifstream* input){
  string np1;
  int np;
  getline(*input, np1);
  stringstream x(np1);
  x >> np;

  vector<string> people;
  for (int i = 0; i < np; i++) {
    string person;
    getline(*input, person);
    book[person] = 0;
    people.push_back(person);
  }
  return people;
}

void readGroup(ifstream* input){
  string giver;
  vector<string> recievers;
  string line;
  getline(*input, giver);
  getline(*input, line);
  int nGiven, nRecievers;
  sscanf(line.c_str(), "%d %d", &nGiven, &nRecievers);
  if (nGiven != 0) {
    for (int i = 0; i < nRecievers; i++){
      string line0;
      getline(*input, line0);
      recievers.push_back(line0);
    }
    for (int i= 0; i < recievers.size(); i++) {
      book[recievers[i]] += (nGiven - nGiven%nRecievers)/nRecievers;
    }
    book[giver] -= nGiven - nGiven%nRecievers;
  }
}

int main() {
  ifstream input;
  input.open("gift1.in");
  ofstream output;
  output.open("gift1.out");
  vector<string> people;
  people = getPeople(&input);
  for (int i = 0; i < book.size(); i++){
    readGroup(&input);
  }

  for (int j = 0; j < book.size(); j++){
    output << people[j] << " " << book[people[j]] << endl;
  }


}

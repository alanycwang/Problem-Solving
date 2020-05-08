#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int r, c, e, n;
  cin >> r >> c >> e >> n;
  int depths[r*c];
  for (int i = 0; i < r*c; i++){
    cin >> depths[i];
  }
  for (int i = 0; i < n; i++){
    int coordinate1;
    int coordinate2;
    int depth;
    cin >> coordinate1;
    cin >> coordinate2;
    cin >> depth;
    int x[9];
    int greatest;
    int x_sorted[9];
    for (int j = 0; j < 3; j++){
      for (int k = 0; k < 3; k++){
        x[3*j+k] = depths[((coordinate1+j-1)*c)+coordinate2+k-1];
        x_sorted[3*j+k] = depths[((coordinate1+j-1)*c)+coordinate2+k-1];
        //cout << x[3*j+k] << " ";
      }
      //cout << endl;
    }
    sort(x_sorted, x_sorted+9);
    greatest = x_sorted[8];
    for (int j = 0; j < 3; j++){
      for (int k = 0; k < 3; k++){
        if (x[3*j+k] > greatest-depth){
          depths[((coordinate1+j-1)*c)+coordinate2+k-1] = greatest-depth;
        }
      }
    }
    //cout << greatest << endl;
    for(int j = 0; j < r; j++){
      for (int k = 0; k < c; k++){
        //cout << depths[c*j+k] << " ";
      }
      //cout << endl;
    }
    //cout << endl;
  }
  long volumes = 0;;
  int x;
  for (int i = 0; i < r; i++){
    for (int j = 0; j < c; j++){
      x = e-depths[c*i+j];
      if (e-depths[c*i+j]<0){
        x = 0;
      }
      //cout << x << " ";
      volumes +=x;
    }
    //cout << endl;
  }

  cout << volumes*72*72;
}

#include <iostream>

using namespace std;

int func(int num) {
	int x = 0;
	for (int i = 1; i <= num; i++) {
		if (num % i == 0) {
			x++;
		}
	}
	return x;
}

int main(){
  for (int i = 2971;; i++){
    if (func(i) == 32){
      cout << i;
      break;
    }
  }

}

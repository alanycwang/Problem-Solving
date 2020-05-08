#include <iostream>

int fib(int x){
  if(x == 1 || x ==2){
    return 1;
  }
  return fib (x-1)+fib(x-2);

}

int main(){
  int x;
  std::cin >> x;
  std::cout << fib(x);
}

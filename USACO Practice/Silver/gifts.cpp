#include <iostream>
#include <algorithm>

using namespace std;

struct gift{
  int price;
  int shipping;
  int total_price;
};

bool sortGift(gift a, gift b){
  return a.total_price < b.total_price;
}

int main(){
  int n, b;
  cin >> n >> b;
  gift gifts[n];
  for(int i = 0; i < n; i++){
    int x, y;
    cin >> x >> y;
    gifts[i].price = x;
    gifts[i].shipping = y;
    gifts[i].total_price = x + y;
  }
  int x = 0;
  int y = 0;
  sort(gifts, gifts+n, sortGift);
  for (int i = 0; i < n; i++){
    x+=gifts[i].total_price;
    y++;
    if (x > b){
      x-=gifts[i].total_price;
      x+=gifts[i].price/2;
      x+=gifts[i].shipping;
      if (x > b){
        y--;
      }
      break;
    }
  }
  cout << y;
}

//too slow
#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, m, q;
  cin >> n >> m >> q;
  int p[m];
  for (int i = 0; i < m; i++){
    cin >> p[i];
  }
  vector<int> cards;
  for (int i = 0; i < n; i++){
    cards.push_back(i+1);
  }
  //cout << endl;
  vector<int> ans;
  for (int i = 0; i < n-m+1; i++){
    vector<int> temp (m);
    copy(cards.begin(), cards.begin() + m, temp.begin());
/*    for (int j = 0; j < m; j++){
      cout << temp[j] << endl;
    }
    cout << endl;*/
    for (int j = 0; j < m; j++){
      cards[p[j]-1] = temp[j];
    }
/*    for (int j = 0; j < n; j++){
      cout << cards[j] << " ";
    }*/
    //cout << endl;
    ans.insert(ans.begin(), cards[0]);
    cards.erase(cards.begin());
  }
  for (int i = n-m+1; i < n; i++){
    ans.insert(ans.begin(), cards[0]);
    cards.erase(cards.begin());
  }
  for (int i = 0; i < q; i++){
    int a;
    cin >> a;
    cout << ans[a-1] << endl;
  }
/*  for (int i = 0; i < ans.size(); i++){
    cout << ans[i] << " ";
  }*/
}

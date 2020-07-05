#include <bits/stdc++.h>

using namespace std;

vector<set<long long>> polygons;
long long n, c;
long long fences[1000][2][2];
long long cows[1000][2];
bool used[1000];
vector<long long> tally;
vector<float> areas;

void find_polygons(long long fence, long long start, long long polygon, long long dir, bool first) {
  if (fence == start && !first) return;
  //cout << fences[fence][dir][0] << " " << fences[fence][dir][1] << endl;
  for (long long i = 0; i < n; i++) {
    //cout << fences[i][0][0] << " " << fences[i][0][1] << " " << fences[i][1][0] << " " << fences[i][1][1] << endl;
    if (!used[i] && i != fence && fences[fence][dir][0] == fences[i][0][0] && fences[fence][dir][1] == fences[i][0][1]) {
      areas[polygon] += fences[fence][!dir][0]*fences[fence][dir][1] - fences[fence][dir][0]*fences[fence][!dir][1];
      areas[polygon] += fences[fence][dir][0]*fences[i][0][1] - fences[i][0][0]*fences[fence][dir][1];
      polygons[polygon].insert(i);
      used[i] = true;
      find_polygons(i, start, polygon, 1, false);
      return;
    }
    if (!used[i] && i != fence && fences[fence][dir][0] == fences[i][1][0] && fences[fence][dir][1] == fences[i][1][1]) {
      areas[polygon] += fences[fence][!dir][0]*fences[fence][dir][1] - fences[fence][dir][0]*fences[fence][!dir][1];
      areas[polygon] += fences[fence][dir][0]*fences[i][1][1] - fences[i][1][0]*fences[fence][dir][1];
      polygons[polygon].insert(i);
      used[i] = true;
      find_polygons(i, start, polygon, 0, false);
      return;
    }
  }
  //cout << endl;
}

long long ccw(long long a[2], long long b[2], long long x[2]) {
  __int128 temp = __int128(b[0] - a[0])*__int128(x[1] - a[1]) - __int128(b[1] - a[1])*__int128(x[0] - a[0]);
  if (temp < 0) return -1;
  if (temp == 0) return 0;
  return 1;
}

bool intersection(long long a[2], long long b[2], long long x[2], long long y[2]) {
  return (ccw(a, x, b) * ccw(a, y, b) == -1 && ccw(x, a, y) * ccw(x, b, y) == -1);
}

bool inside(long long cow, long long polygon) {
  long long cnt = 0;
  //cout << "working" << endl;
  //cout << polygons[polygon].size() << endl;
  //cout << polygon << endl;
  //cout << *polygons[polygon].begin() << endl;
  for (set<long long>::iterator i = polygons[polygon].begin(); i != polygons[polygon].end(); i++) {
    //cout << *i << endl;
    //cout << "working" << endl;
    long long temp[2] = {cows[cow][0] + 1, LLONG_MAX};
    //cout << "working" << endl;
    if (intersection(fences[*i][0], fences[*i][1], cows[cow], temp)) cnt++;
    //cout << "working" << endl;
  }
  //cout << "not working" << endl;
  return cnt%2;
}

int main() {
  cin >> n >> c;
  for (long long i = 0; i < n; i++) cin >> fences[i][0][0] >> fences[i][0][1] >> fences[i][1][0] >> fences[i][1][1];
  for (long long i = 0; i < c; i++) cin >> cows[i][0] >> cows[i][1];

  long long polygon = 0;
  for (long long i = 0; i < n; i++) {
    if (!used[i]) {
      set<long long> empty;
      areas.push_back(0);
      tally.push_back(0);
      polygons.push_back(empty);
      find_polygons(i, i, polygon, 0, true);
      polygon++;
      used[i] = true;
    }
  }
  tally.push_back(0);

/*  for (auto i : polygons) {
    for (auto j : i) cout << j << " ";
    cout << endl;
  }*/

  for (long long i = 0; i < polygon; i++) {
    areas[i] = abs(areas[i]);
    areas[i] = areas[i]/2;
    //cout << areas[i] << endl;
  }

  for (long long i = 0; i < c; i++) {
    long long smallest = polygon;
    bool first = true;
    for (long long j = 0; j < polygon; j++) if (inside(i, j) && (first || areas[j] < areas[smallest])) {
        first = false;
        smallest = j;
    }
    tally[smallest]++;
  }

  //cout << polygon << endl;

  long long ans = 0;
  for (long long i = 0; i <= polygon; i++) {
    ans = max(ans, tally[i]);
    //cout << tally[i] << " ";
  }
  //cout << endl;
  cout << ans;
}

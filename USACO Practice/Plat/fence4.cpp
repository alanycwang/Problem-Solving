#include <iostream>
#include <cmath>

using namespace std;

int n;
int observer[2];
int vertices[200][2];
bool visible[200];

long long ccw(int a[2], int b[2], int x[2]) {
  int64_t temp = int64_t(b[0] - a[0])*int64_t(x[1] - a[1]) - int64_t(b[1] - a[1])*int64_t(x[0] - a[0]);
  if (temp < 0) return -1;
  if (temp == 0) return 0;
  return 1;
}

bool intersection(int a[2], int b[2], int x[2], int y[2]) {
  return (ccw(a, x, b) * ccw(a, y, b) == -1 && ccw(x, a, y) * ccw(x, b, y) == -1);
}

pair<float, float> equation(float a[2], int b[2]) {
  float slope = float(a[1] - b[1])/float(a[0] - b[0]);
  return make_pair(slope, float(a[1]) - slope*float(a[0]));
}

pair<int, int> intersect(pair<float, float> a, pair<float, float> b) {
  float x = (a.second - b.second)/(a.first - b.first);
  return make_pair(x, x*a.first + a.second);
}

float dist(pair<float, float> a, pair<float, float> b) {
  pair<int, int> temp = intersect(a, b);
  return sqrt((temp.first - observer[0])^2 + (temp.second - observer[1])^2);
}

void closest(float point[2]) {
  pair<float, float> eq = equation(point, observer);
  int closest = -1;
  float mindist = 1000000000;
  for (int i = 0; i < n; i++) {
    float tmp[2] = {float(vertices[i][0]), float(vertices[i][1])};
    pair<float, float> temp;
    temp = equation(tmp, vertices[(i + 1)%n]);
    float dst = dist(eq, temp);
    if (dst < mindist) {
      mindist = dst;
      closest = i;
    }
  }
  visible[closest] = true;
}

int main() {
  cin >> n >> observer[0] >> observer[1];
  for (int i = 0; i < n; i++) {
    cin >> vertices[i][0] >> vertices[i][1];
  }

  for (int i = 0; i < n; i++) for (int j = i + 2; j < n; j++) if (abs(i-j) > 1 && intersection(vertices[i], vertices[(i + 1)%n], vertices[j], vertices[(j + 1)%n])) {
    cout << "NOFENCE" << endl;
    return 0;
  }

  for (int i = 0; i < n; i++) {
    float temp[2] = {float(vertices[i][0]), float(vertices[i][1])};
    closest(temp);
    temp[0] = (vertices[i][0] + vertices[(i + 1)%n][0])/2.0;
    temp[1] = (vertices[i][1] + vertices[(i + 1)%n][1])/2.0;
    closest(temp);
  }

  for (int i = 0; i < n; i++) if (visible[i]) {
    cout << vertices[i][0] << " " << vertices[i][1] << " " << vertices[(i + 1)%n][0] << " " << vertices[(i + 1)%n][1] << endl;
  }
}

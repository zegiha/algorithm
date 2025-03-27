#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using pipii = pair <int, pair <int, int>>;

int n, p[100'001], ans;
vector <pair <int, int>> x, y, z;
vector <pipii> edge;

int abs(int a) {
  if(a < 0) return a * -1;
  return a;
}

void processing(vector <pair <int, int>>& arr) {
  sort(arr.begin(), arr.end());
  for(int i = 0; i < n-1; i++) {
    edge.push_back({abs(arr[i].first - arr[i+1].first), {arr[i].second, arr[i+1].second}});
  }
}

int Find(int target) {
  if(p[target] == target) return target;
  return p[target] = Find(p[target]);
}
void Union(int f, int s) {
  p[s] = f;
}

void solve() {
  for(int i = 0; i < edge.size(); i++) {
    int
    first_parent = Find(edge[i].second.first),
    second_parent = Find(edge[i].second.second);

    if(first_parent != second_parent) {
      Union(first_parent, second_parent);
      ans += edge[i].first;
    }
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    int nx, ny, nz; cin >> nx >> ny >> nz;
    x.push_back({nx, i});
    y.push_back({ny, i});
    z.push_back({nz, i});
  }

  processing(x);
  processing(y);
  processing(z);
  sort(edge.begin(), edge.end());
  for(int i = 0; i < n; i++) p[i] = i;

  solve();

  cout << ans;
}
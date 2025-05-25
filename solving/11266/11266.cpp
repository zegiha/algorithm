#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector <vector <int>> arr;
vector <int> discover;

void dfs(int target, int cnt) {
  discover[target] = cnt;
  for(int i = 0; i < arr[target].size(); i++) {
    
  }
}

int main() {
  cin >> n >> m;

  arr.resize(n + 1, vector <int> (0));
  discover.resize(n + 1, -1);

  int a, b;
  while(m--) {
    cin >> a >> b;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }

  dfs(1, 1);
}
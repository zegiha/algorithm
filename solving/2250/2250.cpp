#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, tree[10'001][2], childCnt[10'001][2], position[10'001];
vector <vector <int>> level;
pair <int, int> ans;

int setChildCntAndLevel(int node, int currentLevel) {
  level[currentLevel].push_back(node);

  if(tree[node][0] != -1) childCnt[node][0] = setChildCntAndLevel(tree[node][0], currentLevel + 1);
  if(tree[node][1] != -1) childCnt[node][1] = setChildCntAndLevel(tree[node][1], currentLevel + 1);
  
  return childCnt[node][0] + childCnt[node][1] + 1;
}

void setPosition(int node, int offset) {
  position[node] = offset + childCnt[node][0] + 1;

  if(tree[node][0] != -1) setPosition(tree[node][0], offset);
  if(tree[node][1] != -1) setPosition(tree[node][1], position[node]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  level.resize(n + 1, {});

  int a, b, c;
  for(int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    tree[a][0] = b;
    tree[a][1] = c;
  }

  setChildCntAndLevel(1, 1);
  setPosition(1, 0);

  int targetLevel = 1, width;
  ans = {-1, -2'100'000'000};

  while(level[targetLevel].size()) {
    int leftMost = 2'100'000'000, rightMost = -2'100'000'000;

    for(auto& node : level[targetLevel]) {
      leftMost = min(leftMost, position[node]);
      rightMost = max(rightMost, position[node]);
    }

    width = rightMost - leftMost + 1;
    if(ans.second < width) {
      ans = {targetLevel, width};
    }
    
    targetLevel++;
  }

  cout << ans.first << ' ' << ans.second;
}
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector <vector <int>> arr;

vector <bool> isCut;
vector <int> discover;

int discoverCnt = 1;
int setIsCut(int target, bool isRoot) {
  int res = discover[target] = discoverCnt++, child, childRes, childCnt = 0;

  for(int i = 0; i < arr[target].size(); i++) {
    child = arr[target][i];
    if(discover[child] == -1) {
      childCnt++;
      childRes = setIsCut(child, false);
      if(!isRoot && discover[target] <= childRes) isCut[target] = true;
      res = min(res, childRes);
    } else {
      res = min(res, discover[child]);
    }
  }

  if(isRoot && childCnt > 1) isCut[target] = true;

  return res;
}

int main() {
  cin >> n >> m;
  arr.resize(n + 2, vector <int> (0));
  isCut.resize(n + 2, false);
  discover.resize(n + 2, -1);
  int a, b;
  while(m--) {
    cin >> a >> b;
    arr[a].push_back(b);
    arr[b].push_back(a);
  }

  for(int i = 1; i <= n; i++) {
    if(discover[i] == -1) {
      setIsCut(i, true);
    }
  }

  int ansCnt = 0;
  for(int i = 1; i <= n; i++) if(isCut[i]) ansCnt++;
  cout << ansCnt << '\n';
  for(int i = 1; i <= n; i++) if(isCut[i]) cout << i << ' ';

  return 0;
}
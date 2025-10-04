#include <iostream>

using namespace std;
using pii = pair <int, int>;

int n, post[100'001], in[100'001], bt[100'002][2];

void abbyRoad(int postIdx, int inIdx, pii inRange) {
  // cout << postIdx << ' ' << inIdx << ' ' << inRange.first << ' ' << inRange.second << '\n';

  int newInIdx;
  bool isLeft = false;
  for(int i = inRange.first; i < inIdx; i++) {
    if(in[i] == post[postIdx - 1]) {
      isLeft = true;
      newInIdx = i;
      break;
    }
  }

  if(isLeft) {
    bt[post[postIdx]][0] = post[postIdx - 1];
    if(inRange.first >= inIdx - 1) return;
    abbyRoad(postIdx - 1, newInIdx, {inRange.first, inIdx - 2});
  } else {
    if(inIdx + 1 <= inRange.second) {
      int childrenCnt = inRange.second - (inIdx + 1);
      for(int i = inRange.first; i < inIdx; i++) {
        if(in[i] == post[postIdx - 2 - childrenCnt]) {
          newInIdx = i;
          break;
        }
      }

      bt[post[postIdx]][0] = post[postIdx - 2 - childrenCnt];
      if(inRange.first < inIdx - 1) {
        abbyRoad(postIdx - 1 - childrenCnt, newInIdx, {inRange.first, inIdx - 2});
      }
    }

    

    for(int i = inIdx + 1; i <= inRange.second; i++) if(in[i] == post[postIdx - 1]) {
      newInIdx = i;
      break;
    }

    bt[post[postIdx]][1] = post[postIdx - 1];
    if(inIdx + 1 >= inRange.second) return;
    abbyRoad(postIdx - 1, newInIdx, {inIdx + 2, inRange.second});

  }
}

void printingPre(int node) {
  cout << node << ' ';

  if(bt[node][0]) printingPre(bt[node][0]);
  if(bt[node][1]) printingPre(bt[node][1]);
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> in[i];
  for(int i = 0; i < n; i++) cin >> post[i];

  int rootInIdx;
  for(int i = 0; i < n; i++) if(in[i] == post[n-1]) {
    rootInIdx = i;
    break;
  }

  abbyRoad(n-1, rootInIdx, {0, n-1});
  printingPre(post[n-1]);
}
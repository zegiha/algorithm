#include <iostream>

using namespace std;

int n, in[100'001], post[100'001], inIdx[100'002];

void tpac(int inStart, int inEnd, int postStart, int postEnd) {
  if(inStart > inEnd || postStart > postEnd) return;

  int target = post[postEnd];

  cout << target << ' ';

  int targetInIdx = inIdx[target], leftSize = targetInIdx - inStart;

  tpac(inStart, targetInIdx - 1, postStart, postStart + leftSize - 1);
  tpac(targetInIdx + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> in[i];
  for(int i = 0; i < n; i++) cin >> post[i];
  for(int i = 0; i < n; i++) inIdx[in[i]] = i;

  tpac(0, n-1, 0, n-1);
}
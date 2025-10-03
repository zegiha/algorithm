#include <iostream>

using namespace std;
using pii = pair <int, int>;

int n, in[100'001], post[100'001], bt[100'002][2];

void printPre(int node) {
  cout << node << ' ';
  if(bt[node][0])printPre(bt[node][0]);
  if(bt[node][1])printPre(bt[node][1]);
}

void setBt(int postIdx, int inIdx, int leftStart, int rightEnd) {
  cout << postIdx << ' ' << inIdx << ' ' << leftStart << ' ' << rightEnd << '\n';

  int childInIdx = -1;
  bool isLeftChild = false;

  for(int i = leftStart; i < inIdx; i++)
  if(post[postIdx - 1] == in[i]) {
    isLeftChild = true;
    childInIdx = i;
    break;
  }

  if(isLeftChild) {
    bt[post[postIdx]][0] = post[postIdx - 1];
    if(leftStart >= childInIdx -1) return;
    setBt(postIdx - 1, childInIdx, leftStart, childInIdx - 1);
  } else {
    for(int i = inIdx + 1; i <= rightEnd; i++) if(post[postIdx-1] == in[i]) {
      childInIdx = i;
      break;
    }

    bt[post[postIdx]][1] = post[postIdx - 1];
    if(childInIdx + 1 >= rightEnd) return;
    setBt(postIdx -1, childInIdx, childInIdx + 1, rightEnd);
  }
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> in[i];
  for(int i = 0; i < n; i++) cin >> post[i];

  int inIdx = -1;
  for(int i = 0; i < n; i++) if(in[i] == post[n-1]) {
    inIdx = i;
    break;
  }

  setBt(n-1, inIdx, 0, n-1);
  printPre(post[n-1]);
}
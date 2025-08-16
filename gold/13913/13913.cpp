#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector <vector <int>> trace;

int n, k;

bool isArea(int i) {
  return 0 <= i && i <= 100'000;
}

void printTrace(int target, int idx) {
  // cout << "----------" << target << ' ' << idx << '\n';
  if(idx == -1) {
    cout << n << ' ';
    return;
  }

  for(int v : trace[idx]) {
    if(
      v + 1 == target ||
      v - 1 == target ||
      ((target % 2 == 0) && (v * 2 == target))
    ) {
      printTrace(v, idx - 1);
      cout << v << ' ';
      break;
    }
  }
}

int main() {
  cin >> n >> k;

  int ans = 0;
  bool sw = false;
  queue <int> q;
  bool visit[100'001] = {0, };

  q.push(n);
  visit[n] = true;

  while(!q.empty() && !sw) {
    int size = q.size(), traceIdx = trace.size();
    trace.push_back({});

    while(size--) {
      int i = q.front();
      q.pop();

      if(i == k) {
        sw = true;
        break;
      }

      if(isArea(i + 1) && !visit[i + 1]) {
        trace[traceIdx].push_back(i + 1);
        visit[i + 1] = true;
        q.push(i + 1);
      }
      if(isArea(i - 1) && !visit[i - 1]) {
        trace[traceIdx].push_back(i - 1);
        visit[i - 1] = true;
        q.push(i - 1);
      }
      if(isArea(i * 2) && !visit[i * 2]) {
        trace[traceIdx].push_back(i * 2);
        visit[i * 2] = true;
        q.push(i * 2);
      }
    }
    ans++;
  }

  // for(int i = 0; i < trace.size(); i++) {
  //   for(int j = 0; j < trace[i].size(); j++) {
  //     cout << trace[i][j] << ' ';
  //   }
  //   cout << '\n';
  // }

  cout << ans - 1 << '\n';
  printTrace(k, trace.size() - 3);
  cout << k << ' ';
}
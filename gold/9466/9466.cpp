#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
vector <int> arr;

int main() {
  int tc;
  cin >> tc;
  while(tc--) {
    cin >> n;
    arr.resize(n + 2);
    for(int i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    int ans = n;
    vector <bool> mainVisit;
    mainVisit.resize(n + 2);
    for(int i = 1; i <= n; i++) {
      if(!mainVisit[i]) {
        int root = i, cnt = 1;
        vector <bool> visit;
        visit.resize(n + 2);
        stack <int> s;
        s.push(i);
        visit[i] = true;
        mainVisit[i] = true;
        while(!s.empty()) {
          int row = arr[s.top()]; s.pop();
          if(!visit[row] && !mainVisit[row]) {
            visit[row] = true;
            s.push(row);
            cnt++;
          } else {
            if(root == row) {
              // cout << row << ' ' << cnt << endl;
              ans -= cnt;
              for(int i = 1; i <= n; i++) if(visit[i]) mainVisit[i] = true;
            }
          }
        }
      }
    }
    cout << ans;
  }
}
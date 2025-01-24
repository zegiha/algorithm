#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, P, ans;

int main() {
  cin >> N >> P;

  int n, p;
  vector <stack <int>> ss (7, stack <int> ());
  while(N--) {
    int t = 0;
    cin >> n >> p;
    while(!ss[n].empty() && ss[n].top() > p) {
      ss[n].pop();
      ans++;
      t++;
    }
    if(ss[n].empty() || ss[n].top() < p) {
      ss[n].push(p);
      ans++;
      t++;
    }
    // cout << N << " : " << t << '\n';
  }
  cout << ans;
}

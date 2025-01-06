#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  int center = 0, t;
  priority_queue <int, vector<int>, greater<int>> min_q;
  priority_queue <int> max_q;
  for(int i = 0; i < n; i++) {
    cin >> t;

    if(max_q.size() == 0) {
      max_q.push(t);
    } else {
      if(min_q.size() < max_q.size()) {
        min_q.push(t);
      } else {
        max_q.push(t);
      }
      
      if(min_q.top() < max_q.top()) {
        int min_t = min_q.top(), max_t = max_q.top();
        min_q.pop(); max_q.pop();

        min_q.push(max_t);
        max_q.push(min_t);
      }
    }

    cout << max_q.top() << '\n';
  }
}
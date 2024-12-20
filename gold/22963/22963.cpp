#include <iostream>
#include <vector>

using namespace std;

int n, arr[200'001];
vector <pair <int, int>> ans;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for(int i = 0; i < n - 1; i++) {
    if(arr[i] > arr[i + 1]) {
      if(ans.size() >= 3) {
        cout << "NO";
        return 0;
      } else {
        arr[i + 1] = arr[i];
        ans.push_back({i + 1, arr[i]});
      }
    }
  }
  
  cout << "YES\n" << ans.size() << '\n';
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << ' ' << ans[i].second << '\n';
  }
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, arr[8];
// vector <vector <int>> ans;

void solve(int i, int cnt, vector <int> ans) {
    ans.push_back(arr[i]);
    if(cnt == m) {
        for(int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    else {
        for(int j = i + 1; j < n; j++) {
            solve(j, cnt + 1, ans);
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    for(int i = 0; i < n; i++) {
        solve(i, 1, vector <int> (0));
    }
    return 0;
}
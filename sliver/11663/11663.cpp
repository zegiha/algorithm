#include <iostream>
#include <algorithm>

using namespace std;

int n, m, dot[100'001], line[100'001][2];

pair <int, int> get_dot_idx(int target) {
    int start = 0, end = n - 1, mid;

    while(start <= end) {
        mid = (start + end) / 2;

        if(target < dot[mid]) {
            end = mid - 1;
        } else if(dot[mid] < target) {
            start = mid + 1;
        } else {
            return {mid, mid};
        }
    }
    
    return {start, end};
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> dot[i];
    for(int i = 0; i < m; i++) cin >> line[i][0] >> line[i][1];

    sort(dot, dot + n);
    dot[n] = 2'100'000'000;

    for(int i = 0; i < m; i++) {
        pair <int, int> from = get_dot_idx(line[i][0]), to = get_dot_idx(line[i][1]);

        // cout << from.first << ' ' << from.second << "  ||  " << to.first << ' ' << to.second << '\n';

        int ans = to.first - from.first;
        if(to.first == to.second) ans++;

        cout << ans << '\n';
    }
}
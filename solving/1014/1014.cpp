#include <iostream>
#include <vector>

using namespace std;

int dp[1025], arr[12], m, n, ans;
bool vis[12];
vector <int> comb;

void init() {
    for(int i = 0; i < 12; i++) {
        arr[i] = 0;
        vis[i] = false;
        for(int j = 0; j < 1025; j++) dp[i] = -1;
    }
    comb.clear();
    ans = -1;
}

void makeCombination(int idx) {
    if(idx > m) {
        int sum = 0;
        for(auto i : comb) {
            sum += arr[i];
            // cout << i << ' ';
        }
        // cout << '\n';

        ans = max(ans, sum);

        return;
    }

    makeCombination(idx + 1);

    if(vis[idx]) return;

    int l = max(idx - 1, 1), r = min(idx + 1, m);
    bool prevVisL = vis[l], prevVisR = vis[r];
    vis[idx] = vis[l] = vis[r] = true;
    comb.push_back(idx);

    makeCombination(idx + 1);

    comb.pop_back();
    vis[idx] = false;
    vis[l] = prevVisL;
    vis[r] = prevVisR;
}

void solve() {
    init();
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string t; cin >> t;

        for(int j = 1; j <= m; j++) {
            arr[j] += t[j-1] == '.' ? 1 : 0;
        }
    }
    // cout << "check : ";
    // for(int i = 1; i <= m; i++) cout << arr[i] << ' ';
    // cout << '\n';

    makeCombination(1);
    // cout << " : ";
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 100;
    long long sum = 1;
    while(t > 0) {
        sum *= (long long)t;
        t -= 6;
    }
    cout << sum;
    // int t; cin >> t;
    // while(t--) solve();
}
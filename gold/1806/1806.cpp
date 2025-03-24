#include <iostream>

using namespace std;
using ll = long long;

ll n, s, arr[100'001], ans = 4'200'000'000;

int main() {
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> arr[i];

    ll l = 0, r = 0, sum = arr[0];

    while(r < n) {
        // cout << l << ' ' << r << ' ' << sum << '\n';
        if(s <= sum) ans = min(ans, r - l + 1);
        if(l >= r) {
            r++;
            sum += arr[r];
        }
        else {
            if(sum < s) {
                r++;
                sum += arr[r];
            }
            else {
                sum -= arr[l];
                l++;
            }
        }
    }

    if(ans != 4'200'000'000) cout << ans;
    else cout << 0;
}
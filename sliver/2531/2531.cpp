#include <iostream>

using namespace std;

int arr[30'001], n, d, k, c, eat[3001], cnt, ans;

int main() {
    cin >> n >> d >> k >> c; c--;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    int idx;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            for(int j = 0; j < k; j++) {
                idx = (i + j) % n;
                if(eat[arr[idx]] == 0) cnt++;
                eat[arr[idx]]++;
            }
        } else {
            idx = (i + k-1) % n;
            if(eat[arr[idx]] == 0) cnt++;
            eat[arr[idx]]++;
        }

        ans = max(ans, eat[c] == 0 ? cnt + 1 : cnt);

        eat[arr[i]]--;
        if(eat[arr[i]] == 0) cnt--;
    }

    cout << ans;
}
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, arr[1'000'000];

int main() {
    long long start = 2'100'000'000, end = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] < start) start = arr[i];
        if(end < arr[i]) end = arr[i];
    }

    start *= m / n;
    end *= m / n + 1;

    long long mid, ans = 0;
    while(start <= end) {
        mid = (start + end) / 2;

        long long cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += mid / arr[i];
        }

        if(cnt < m) {
            start = mid + 1;
        } else {
            ans = mid;
            end = mid - 1;
        }
    }

    cout << ans;
}
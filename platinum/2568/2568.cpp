#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
pair <int, int> arr[100'001];
vector <int> lis, idx;

int get_idx(int target) {
    int l = 0, r = lis.size()-1, m;

    while(l <= r) {
        m = (l + r) / 2;
        if(target > lis[m]) l = m + 1;
        else r = m - 1;
    }

    return l;
}

void printing(int target, int i, int cnt) {
    if(i < 0) {
        cout << cnt << '\n';
        return;
    }
    if(target != idx[i]) {
        printing(target, i - 1, cnt + 1);
        cout << arr[i].first << '\n';
    } else {
        printing(target - 1, i - 1, cnt);
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + n);

    for(int i = 0; i < n; i++) {
        int target_idx = get_idx(arr[i].second);
        if(target_idx < lis.size()) {
            lis[target_idx] = arr[i].second;
        } else {
            lis.push_back(arr[i].second);
        }
        idx.push_back(target_idx);
    }

    printing(lis.size() - 1, n-1, 0);
}
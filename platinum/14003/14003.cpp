#include <iostream>
#include <vector>

using namespace std;

int n, arr[1'000'001];
vector <int> lis, index, ans;

int get_idx(int target) {
    int l = 0, r = lis.size()-1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(target > lis[mid]) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    index.resize(n);
    for(int i = 0; i < n; i++) {
        int idx = get_idx(arr[i]);
        if(lis.size() == idx)
            lis.push_back(arr[i]);
        else 
            lis[idx] = arr[i];
        index[i] = idx;
    }

    int target = lis.size()-1;
    for(int i = n-1; i >= 0; i--) {
        if(index[i] == target) {
            ans.push_back(i);
            target--;
            if(target == -1) break;
        }
    }

    cout << ans.size() << '\n';
    for(int i = ans.size()-1; i >= 0; i--) cout << arr[ans[i]] << ' ';
}
#include <iostream>
#include <vector>

using namespace std;

int n, m, arr[302], ansValue = 2'100'000'000;
vector <int> ansComb, comb;

bool isMakeable(int target) {
    int sum = 0, cnt = 0, combCnt = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] > target || cnt > m) return false;
        if(sum + arr[i] > target) {
            comb.push_back(combCnt);
            sum = arr[i];
            cnt++;
            combCnt = 1;
        } else {
            sum += arr[i];
            combCnt++;
        }
    }

    if(sum > 0) {
        cnt++;
        comb.push_back(combCnt);
    }
    
    return cnt == m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int left = 1, right = 0, mid;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        right += arr[i];
    }

    while(left <= right) {
        comb.clear();
        mid = (left + right) / 2;
        if(isMakeable(mid)) {
            right = mid - 1;
            if(mid < ansValue) {
                ansValue = mid;
                ansComb = comb;
            }
        } else {
            left = mid + 1;
        }
    }

    cout << ansValue << '\n';
    for(auto v : comb) cout << v << ' ';
    cout << '\n' << isMakeable(1);
}

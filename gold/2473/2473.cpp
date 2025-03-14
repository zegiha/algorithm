#include <iostream>
#include <algorithm>
#include <vector>

#define INF 4'100'000'000

using namespace std;
using ll = long long;

ll n, arr[5001];
pair <ll, vector <int>> ans = {INF, vector <int> (0)};

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    for(int i = 0; i < n; i++) {
        int l = 0, r = n-1;
        ll sum;
        while(l < r) {
            sum = abs(arr[i] + arr[l] + arr[r]);
            ll
                l_sum = abs(arr[i] + arr[l + 1] + arr[r]),
                r_sum = abs(arr[i] + arr[l] + arr[r-1]);
            if(r-1 == i) r_sum = INF;
            if(l+1 == i) l_sum = INF;
            if(sum > min(l_sum, r_sum)) {
                if(l_sum > r_sum) r--;
                else l++;
            } else break;
        }
        if(ans.first > sum) {
            ans = {sum, vector <int> (0)};
            ans.second.push_back(i); ans.second.push_back(l); ans.second.push_back(r);
        }
    }

    for(int i = 0; i < 3; i++) cout << arr[ans.second[i]] << ' ';
}
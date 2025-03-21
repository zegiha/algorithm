#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[100'001];
pair <int, pair <int, int>> ans = {2'100'000'000, {-1, -1}};

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    int l = 0, r = n-1;
    while(l < r) {
        if(abs(arr[l] + arr[r]) < ans.first) 
            ans = {abs(arr[l] + arr[r]), {arr[l], arr[r]}};
        if(arr[l] + arr[r] < 0) l++;
        else if(arr[l] + arr[r] > 0) r--;
        else break;
    }

    cout << ans.second.first << ' ' << ans.second.second;
}
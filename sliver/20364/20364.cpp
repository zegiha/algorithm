#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> arr;

vector <bool> visit;

void solve(int idx) {
    int n = arr[idx], ncp = arr[idx];
    vector <int> way(1, n);
    while(n > 0) {
        if(n % 2 != 0) n--;
        n /= 2;
        if(n > 1) way.push_back(n);
    }

    for(int i = way.size() - 1; i >= 0; i--) {
        if(visit[way[i]]) {
            cout << way[i] << '\n';
            return;
        }
    }

    visit[ncp] = true;

    cout << 0 << '\n';
}

int main() {
    int t, n; cin >> n >> t;
    visit.resize(n + 2, false);
    arr.resize(t);
    for(int i = 0; i < t; i++) {
        cin >> arr[i];
    }
    for(int i = 0; i < t; i++) {
        solve(i);
    }
}
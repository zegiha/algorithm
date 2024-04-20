#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector <vector <int>> arr;

bool dfs(int index, vector <bool>* check, int cnt) {
    // cout << index << "  ||  index" << endl;
    // for(int i = 0; i < n; i++) cout << (*check)[i] << " "; cout << " ||  check\n";
    // cout << cnt << "  ||  cnt\n\n";

    for(int i = 0; i < arr[index].size(); i++) {
        if(!(*check)[arr[index][i]]) {
            (*check)[arr[index][i]] = true;
            if(dfs(arr[index][i], check, cnt + 1)) return true;
            (*check)[arr[index][i]] = false;
        }
    }
    if(cnt >= 5) return true;
    else return false;
}

int main() {
    cin >> n >> m;
    arr.resize(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a].emplace_back(b);
        arr[b].emplace_back(a);
    }
    for(int i = 0; i < n; i++) {
        vector <bool> check; check.resize(n + 1);
        check[i] = true;
        // cout << "****************************************************************************\n";
        if(dfs(i, &check, 1)) {
            cout << 1;
            return 0;
        };
    }

    cout << 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 900'000'000;
int v, e, ans = INF;
vector <vector <int>> arr;

int main() {
    cin >> v >> e;
    arr.resize(v + 1, vector <int> (v + 1, INF));
    int a, b, c;
    for(int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        arr[a-1][b-1] = c;
    }

    for(int k = 0; k < v; k++) {
        for(int i = 0; i < v; i++) {
            for(int j = 0; j < v; j++) {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            if(i == j) continue;
            ans = min(arr[i][j] + arr[j][i], ans);
        }
    }

    if(ans >= INF) {
        cout << -1;
    } else {
        cout << ans;
    }
}
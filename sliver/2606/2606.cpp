#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n, ans, arr[1000][1000];

void dfs() {
    bool check[1001] = {0, };
    stack <int> s;

    s.push(1);
    check[1] = true;
    while(!s.empty()) {
        int peek = s.top(); s.pop();
        for(int i = 1; i <= n; i++) {
            if(arr[peek][i] == 1 && !check[i]) {
                check[i] = 1;
                s.push(i);
                ans++;
            }
        }
    }
}

int main() {
    int t;
    cin >> n >> t;
    for(int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

   dfs();
   cout << ans;
}
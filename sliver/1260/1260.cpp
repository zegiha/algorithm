#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int n, m, root;
vector <vector <int>> arr;

void dfs() {
    vector <bool> check; check.resize(n + 2);
    stack <int> s;
    check[root] = true;
    s.push(root);
    cout << root << ' ';

    while(!s.empty()) {
        int peek = s.top(); s.pop();

        for(int i = 1; i <= n; i++) {
            if(arr[peek][i] == 1 && !check[i]){
                check[i] = true;
                s.push(i);
                cout << i << ' ';
                break;
            }
        }
    }
}

void bfs() {
    vector <bool> check; check.resize(n + 2);
    queue <int> q;
    check[root] = true;
    q.push(root);
    cout << root << ' ';

    while(!q.empty()) {
        int peek = q.front(); q.pop();

        for(int i = 1; i <= n; i++) {
            if(arr[peek][i] == 1 && !check[i]) {
                check[i] = true;
                q.push(i);
                cout << i << ' ';
            }
        }
    }
}

int main() {
    int x, y;
    vector <bool> tmpCheck;
    cin >> n >> m >> root;
    arr.resize(n + 2);
    tmpCheck.resize(n + 2);
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        if(!tmpCheck[x]) {
            arr[x].resize(n + 2);
            tmpCheck[x] = true;
        }
        if(!tmpCheck[y]) {
            arr[y].resize(n + 2);
            tmpCheck[y] = true;
        }
        arr[x][y] = 1;
        arr[y][x] = 1;
    }

    dfs(); cout << endl;
    bfs();
}
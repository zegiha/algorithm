#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector <int> tree, arr;

int getOp(int a) {
    if(a > 0) return 1;
    else if(a < 0) return -1;
    return 0;
}

int makeTree(int node, int start, int end) {
    if(start == end) return tree[node] = getOp(arr[start]);

    int mid = (start + end) / 2;
    int l = makeTree(node * 2, start, mid), r = makeTree(node * 2 + 1, mid + 1, end);

    return tree[node] = getOp(l * r);
}

bool isArea(int s, int e, int t) {
    return s <= t && t <= e;
}

int changeEl(int node, int start, int end, int idx) {
    if(isArea(start, end, idx)) {
        if(start == end) return tree[node] = getOp(arr[start]);

        int mid = (start + end) / 2;
        int l = changeEl(node * 2, start, mid, idx), r = changeEl(node * 2 + 1, mid + 1, end, idx);

        return tree[node] = getOp(l * r);
    } else return tree[node];
}

int getArea(int node, int s, int e, int ts, int te) {
    if(isArea(ts, te, s) && isArea(ts, te, e)) {
        return tree[node];
    } else if(isArea(ts, te, s) || isArea(ts, te, e) || (isArea(s, e, ts) && isArea(s, e, te))) {
        int m = (s + e) / 2;
        int l = getArea(node * 2, s, m, ts, te), r = getArea(node * 2 + 1, m + 1, e, ts, te);
        return getOp(l * r);
    } else {
        return 1;
    }
}

void solve(int n) {
    tree.clear();
    arr.clear();

    string ans = "";
    int k, a, b, treeHeight;
    char cmd;
    cin >> k;
    arr.resize(n + 1);
    for(int i = 0; i < n; i++) cin >> arr[i];

    treeHeight = ceil(log2(n));
    tree.resize(1 << (treeHeight + 1));

    makeTree(1, 0, n - 1);

    while(k--) {
        cin >> cmd >> a >> b;
        if(cmd == 'C') {
            a--;
            arr[a] = b;
            changeEl(1, 0, n-1, a);
        } else {
            a--; b--;
            int t = getArea(1, 0, n-1, a, b);
            if(t > 0) {
                ans += "+";
            } else if(t < 0) {
                ans += "-";
            } else {
                ans += "0";
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    while(cin >> t) {
        solve(t);
    }
}
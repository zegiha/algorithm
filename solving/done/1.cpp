#include <iostream>
#include <vector>
#include <cmath>

#define MAX 1000000

using namespace std;
using ll = long long;

vector <ll> st;

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int height = (int)ceil(log2(MAX));
    st.resize(1 << (height + 1));
}

int qSt(int n, int s, int e, int v) {
    if(s == e) return s;

    int m = (s + e) / 2;
    if(st[n * 2] >= v) return qSt(n * 2, s, m, v);
    else return qSt(n * 2 + 1, m + 1, e, v - st[n * 2]);
}

void uSt(int n, int s, int e, int idx, int v) {
    if(idx < s || idx > e) return;
    st[n] += (ll)v;

    if(s != e) {
        int m = (s + e) / 2;
        uSt(n * 2, s, m, idx, v);
        uSt(n * 2 + 1, m + 1, e, idx, v);
    }
}

int main() {
    init();

    int t; cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b;
        if(a == 1) {
            int res = qSt(1, 1, MAX, b);
            cout << res << '\n';
            b = res;
            c = -1;
        } else cin >> c;
        uSt(1, 1, MAX, b, c);
    }
}
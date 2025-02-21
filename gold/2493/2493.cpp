#include <iostream>
#include <stack>

using namespace std;

int n, arr[500'001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    stack <pair <int, int>> s;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    int i = 0;
    while(i < n) {
        int h = arr[i];
        if(s.empty()) {
            cout << 0 << ' ';
            s.push({h, i++});
        } else {
            if(s.top().first <= h) s.pop();
            else {
                cout << s.top().second + 1 << ' ';
                s.push({h, i++});
            }
        }
    }
}
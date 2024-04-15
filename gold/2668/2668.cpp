#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, ans;
vector <int> arr;

int main() {
    cin >> n;
    arr.resize(n + 2);
    for(int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        arr[i] = tmp;
    }

    // for(int i = 1; i <= n; i++) {
    //     cout << arr[i] << "  || arr[i]  " << i << "  ||  i" << endl;
    // }

    vector <bool> check, ansArr;
    check.resize(n + 2);
    ansArr.resize(n + 2);
    for(int i = 1; i <= n; i++) {
        if(!check[i]) {
            check[i] = true;
            stack <int> s;
            vector <bool> visit;
            visit.resize(n + 2);
            visit[i] = true;
            s.push(arr[i]);
            // cout << i << "  ||  i" << endl;
            // cout << arr[i] << "  || arr[i]" << endl;
            while(!s.empty()) {
                int item = s.top(); s.pop();
                if(visit[item]) {
                    if(item == i) {
                        // cout << item << "  ||  loop" << endl;
                        int cnt = 0;
                        for(int j = 1; j <= n; j++) {
                            if(visit[j]) {
                                ansArr[j] = true;
                                check[j] = true;
                                cnt++;
                            }
                        }
                        ans += cnt;
                    }
                } else {
                    // cout << item << "  ||  item" << endl;
                    visit[item] = true;
                    s.push(arr[item]);
                }
            }
            // for(int i = 1; i <= n; i++) {
            //     cout << check[i] << ' ';
            // } cout << endl;
        }
    }

    cout << ans << endl;
    for(int i = 1; i <= n; i++) {
        if(ansArr[i]) cout << i << endl;
    }
}
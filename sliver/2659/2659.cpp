#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> cn_arr;

bool is_made(int cn) {
    for(int i = 0; i < cn_arr.size(); i++) {
        if(cn_arr[i] == cn) return true;
    }
    return false;
}
int get_cn(int n) {
    int res = 2'100'000'000, test = 3;
    vector <int> arr(4);
    while(n > 0) {
        arr[test] = n % 10;
        n /= 10;
        test--;
    }
    for(int i = 0; i < 4; i++) {
        int t = 0;
        for(int j = 0; j < 4; j++) {
            t *= 10;
            t += arr[(i + j) % 4];
        }
        if(t < res) res = t;
    }
    return res;
}
void set_cn_arr(int depth, int n) {
    if(depth == 4) {
        int cn = get_cn(n);
        if(!is_made(cn)) {
            cn_arr.push_back(cn);
        }
        return;
    }

    for(int i = 1; i <= 9; i++) {
        n *= 10;
        n += i;
        set_cn_arr(depth + 1, n);
        n -= i;
        n /= 10;
    }
}

int main() {
    set_cn_arr(0, 0);
    sort(cn_arr.begin(), cn_arr.end());

    int n = 0, t;
    for(int i = 0; i < 4; i++) {
        cin >> t;
        n *= 10;
        n += t;
    }
    int cn = get_cn(n);
    for(int i = 0; i < cn_arr.size(); i++) {
        if(cn == cn_arr[i]) {
            cout << i + 1;
            break;
        }
    }

    // int arr[] = {1, 2, 3, 4};
    // for(int i = 0; i < 4; i++) {
    //     int t = 0;
    //     for(int j = 0; j < 4; j++) {
    //         t *= 10;
    //         t += arr[(i + j) % 4];
    //     }
    //     cout << t << ' ' << get_cn(t) << '\n';
    // }
}

#include <iostream>
#include <string>

using namespace std;

int arr[80][80], n = 80;

string del_comma(string a) {
    string res = "";
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != ',') {
            res += a[i];
        }
    }
    return res;
}

int main() {
    for(int i = 0; i < n; i++) {
        string a; cin >> a;
        a = del_comma(a);
        int idx = 0;
        for(int j = 0; j < n; j++) {
            int res = 0;
            while(a[idx] != ' ' && idx < a.size()) {
                res *= 10;
                res += a[idx++]-'0';
            }
            arr[i][j] = res;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << arr[i][j] << ' ';
        cout << '\n';
    }
}
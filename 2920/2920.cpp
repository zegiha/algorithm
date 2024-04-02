#include <iostream>
using namespace std;

int main() {
    bool a = true, d = true;
    for(int i = 0; i < 8; i++) {
        int tmp;
        cin >> tmp;
        if(tmp != i + 1) a = false;
        if(tmp != 8 - i) d = false;
    }
    if(a) cout << "ascending";
    else {
        if(d) cout << "descending";
        else cout << "mixed";
    }
}
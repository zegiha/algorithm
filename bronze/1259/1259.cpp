#include <iostream>
using namespace std;

bool hasPattern(string str) {
    for(int i = 0; i < str.length(); i++) {
        if(str[i] != str[str.length() - 1 - i]) return false;
    }
    return true;
}

int main() {
    while(1) {
        string str;
        cin >> str;
        if(str != "0") {
            if(hasPattern(str)) cout << "yes\n";
            else cout << "no\n";
        } else break;
    }
}
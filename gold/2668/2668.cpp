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
        arr[tmp] = i;
    }
}
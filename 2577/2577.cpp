#include <iostream>
using namespace std;

int main() {
    int a, b, c, sum = 0, ans[10] = {0, };
    cin >> a >> b >> c;
    sum = a * b * c;

    while(sum != 0) {
        ans[sum % 10]++;
        sum /= 10;
    }
    for(int i = 0; i <= 9; i++) cout << ans[i] << endl;
}
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int h, w, n;
        cin >> h >> w >> n;

        int ansH = n % h, ansW = n / h + 1;
        if(n % h == 0) {
            ansH = h;
            ansW--;
        }

        printf("%d%02d\n", ansH, ansW);
    }
}
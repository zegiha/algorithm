//https://www.acmicpc.net/problem/1052

#include <stdio.h>

int n, k, maxBinary = 1, ans;

int main() {
    scanf("%d %d", &n, &k);

    //get maxBinaryNumber
    while(maxBinary * 2 < n) maxBinary *= 2;

    //make n to smallest
    while(k > 1){
        if(n > maxBinary) {
            n -= maxBinary;
            k--;
            // printf("n: %d  |  maxBinary: %d  |  k: %d\n", n, maxBinary, k);
        } else {
            maxBinary /= 2;
        }
    }

    maxBinary = 1;
    while(maxBinary < n) maxBinary *= 2;

    ans = maxBinary - n;
    printf("%d", ans);

    return 0;
}
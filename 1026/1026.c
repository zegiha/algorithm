#include <stdio.h>
int n, a[51], b[51], cnt;


int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int temp;
            if(a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            if(b[i] < b[j]) {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++) cnt += a[i] * b[i];
    printf("%d", cnt);

    return 0;
}
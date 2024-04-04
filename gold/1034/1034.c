#include <stdio.h>
#include <string.h>

int main() {
    int n, m, k, big = 0, cnt = 0, arrN[51] = {0,};
    char arr[51][51];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
        for(int j = 0; j < strlen(arr[i]); j++) {
            if(arr[i][j] == '0') arrN[i]++;
        }
    }
    // printf("%d", arrN[0]);
    scanf("%d", &k);

    for(int i = 0; i < n; i++) {
        if(k >= arrN[i] && (k - arrN[i]) % 2 == 0) {
            // printf("%d ", i);
            for(int j = i; j < n; j++) {
                if(strcmp(arr[i], arr[j]) == 0) {
                    cnt++;
                }
            }
            if(cnt > big) big = cnt;
            // printf("%d\n", cnt);
            cnt = 0;
        }
    }
    printf("%d", big);
}
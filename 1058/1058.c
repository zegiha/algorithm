#include <stdio.h>

int n, arr[51][51], ans, cnt, check[51];

int isBoth(int basic, int i) {
    if(basic == i) return 1;
    if(arr[basic][i] == 1) return 1;
    return 0;
}

void getConnectedNode(int i, int basic) {
    for(int j = 0; j < n; j++) {
        if(arr[i][j] == 1 && check[j] == 0 && isBoth(basic, i)) {
            check[j] = 1;
            cnt++;
            getConnectedNode(j, basic);
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        char tmp[51];
        scanf("%s", tmp);
        for(int j = 0; j < n; j++) {
            if(tmp[j] == 'N') arr[i][j] = 0;
            else arr[i][j] = 1;
        }
    }
    for(int i = 0; i < n; i++){
        check[i] = 2;
        getConnectedNode(i, i);
        if(cnt > ans) ans = cnt;
        cnt = 0;
        for(int j = 0; j < n; j++) check[j] = 0;
    }
    printf("%d", ans);
}
// https://www.acmicpc.net/problem/15649

#include <stdio.h>

int n, m, ans[9], sw[9];

void solve(int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
        return;
    } else {
        for(int i = 1; i <= n; i++) {
            if(!sw[i]) {
                sw[i] = 1;
                ans[cnt] = i;
                solve(cnt + 1);
                sw[i] = 0;
            }
        }
    }
}

int main() {
    scanf("%d %d",&n, &m);
    solve(0);
}
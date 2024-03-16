#include <stdio.h>
int main() {
    int a[51][51], b[51][51], n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) scanf("%d", a[i][j]);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) scanf("%d", b[i][j]);
    }

    
}
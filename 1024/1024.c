#include <stdio.h>
int main() {
    int n, l;
    scanf("%d %d", &n, &l);
    
    for(int i = l; i <= 100; i++) {
        double fst = ((double)n / (double)i) - ((double)(i - 1) / 2.0);
        if((int)fst == fst && fst >= 0) {
            for(int j = 0; j < i; j++) {
                printf("%d ", (int)fst + j);
            }
            return 0;
        }
    }
    printf("-1");
    return 0;
}
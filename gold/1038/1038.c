#include <stdio.h>

int n, x[11];

void solve(int pivot, int i) {
    if(n < 0) {
        return;
    }

    // printf("%d %d\n", x[i] + 1, x[i + 1]);
    if(x[i] + 1 < x[i + 1]) {
        if(i == 0) {
            n--;
            x[i]++;
            solve(pivot, i);
        } else {
            x[i]++;
            solve(pivot, i - 1);
        }
    } else {
        if(i != pivot) {
            x[i] = i - 1;
            solve(pivot, i + 1);
        } else{
            if(pivot < 9) {
                for(int j = 0; j <= i + 1; j++) x[j] = j - 1;
                solve(pivot + 1, i + 1);
            } else {
                x[10] = -1;
                return;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    
    for(int i = 0; i < 11; i++) x[i] = 10;
    x[0] = -1;
    solve(0, 0);
    if(x[10] != -1) {
        for(int i = 9; i >= 0; i--) {
            if(x[i] != 10) printf("%d", x[i]);
        }
    } else printf("-1");
}

    // if(i != pivot || pivot == 0) {
    //     printf("!= pivot  |  ");
    //     if(i != 0) {
    //         if(x[i] + 1 < x[i + 1]) {
    //             printf("!= 0  |  isn big  |  ");
    //             x[i]++;
    //             printf("\n");
    //             solve(i - 1, pivot);
    //         } else{
    //             printf("!= 0  |  is big  |  ");
    //             x[i] = i;
    //             return;
    //         }
    //     } else{
    //         if(x[i] + 1 < x[i + 1]) {
    //             printf("isn big  |  ");
    //             x[i]++;
    //             n--;
    //             printf("\n");
    //             solve(i, pivot);
    //         } else{
    //             printf("is big  |  ");
    //             x[i] = 0;
    //             return;
    //         }
    //     } 
    // } else {
    //     printf("== pivot  |  ");
    //     if(x[i] + 1 < x[i + 1]) {
    //         printf("isn big  |  ");
    //         x[i]++;
    //         printf("\n");
    //         solve(i - 1, pivot);
    //     } else{
    //         printf("is big  |  ");
    //         for(int j = 0; j <= i; j++) x[j] = j;
    //         printf("\n");
    //         solve(i, pivot + 1);
    //     }
    // }
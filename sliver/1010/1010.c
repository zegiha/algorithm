// #include <stdio.h>

// int cnt;

// void solve(int b, int s, int i) {
//     if(i >= b) return;
//     if(s == 1) {
//         cnt++;
//         //printf("cnt: %d %d %d\n", b, s, i);
//         solve(b, s, i + 1);
//         return;
//     }
//     //printf("A: %d %d %d\n", b, s, i);
//     solve(b, s - 1, i + 1);
//     //printf("B: %d %d %d\n", b, s, i);
//     solve(b, s, i + 1);
// }

// int main() {
//     int t;
//     scanf("%d", &t);
//     while (t--)
//     {
//         int b, s;
//         scanf("%d %d", &b, &s);
//         if(b < s) {
//             int temp = b;
//             b = s;
//             s = temp;
//         }
//         solve(b, s, 0);
//         printf("%d\n", cnt);
//         cnt = 0;
//     }   
    
// }

#include <stdio.h>

int main() {
    int t;
    while(t--) {
        int n, m, ans = 0;
        scanf("%d %d", &n, &m);
        ans = 1;
        for(int i = 0; i < n; i++) {
            ans *= m - i;
            ans /= 1 + i;
        }
        printf("%d\n", ans);
    }
}
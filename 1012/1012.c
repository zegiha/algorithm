#include <stdio.h>

int arr[55][55], n, row, col;

void delVege(int i, int j) {
    if(arr[i][j] != 1) return;
    arr[i][j] = 0;
    if(i + 1 < row) delVege(i + 1, j);
    if(i - 1 >= 0) delVege(i - 1, j);
    if(j + 1 < col) delVege(i, j + 1);
    if(j - 1 >= 0) delVege(i, j - 1);
    n--;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int cnt = 0;
        //get map size and vegetable's number
        scanf("%d %d %d", &row, &col, &n);

        //get vegetable
        for(int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            arr[x][y] = 1;
        }

        int i = 0, j = 0;
        while(n) {
            if(arr[i][j] == 1) {
                delVege(i, j);
                cnt++;
            }
            if(j >= col) {
                j = 0;
                i++;
            } else {
                j++;
            }
        }
        printf("%d\n", cnt);
    }
}
#include <stdio.h>

int q[1002], back;

void popLeft() {
    for(int i = 0; i < back - 1; i++){
        int temp = q[i];
        q[i] = q[i + 1];
        q[i + 1] = temp;
    }
    back--;
}
void push(int e) {
    q[back] = e;
    back++;
}

int main() {
    int nodeMap[100][100], n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        nodeMap[y][x] = 1;
        nodeMap[y][0]++;
    }
    for(int i = 1; i <= n; i++) {
        if(!nodeMap[i][0]) {
            push(i);
            for(int j = 1; j <= n; j++) if(nodeMap[j][i] == 1) push(j);
            
        }
    }
    return 0;
}
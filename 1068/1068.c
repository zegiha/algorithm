#include <stdio.h>

int n, node[51][51], del, leafnode;

void getLeafnode(int i) {
    int sw = 1;
    for(int j = i + 1; j < n; j++) {
        if(node[i][j] && j != del) {
            sw = 0;
            getLeafnode(j);
        }
    }
    if(sw) leafnode++;
}

int main() {
    scanf("%d", &n);
    int tmpArr[51];
    for(int i = 0; i < n; i++) scanf("%d", &tmpArr[i]);
    for(int i = 0; i < n; i++) {
        if(tmpArr[i] != -1) node[tmpArr[i]][i]++; 
    }
    scanf("%d", &del);

    if(del != 0) getLeafnode(0);
    printf("%d", leafnode);
}
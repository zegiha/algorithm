#include <stdio.h>
#include <string.h>

int n, arrIndex[55];
char string, ans[20002][50], arr[55][20002];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", string);
        int len = strlen(string);
        strcpy(arr[len][arrIndex[len]], string);
        arrIndex[len]++;
    }
    for(int i = 1; i <= 8; i++) {
        
    }
}
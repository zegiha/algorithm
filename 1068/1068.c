#include <stdio.h>

int N, arr[51], del;
typedef struct stackType {
    int e[51];
    int top;
} stackType;

void push(stackType* stack, int element) {
    stack -> e[++stack -> top] = element;
}

void getLeafnode(int i, stackType stack) {
    for(int index = i + 1; index < N; index++) {
        if(arr[index] == i && index != del) {
            push(&stack, index);
        }
    }

}

int main() {
    scnaf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
    scanf("%d", &del);

    stackType stack;
    stack.top = -1;
    getLeafnode(0, stack);
}
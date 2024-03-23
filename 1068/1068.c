#include <stdio.h>

int N, node[51], del, ans = 0;
typedef struct stackType {
    int e[51];
    int top;
} stackType;

int isFull(stackType* stack) {
    if(stack->top >= N - 1) return 1;
    else return 0;
}
int isEmpty(stackType* stack) {
    if(stack->top <= -1) return 1;
    else return 0;
}
void push(int element, stackType* stack) {
    if(!isFull(stack)) stack->e[++stack->top] = element;
}
void pop(stackType* stack) {
    if(!isEmpty(stack)) stack->e[stack->top--] = 0;
}

void getLeafnode(stackType* stack) {
    int sw = 1;
    if(isEmpty(stack)) {
        return;
    }
    for(int i = 0; i < N; i++) {
        if(node[i] == stack->e[stack->top] && i != del) {
            // printf("%d %d\n", stack->top, node[i]);
            push(i, stack);
            getLeafnode(stack);
            pop(stack);
            sw = 0;
        }
    }
    if(sw) ans++;
}

int main() {
    int root;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &node[i]);
        if(node[i] == -1) root = i;
    }
    scanf("%d", &del);

    stackType stack;
    stack.top = -1;
    if(del != root) push(root, &stack);
    getLeafnode(&stack);
    printf("%d", ans);
}
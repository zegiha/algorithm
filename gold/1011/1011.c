#include <stdio.h>
#include <math.h>

int TC = 0;
int x, y, length, d = 0;
int move_count = 0;

int main(void) {
    scanf("%d", &TC);
    for(int i = 0; i < TC; i++) {
        scanf("%d %d", &x, &y);
        length = y - x;
        d = sqrt(length); // 1. 제곱근 계산
        if(d*d == length) move_count = 2 * d - 1;
        else move_count = 2 * d;
        // d*d == length ? move_count = 2 * d - 1 : move_count = 2 * d; // 2. 제곱 수 case
        if (length > d * (d + 1)) move_count += 1; // 3. 중간 값 case
        printf("%d\n", move_count);
    }
}
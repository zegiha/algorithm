#include <stdio.h>
#include <math.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int loc[2][2], cnt = 0, n;
        scanf("%d %d %d %d", &loc[0][0], &loc[0][1], &loc[1][0], &loc[1][1]);
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            int x, y, r, startIn = 0, endIn = 0, distance;
            scanf("%d %d %d", &x, &y, &r);

            //check x
            distance = sqrt(pow((double)(x - loc[0][0]), 2.0) + pow((double)(y - loc[0][1]), 2.0));
            if(distance < (double)r) startIn++;
            //check y
            distance = sqrt(pow((double)(x - loc[1][0]), 2.0) + pow((double)(y - loc[1][1]), 2.0));
            if(distance < (double)r) endIn++;

            if(startIn != endIn) cnt++;
        }
        printf("%d\n", cnt);
    }
    
}
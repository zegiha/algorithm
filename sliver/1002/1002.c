#include <stdio.h>
#include <math.h>

int main() {
    int t;
    double fst[3], sed[3];
    scanf("%d", &t);
    
    for(int i = 0; i < t; i++) {
        int tmp1, tmp2;
        double sum, distance, smallTmp, bigTmp;
        scanf("%lf %lf %d %lf %lf %d", &fst[0], &fst[1], &tmp1, &sed[0], &sed[1], &tmp2);

        smallTmp = tmp1 < tmp2 ? (double)tmp1 : (double)tmp2;
        bigTmp = tmp1 > tmp2 ? (double)tmp1 : (double)tmp2;
        sum = (double)tmp1 + (double)tmp2;
        distance = sqrt(pow(fst[0] - sed[0], 2.0) + pow(fst[1] - sed[1], 2.0));

        if(distance == 0 && tmp1 == tmp2) printf("-1\n");
        else if(distance < sum && ((bigTmp - smallTmp) < distance)) printf("2\n");
        else if(distance == sum || (bigTmp - smallTmp) == distance) printf("1\n");
        else printf("0\n");
    }

    return 0;
}
#include <stdio.h>
 
int main(void){
    int M,N,X1,Y1,E1,N1,F1,X2,Y2,E2,N2,F2;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d", &M,&N,&X1,&Y1,&E1,&N1,&F1,&X2,&Y2,&E2,&N2,&F2);
    for (int t = 1; t <= F1 || t <= F2; t++) {
        if (t <= F1) {
            if (t%(E1+N1) <= N1 && t%(E1+N1) != 0) {
                Y1++;
                Y1 %= N;
            }
            else {
                X1++;
                X1 %= M;
            }
        }
        if (t <= F2) {
            if (t%(E2+N2) <= E2 && t%(E2+N2) != 0) {
                X2++;
                X2 %= M;
            }
            else {
                Y2++;
                Y2 %= N;
            }
        }
        if ((X1 == X2) && (Y1 == Y2)) {
            printf("%d\n", t);
            return 0;
        }
    }
    printf("-1\n");
 
    return 0;
}
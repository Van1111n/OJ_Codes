#include <stdio.h>
#include <math.h>
#define N 500
const double Log2 = 0.30102999566398119521373889472449;

void mul(int a[N], int b){
    int aLen=499;
    while (a[aLen]==0) aLen--;
    aLen++;
    for (int i=0; i<aLen; i++){
        a[i]*=b;
    }
    for (int i=0; i<N; i++){
        if (a[i]>=10){
            if (i!=499) a[i+1]+=a[i]/10;
            a[i]%=10;
        }
    }
    return;
}

void prt(int a[N]){
    for (int k=499; k>=0; k--){
        printf("%d",a[k]);
        if(k%50 == 0) printf("\n");
    }
    return;
}

int main(){
    int p;
    scanf("%d", &p);
    int bitNum = (int)(p * Log2 + 1);
    printf("%d\n", bitNum);
    int a[N]={0};
    a[0]=1;
    for (int i=0; i<p; i++){
        mul(a,2);
    }
    a[0]--;
    prt(a);
    return 0;
}
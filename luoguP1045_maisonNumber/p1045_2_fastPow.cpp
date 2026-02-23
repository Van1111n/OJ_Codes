#include <stdio.h>
#include <math.h>
#define N 500
const double Log2 = 0.30102999566398119521373889472449;

void mul(int a[N], int b[N], int result[N]){
    for (int i=0; i<N; i++){
        result[i]=0;
        for (int j=0; j<=i; j++){
            result[i]+=a[j]*b[i-j];
        }
    }
    for (int i=0; i<N; i++){
        if (result[i]>=10){
            if (i!=499) result[i+1]+=result[i]/10;
            result[i]%=10;
        }
    }
    return;
}

void fast_pow(int a[N], int p, int result[N]){
    int temp[N];

    for (int i=0; i<N; i++){
        result[i] = 0;
    }
    result[0]=1;

    while (p){
        for (int i=0; i<N; i++) {
            temp[i]=result[i];
        }
        if (p%2) mul(temp, a, result);
        p/=2;
        for (int i=0; i<N; i++) {
            temp[i]=a[i];
        }
        mul(temp,temp,a);
    }
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
    int result[N]={0};
    result[0]=1;
    a[0]=2;

    fast_pow(a,p,result);
    result[0]--;
    prt(result);
}
#include <stdio.h>
#include <iomanip>
#define N 50
const double Log2 = 0.30102999566398119521373889472449;

void mul(long long a[N], int b){
    int aLen=49;
    while (a[aLen]==0) aLen--;
    aLen++;
    for (int i=0; i<aLen; i++){
        a[i]*=b;
    }
    for (int i=0; i<N; i++){
        if (a[i]>=10000000000){
            if (i!=49) a[i+1]+=a[i]/10000000000;
            a[i]%=10000000000;
        }
    }
    return;
}

void prt(long long a[N]){
    for (int k=49; k>=0; k--){
        int bit=0;
        long long int n=a[k];
        while(n){
            n/=10;
            bit++;
        }
        for (int i=0; i<10-bit; i++){
            printf("0");
        }
        if (a[k]!=0) printf("%lld",a[k]);
        if(k%5 == 0) printf("\n");
    }
    return;
}

int main(){
    int p;
    scanf("%d", &p);
    int bitNum = (int)(p * Log2 + 1);
    printf("%d\n", bitNum);
    long long a[N]={0};
    a[0]=1;
    for (int i=0; i<p; i++){
        int aLen = 49;
        while (a[aLen] == 0)
            aLen--;
        aLen++;
        for (int i = 0; i < aLen; i++)
        {
            a[i] *= 2;
        }
        for (int i = 0; i < N; i++)
        {
            if (a[i] >= 10000000000)
            {
                if (i != 49)
                    a[i + 1] += a[i] / 10000000000;
                a[i] %= 10000000000;
            }
        }
    }
    a[0]--;
    prt(a);
    return 0;
}
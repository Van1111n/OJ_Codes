#include <iostream>
#define N 2000

void mul(int a[N], int b){
    int aLen=1999;
    while (a[aLen]==0) aLen--;
    aLen++;

    for (int i=0; i<aLen; i++){
        a[i]*=b;
    }
    for (int i=0; i<N; i++){
        if (a[i]>=10){
            a[i+1]+=a[i]/10;
            a[i]%=10;
        }
    }
    return;
}

void prt(int a[N]){
    int k;
    for (k=1999; a[k]==0; k--);
    for (; k>=0; k--) printf("%d",a[k]);
}

int main(){
    int n, m;
    int a[N]={1};
    scanf("%d",&n);
    for (m=1; n >= (m+4)*(m+1)/2; m++);
    int facts[N]={0};
    for (int i=0; i<m; i++){
        facts[i]=i+2;
    }
    int remain=n-(m+3)*m/2;
    while (remain!=0){
        for (int i=m-1; i>=0; i--){
            facts[i]++;
            remain--;
            if (remain==0) break;
        }
    }
    for (int i=0; i<m; i++){
        mul(a,facts[i]);
        printf("%d", facts[i]);
        if (i!=m-1) printf(" ");
    }
    printf("\n");
    prt(a);
}
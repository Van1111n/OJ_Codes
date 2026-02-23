#include <iostream>
#include <cstring>
#define N 4000
#pragma GCC optimize(2)

void add(int num, char c[], int bit){
    c[bit]+=num%10;
    if (c[bit]>=10){
        c[bit]%=10;
        c[bit+1]++;
    }
    c[bit+1]+=num/10;
    for (int i=bit+1; c[i]>=10; i++){
        c[i]%=10;
        c[i+1]++;
    }
}

int main(){
    char a[N], b[N], c[N]={0};
    int aLen, bLen, cLen;
    scanf("%s",a); scanf("%s",b);
    if (a[0] == '0' || b[0] == '0'){
        printf("%d",0);
        return 0;
    }
    aLen=strlen(a), bLen=strlen(b);
    for (int i=aLen-1; i>=0; i--){
        for (int j=bLen-1; j>=0; j--){
            add((a[i]-'0')*(b[j]-'0'), c, aLen-1-i+bLen-1-j);
        }
    }
    cLen=4000;
    while (c[--cLen]==0 && cLen>=0){}
    cLen++;
    for (int i=cLen-1; i>=0; i--){
        printf("%d",c[i]);
    }
}
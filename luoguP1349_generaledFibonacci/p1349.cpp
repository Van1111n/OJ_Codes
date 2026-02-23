#include <iostream>

void matrix_mul(long long a[2][2], long long b[2][2], long long ans[2][2], long long p){
    ans[0][0]=(a[0][0]*b[0][0]%p+a[0][1]*b[1][0]%p)%p;
    ans[0][1]=(a[0][0]*b[0][1]%p+a[0][1]*b[1][1]%p)%p;
    ans[1][0]=(a[1][0]*b[0][0]%p+a[1][1]*b[1][0]%p)%p;
    ans[1][1]=(a[1][0]*b[0][1]%p+a[1][1]*b[1][1]%p)%p;
    return;
}

void matrix_pow(long long m[2][2], long long n, long long ans[2][2], long long p){
    ans[0][0]=1; ans[0][1]=0; ans[1][0]=0; ans[1][1]=1;
    long long temp[2][2];
    while (n){
        for (int i=0; i<2; i++){
            for (int j=0; j<2; j++){
                temp[i][j]=ans[i][j];
            }
        }
        if (n%2) matrix_mul(temp, m, ans, p);
    
        matrix_mul(m,m,temp,p);
        for (int i=0; i<2; i++){
            for (int j=0; j<2; j++){
                m[i][j]=temp[i][j];
            }
        }
        n/=2;
    }
    return;
}

int main(){
    long long p, q, a1, a2, n, m;
    long long a[2][2];
    long long ans[2][2];
    scanf("%lld %lld %lld %lld %lld %lld", &p, &q, &a1, &a2, &n, &m);
    a[0][0]=p; a[0][1]=q; a[1][0]=1; a[1][1]=0;
    if (n==1) {
        printf("%d",a1%m);
        return 0;
    }
    if (n==2) {
        printf("%d",a2%m);
        return 0;
    }
    matrix_pow(a,n-2,ans,m);
    //printf("%lld %lld\n", ans[0][0], ans[0][1]);//调试语句
    printf("%lld", (ans[0][0]*a2+ans[0][1]*a1)%m);
    return 0;
}
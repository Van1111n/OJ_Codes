#include <stdio.h>

int main(){
    long long a, b, p;
    scanf("%lld %lld %lld", &a, &b, &p);
    printf("%lld^%lld mod %lld=", a, b, p);
    long long res = 1;
    while (b){
        if (b%2) res = (res % p) * (a % p) % p;
        a = (a % p) * (a % p) % p;
        b /= 2;
    }
    printf("%lld", res);
    return 0;
}
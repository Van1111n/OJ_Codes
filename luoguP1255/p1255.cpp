#include <iostream>
#define LLU unsigned long long

LLU f(int n){
    if (n==1) return 1;
    if (n==2) return 2;
    return f(n - 1) + f(n - 2);
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%llu", f(n));
}
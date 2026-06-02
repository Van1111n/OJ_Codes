#include <iostream>
#include <climits>
#define LLD signed long long int
#define LLU unsigned long long

using namespace std;

// FIXME:
LLU catalan(LLU n, LLU p){
    LLU c[10005];
    c[0]=1;
    for (int i=1; i<=n; i++){
        c[i]=0;
        for (int j=0; j<i; j++){
            c[i]+=c[j]*c[i-j-1]%p;
            c[i]%=p;
        }
    }
    LLU ret = c[n];
    return ret;
}

int main(){
    LLU n;
    cin >> n;
    LLU c = catalan(n, 100000007);
    cout << c;
    return 0;
}
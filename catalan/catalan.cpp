#include <iostream>
#define LLD signed long long int
#define LLU unsigned long long

using namespace std;

LLU catalan(LLU n, LLU p){
    LLU c = 0;
    for (int i = 1; i <= n; i++) {
        c = (4 * i - 2) / (i + 1) * c % p;
    }
    return c;
}
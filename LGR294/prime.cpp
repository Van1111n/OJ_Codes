#include <cmath>
#include <iostream>

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    FILE* fp = fopen("primes.txt", "w");
    for (int i = 2; i < 10000000; i++) {
        if (isPrime(i)) {
            fprintf(fp, "%d,", i);
        }
    }
    return 0;
}
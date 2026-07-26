#include <iostream>

const int mod = 1000000007;

int main() {
    long long a = 1;
    for (int i=95; i>80; i--) {
        a = a * i % mod;
    }
    std::cout << a;
}
#include <iostream>

using LLU = unsigned long long;

void prt(int* arr, int len) {
    for (int i=1; i<=len; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    // 1-based;
    int *a = new int [n+1], *b = new int[n];
    for (int i=1; i<=n; i++) {
        std::cin >> a[i];
    }
    for (int i=1; i<=n-1; i++) {
        std::cin >> b[i];
    }

    int* req = new int[n], *opr = new int[n+1];
    for (int i=1; i<=n-1; i++) {
        req[i] = ((b[i] - (a[i] + a[i + 1])) % m + m) % m;
    }
    opr[1] = 0;
    for (int i=2; i<=n; i++) {
        opr[i] = ((req[i-1]-opr[i-1]+m) % m + m) % m;
    }

    LLU totOpr = 0;
    for (int i=1; i<=n; i++) {
        totOpr += opr[i];
    }
    std::cout << totOpr;
}
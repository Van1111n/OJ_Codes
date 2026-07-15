#include <iostream>
#include <vector>

const int N = 500; //在OJ上改成5000，本地有栈空间限制
const int M = 1000;

// 以arr[0]为个位，要求最高位之后为全0
void plus(int a[N], int b[N], int res[N]) {
    for (int i=0; i<N; i++) {
        res[i] += a[i] + b[i];
        if (res[i] >= 10) {
            res[i] -= 10;
            res[i + 1]++;
        }
    }
    return;
}

void prt(int a[N]) {
    int i = N - 1;
    while (a[i] == 0) {
        --i;
    }
    while (i>=0) {
        printf("%d", a[i]);
        --i;
    }
    printf("\n");
    return;
}

int main() {
    int m, n;
    std::cin >> m >> n;
    int k = n - m; 
    
    // 求fib_k
    int fibs[M][N] = {0};
    fibs[0][0] = 1;
    fibs[1][0] = 1;

    for (int i=2; i<=k; i++) {
        plus(fibs[i-2], fibs[i-1], fibs[i]);
    }
    prt(fibs[k]);

    return 0;
}
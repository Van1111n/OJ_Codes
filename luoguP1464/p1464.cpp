#include <iostream>

using LLU = unsigned long long;
using LLD = signed long long;

const int n = 21;

using namespace std;

void f(LLD ma[][n][n]) {
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            for (int c = 0; c < n; c++) {
                if (a == 0 || b == 0 || c == 0) {
                    ma[a][b][c] = 1;
                } else if (a < b && b < c) {
                    ma[a][b][c] = ma[a][b][c - 1] + ma[a][b - 1][c - 1] - ma[a][b - 1][c];
                } else {
                    ma[a][b][c] = ma[a - 1][b][c] + ma[a - 1][b - 1][c] + ma[a - 1][b][c - 1] - ma[a - 1][b - 1][c - 1];
                }
            }
        }
    }
}

int main() {
    LLD w[n][n][n] = {0};
    f(w);
    LLD a, b, c;
    while (1) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1) {
            break;
        } else {
            LLD ans;
            if (a <= 0 || b <= 0 || c<= 0) {
                ans = 1;
            } else if (a > 20 || b > 20 || c > 20) {
                ans = w[20][20][20];
            } else {
                ans = w[a][b][c];
            }
            printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, ans);
        }
    }

    return 0;
}
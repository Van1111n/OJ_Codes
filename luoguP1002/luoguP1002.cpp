#include <iostream>

using namespace std;

void prtmatrix(int ** a, int n,int m){
    printf("prt:\n");
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}

int main() {
    long long bx, by, hx, hy;
    scanf("%lld %lld %lld %lld", &bx, &by, &hx, &hy);
    long long** dp = (long long**)malloc((bx + 1) * sizeof(long long*));
    for (long long i = 0; i <= bx; i++) {
        dp[i] = (long long*)malloc((by + 1) * sizeof(long long));
        for (long long j = 0; j <= by; j++) {
            if (i == hx && j == hy 
                || i == hx + 2 && j == hy + 1 
                || i == hx + 1 && j == hy + 2 
                || i == hx - 1 && j == hy + 2 
                || i == hx - 2 && j == hy + 1 
                || i == hx - 2 && j == hy - 1 
                || i == hx - 1 && j == hy - 2 
                || i == hx + 1 && j == hy - 2 
                || i == hx + 2 && j == hy - 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = -1;
            }
        }
        
    }
    //prtmatrix(dp, bx + 1, by + 1);
    dp[0][0]=1;
    for (long long i=0; i<=bx; i++){
        for (long long j=0; j<=by; j++){
            if (dp[i][j]==-1){
                dp[i][j] = (i == 0 ? 0 : dp[i - 1][j]) + (j == 0 ? 0 : dp[i][j - 1]);
            }
        }
    }
    //prtmatrix(dp, bx + 1, by + 1);
    printf("%lld\n", dp[bx][by]);
}
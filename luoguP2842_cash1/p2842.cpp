#include <iostream>
#include <algorithm>
#include <climits>
#define M 10000
#define N 1000

using namespace std;

int main(){
    long long dp[M];
    for (long long i=0; i<M; i++){
        dp[i]=114514;
    }
    long long n, w;
    long long a[N];
    scanf("%lld %lld", &n, &w);
    for (long long i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    dp[0]=0;
    for (long long i=0; i<n; i++){
        dp[a[i]]=1;
    }
    for (long long i=1; i<=w; i++){
        for (long long j=0; j<n; j++){
            if (i - a[j] >= 0 && dp[i - a[j]] != 114514)
                dp[i] = dp[i - a[j]] + 1 < dp[i] ? dp[i - a[j]] + 1 : dp[i];
        }
        //printf("%lld ", dp[i]);
    }
    printf("%lld", dp[w]);
}
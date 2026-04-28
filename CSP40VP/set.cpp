#include <algorithm>
#include <iostream>
#define LLONG long long
#define N 10000
#define M 100
#define SIZE 1000

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    LLONG a[N] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);  // 这里下标从0开始
    }
    int s[N][SIZE] = {0};
    int ssize[M] = {0};
    LLONG fs[M] = {0};
    for (int i = 0; i < m; i++) {
        scanf("%d", &ssize[i]);
        for (int j = 0; j < ssize[i]; j++) {
            scanf("%d", &s[i][j]);
            fs[i] ^= a[s[i][j] - 1];
        }
    }
    int t[N][SIZE] = {0};
    int tsize[M] = {0};
    LLONG ft[M] = {0};
    for (int i = 0; i < m; i++) {
        scanf("%d", &tsize[i]);
        for (int j = 0; j < tsize[i]; j++) {
            scanf("%d", &t[i][j]);
            ft[i] ^= a[t[i][j] - 1];
        }
    }
    for (int i=0; i<m; i++){
        bool seteq=true;
        if (ssize[i]!=tsize[i]){
            seteq=false;
            goto check;
        }
        for (int j=0; j<ssize[i]; j++){
            if (s[i][j]!=t[i][j]){
                seteq=false;
                break;
            }
        }
        check:
        if (seteq==(fs[i]==ft[i])){
            printf("correct\n");
        } else {
            printf("wrong\n");
        }
    }
    return 0;
}
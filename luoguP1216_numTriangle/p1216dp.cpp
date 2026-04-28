#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

void prt_triangle(int** a, int n) {
    printf("Triangle:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int r;
    scanf("%d", &r);
    int** a = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        a[i] = (int*)malloc(r * sizeof(int));
        for (int j=0; j<r; j++){
            a[i][j]=0;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    //prt_triangle(a,r);
    for (int i = 1; i < r; i++) {
        for (int j = 0; j <= i; j++) {
            a[i][j] = max( j - 1 >= 0 ? a[i - 1][j - 1] : 0,  a[i - 1][j] ) + a[i][j];
        }
        //prt_triangle(a,r);
    }
    int ans=0;
    for(int i=0; i<r; i++){
        ans = a[r - 1][i] > ans ? a[r - 1][i] : ans;
    }
    printf("%d\n",ans);
    return 0;
}
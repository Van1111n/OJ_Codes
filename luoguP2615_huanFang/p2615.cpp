#include <cstdio>
#define N 39

int main(){
    int n;
    int huanFang[N][N];
    int r, c;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            huanFang[i][j]=0;
        }
    }
    scanf("%d",&n);
    r=0; c=n/2;
    huanFang[r][c]=1;
    for (int i=2; i<=n*n; i++){
        if (r==0 && c!=n-1){
            r=n-1; c++;
            goto assignment;
        }
        if (r!=0 && c==n-1){
            c=0; r--; goto assignment;
        }
        if (r==0 && c==n-1){
            r++; goto assignment;
        }
        if (r!=0 && c!=n-1){
            if (huanFang[r-1][c+1]==0){
                r--; c++; goto assignment;
            }
            else r++; goto assignment;
        }
        assignment: huanFang[r][c]=i;
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%d",huanFang[i][j]);
            if (j!=n-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
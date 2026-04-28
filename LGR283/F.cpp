#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    int** a = (int**)malloc((m + 1) * sizeof(int*));
    for (int i=0; i<m+1; i++){
        a[i] = (int*)malloc(n * sizeof(int));
    }
    for (int i=0; i<n; i++){
        scanf("%d",&a[0][i]);
    }

    for (int i=0; i<m; i++){
        int x,y;
        scanf("%d %d", &x, &y);
        for (int j=0; j<n; j++){
            a[i+1][j]=a[i][j];
        }
        a[i+1][x-1]=y;
    }

    // debug prt
    /*
    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    */

    while(q--){
        int u,v;
        scanf("%d %d", &u, &v);
        printf("%d\n",a[u-1][v-1]);
    }

}
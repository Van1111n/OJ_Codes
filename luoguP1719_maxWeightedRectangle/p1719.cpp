#include <iostream>

using namespace std;

int main(){
    int n;
    int **a, **s;
    scanf("%d", &n);
    a = (int**)malloc(n * sizeof(int*));
    s = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        a[i] = (int*)malloc(n * sizeof(int));
        s[i] = (int*)malloc(n * sizeof(int));
    }
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
            s[i][j]=a[i][j] + (i > 0 ? s[i-1][j] : 0) + (j > 0 ? s[i][j-1] : 0) - (i > 0 && j > 0 ? s[i-1][j-1] : 0);
        }
    }
    int maxSum;
    for (int i1=0; i1<n; i1++){
        for (int j1=0; j1<n; j1++){
            for (int i2=i1; i2<n; i2++){
                for (int j2=j1; j2<n; j2++){
                    int sum = s[i2][j2] - (i1 > 0 ? s[i1-1][j2] : 0)-(j1 > 0 ? s[i2][j1-1] : 0) + (i1 > 0 && j1 > 0 ? s[i1-1][j1-1] : 0);
                    maxSum = sum > maxSum ? sum : maxSum;
                }
            }
        }
    }
    printf("%d", maxSum);
    return 0;
}
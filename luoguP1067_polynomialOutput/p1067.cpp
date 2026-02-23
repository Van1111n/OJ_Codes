#include <cstdio>
#include <cstdlib>
#include <cmath>

int main(){
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = n; i >= 0; i--){
        scanf("%d", &a[i]);
    }
    for (int i = n; i >= 0; i--){
        if (a[i] == 0){
            continue;
        }
        if (i != n && a[i] > 0){
            printf("+");
        }
        if (a[i] < 0){
            printf("-");
        }
        if (abs(a[i]) != 1 || i == 0){
            printf("%d", abs(a[i]));
        }
        if (i >= 1){
            printf("x");
        }
        if (i >= 2){
            printf("^%d",i);
        }
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    std::sort(a, a+n);
    for (int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
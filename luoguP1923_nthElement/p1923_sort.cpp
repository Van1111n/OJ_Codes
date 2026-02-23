#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, k;
    int *a;
    scanf("%d %d", &n, &k);
    a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    printf("%d", a[k]);
}
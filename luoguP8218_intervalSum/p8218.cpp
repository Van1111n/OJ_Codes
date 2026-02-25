#include <iostream>

using namespace std;

int main(){
    int n, m;
    int *a, *s;
    scanf("%d", &n);
    a=(int*)malloc(n*sizeof(int));
    s=(int*)malloc(n*sizeof(int));
    for (int i=0; i<n; i++){
        scanf("%d", &a[i]);
        s[i] = a[i] + (i > 0 ? s[i - 1] : 0);
    }
    scanf("%d", &m);
    /*
    for (int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int i=0; i<n; i++){
        printf("%d ", s[i]);
    }
    printf("\n");printf("\n");
    */

    int l, r;
    for (int i=0; i<m; i++){
        scanf("%d %d", &l, &r);
        --l;--r;
        int sum = s[r] - (l > 0 ? s[l - 1] : 0);
        printf("%d\n",sum);
    }
}
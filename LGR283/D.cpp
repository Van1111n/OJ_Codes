#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int a[105];
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
        max = a[i] > a[max] ? i : max;
    }
    if (a[0]>a[n-1]){
        std::swap(a[0],a[n-1]);
    } else {
        std::swap(a[max],a[n-1]);
    }
    for (int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    return 0;
}
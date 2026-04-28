#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int a[10005];
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    int aTotal=0, bTotal=0;
    for (int i=0; i<n; i++){
        if (aTotal<=bTotal){
            aTotal+=a[i];
            putchar('A');
        } else {
            bTotal+=a[i];
            putchar('B');
        }
    }
}
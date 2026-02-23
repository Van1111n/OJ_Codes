#include <iostream>
#pragma GCC optimize(2)

using namespace std;

int main(){
    int n; //num of fish
    scanf("%d", &n);
    int a[n];
    int b[n]={};
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
        for (int j=i-1; j>=0; j--){
            if (a[j]<a[i]) b[i]++;
        }
    }
    for (int i=0; i<n; i++){
        printf("%d",b[i]);
        if (i!=n-1) printf(" ");
    }
    return 0;
}
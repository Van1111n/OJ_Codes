#include <iostream>

using namespace std;

int main(){
    int n, k;
    int a[101];
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &k);
    --k;
    if (a[k]==0){
        printf("%d", k+1);
        return 0;
    } else {
        for (int i=0; i<n; i++){
            if (a[i]==0) {
                printf("%d", i+1);
                return 0;
            }
        }
    }
}
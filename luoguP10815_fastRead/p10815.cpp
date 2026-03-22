#include <iostream>

int main(){
    int n;
    scanf("%d", &n);
    int sum=0; 
    int temp;
    for (int i=0; i<n; i++){
        scanf("%d", &temp);
        sum+=temp;
    }
    printf("%d", sum);
}
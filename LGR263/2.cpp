#include <iostream>

int main(){
    int a, sum=0;
    for (int i=0; i<5; i++){
        scanf("%d", &a);
        sum+=a;
    }
    //printf("%d", sum);
    if (0<=sum && sum<=99) printf("Grey");
    if (100<=sum && sum<=119) printf("Blue");
    if (120<=sum && sum<=169) printf("Green");
    if (170<=sum && sum<=229) printf("Orange");
    if (230<=sum && sum<=500) printf("Red");
    return 0;
}
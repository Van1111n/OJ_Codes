#include <bits/stdc++.h>

using namespace std;

int main(){
    for (int i=1; i<=9; i++){
        for (int j=1; j<=9; j++){
            for (int k=1; k<=9; k++){
                printf("%d%d%d,", i, j, k);
            }
        }
        printf("\n");
    }
    return 0;
}
#include <iostream>

int main(){
    int a[4][4];
    int x0, y0;
    bool b[5]={0};
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            scanf("%d", &a[i][j]);
            if (a[i][j]==0){
                x0=i;
                y0=j;
            }
        }
    }
    for (int i=0; i<4; i++){
        b[a[x0][i]]=true;
    }
    for (int i=1; i<=4; i++){
        if (!b[i]) printf("%d", i);
    }
    return 0;
}
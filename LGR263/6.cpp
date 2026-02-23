#include <stdio.h>
#include <math.h>

int main(){
    int h, w;
    int pI[64][64][3], pK[64][64][3];
    scanf("%d %d", &h, &w);
    for (int i=0; i<3; i++){
        for (int j=0; i<h; i++){
            for (int k=0; k<w; k++){
                scanf("%d", &pI[j][k][i]);
            }
        }
    }
    for (int i=0; i<3; i++){
        for (int j=0; i<h; i++){
            for (int k=0; k<w; k++){
                scanf("%d", &pK[j][k][i]);
            }
        }
    }
}
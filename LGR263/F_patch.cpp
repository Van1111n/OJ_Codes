#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main(){
    int w0, h0;
    scanf("%d %d", &h0, &w0);
    int imageI[3][64][64], imageK[3][64][64];
    for (int i=0; i<3; i++){
        for (int j=0; j<h0; j++){
            for (int k=0; k<w0; k++){
                scanf("%d", &imageI[i][j][k]);
            }
        }
    }
    for (int i=0; i<3; i++){
        for (int j=0; j<h0; j++){
            for (int k=0; k<w0; k++){
                scanf("%d", &imageK[i][j][k]);
            }
        }
    }


    int prefixSum[64][64]={0};
    for (int i=0; i<h0; i++){
        for (int j=0; j<w0; j++){
            prefixSum[i][j] +=
                (imageI[0][i][j] - imageK[0][i][j]) * (imageI[0][i][j] - imageK[0][i][j]) 
                + (imageI[1][i][j] - imageK[1][i][j]) * (imageI[1][i][j] - imageK[1][i][j]) 
                + (imageI[2][i][j] - imageK[2][i][j]) * (imageI[2][i][j] - imageK[2][i][j]) 
                + (i > 0 ? prefixSum[i - 1][j] : 0 )
                + (j > 0 ? prefixSum[i][j - 1] : 0 )
                - (i > 0 && j > 0 ? prefixSum[i - 1][j - 1] : 0);
        }
    }

    int sum, minM;
    int hMin=(h0+1)/2, wMin=(w0+1)/2;
    minM=INT_MAX;
    for (int h1=0; h1<h0; h1++){
        for (int w1=0; w1<w0; w1++){
            for (int h2=h1; h2<h0; h2++){
                for (int w2=w1; w2<w0; w2++){
                    if (h2 - h1 + 1 < hMin || w2 - w1 + 1 < wMin) continue;
                    sum = 
                    prefixSum[h2][w2] 
                    - (w1 > 0 ? prefixSum[h2][w1 - 1] : 0) 
                    - (h1 > 0 ? prefixSum[h1 - 1][w2] : 0) 
                    + (h1 > 0 && w1 > 0 ? prefixSum[h1 - 1][w1 - 1] : 0);
                    minM = sum / 3 / (w2 - w1 + 1) / (h2 - h1 + 1) < minM ? sum / 3 / (w2 - w1 + 1) / (h2 - h1 + 1) : minM;
                }
            }
        }
    }
    double psnr = 20 * log10(255 / sqrt((double)minM));
    printf("%lf", psnr);


    return 0;
}
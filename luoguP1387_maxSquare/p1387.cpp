#include <iostream>

using namespace std;

int main(){
    int row, col;
    int **grid, **prefixSum;
    scanf("%d %d", &row, &col);
    grid = (int**)malloc(row * sizeof(int*));
    prefixSum = (int**)malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++) {
        grid[i] = (int*)malloc(col * sizeof(int));
        prefixSum[i] = (int*)malloc(col * sizeof(int));
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            prefixSum[i][j] = (i > 0 ? prefixSum[i-1][j] : 0) + (j > 0 ? prefixSum[i][j-1] : 0) + grid[i][j] - (i > 0 && j > 0 ? prefixSum[i-1][j-1] : 0);
        }
    }  // calculate prefix sum

    int maxSideLength=0;
    for (int sideLength=1; sideLength<=(col<row?col:row); sideLength++){
        for (int i = 0; i + sideLength - 1 < row; i++) {
            for (int j = 0; j + sideLength - 1 < col; j++) {
                int sumSquare = prefixSum[i + sideLength - 1][j + sideLength - 1] - (j > 0 ? prefixSum[i + sideLength - 1][j - 1] : 0) - (i > 0 ? prefixSum[i - 1][j + sideLength - 1] : 0) + (i > 0 && j > 0 ? prefixSum[i - 1][j - 1] : 0);
                //printf("start:(%d, %d), side length:%d, sum:%d\n", i, j, e, sum);
                if (sumSquare==sideLength*sideLength){
                    //printf("found size length:%d\n", e);
                    maxSideLength=sideLength;
                    goto LOOPEND;
                }
            }
        }
        //printf("Not Found\n");
        break;
        LOOPEND:continue;
    }
    printf("%d\n",maxSideLength);
}
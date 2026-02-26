#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n, targetLength;
    int* heights;
    int minHeight, maxHeight, curheight;
    long long curLength;
    minHeight = INT_MAX;
    maxHeight = INT_MIN;
    scanf("%d %d", &n, &targetLength);
    heights = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
        minHeight = heights[i] < minHeight ? heights[i] : minHeight;
        maxHeight = heights[i] > maxHeight ? heights[i] : maxHeight;
    }
    while (maxHeight - minHeight > 1) {
        curheight = (minHeight + maxHeight) / 2;
        curLength = 0;
        for (int i = 0; i < n; i++) {
            curLength += heights[i] > curheight ? heights[i] - curheight : 0;
        }
        //printf("between:%d, %d, height:%d, length:%d\n", minHeight, maxHeight, curheight, curLength);
        if (curLength < targetLength) {
            maxHeight = curheight - 1;
        } else if (curLength > targetLength) {
            minHeight = curheight;
        } else {
            printf("%d\n", curheight);
            return 0;
        }
    }
    if (minHeight == maxHeight) {
        printf("%d\n", minHeight);
        return 0;
    }
    long long maxHeightLength=0;
    for (int i=0; i<n; i++){
        maxHeightLength += heights[i] > maxHeight ? heights[i] - maxHeight : 0;
    }
    if (maxHeightLength>=targetLength) {
        printf("%d\n", maxHeight);
    } else {
        printf("%d\n", minHeight);
    }
    return 0;
}
#include <cmath>
#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n, m;
    long long standard;
    int *weights, *values, *l, *r;
    int weightL = INT_MAX, weightR = INT_MIN;
    scanf("%d %d %lld", &n, &m, &standard);
    weights = (int*)malloc(n * sizeof(int));
    values = (int*)malloc(n * sizeof(int));
    l = (int*)malloc(m * sizeof(int));
    r = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weights[i], &values[i]);
        weightL = weights[i] < weightL ? weights[i] : weightL;
        weightR = weights[i] > weightR ? weights[i] : weightR;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &l[i], &r[i]);
        --l[i];
        --r[i];
    }

    int* weightsPrefixSum;
    long long* valuesPrifixSum;
    weightsPrefixSum = (int*)malloc(n * sizeof(int));
    valuesPrifixSum = (long long*)malloc(n * sizeof(long long));
    int currentWeight;
    long long yl=0, yr=0;

    currentWeight = weightL;
    for (int i = 0; i < n; i++) {
        weightsPrefixSum[i] = (i > 0 ? weightsPrefixSum[i - 1] : 0) + (weights[i] >= currentWeight ? 1 : 0);
        valuesPrifixSum[i] = (i > 0 ? valuesPrifixSum[i - 1] : 0) + (weights[i] >= currentWeight ? values[i] : 0);
    }
    for (int i = 0; i < m; i++) {
        yl += (weightsPrefixSum[r[i]] - (l[i] > 0 ? weightsPrefixSum[l[i] - 1] : 0)) * (valuesPrifixSum[r[i]] - (l[i] > 0 ? valuesPrifixSum[l[i] - 1] : 0));
    }
    //printf("gugugaga:%d %d\n", currentWeight, yl);
    currentWeight = weightR;
    for (int i = 0; i < n; i++) {
        weightsPrefixSum[i] = (i > 0 ? weightsPrefixSum[i - 1] : 0) + (weights[i] >= currentWeight ? 1 : 0);
        valuesPrifixSum[i] = (i > 0 ? valuesPrifixSum[i - 1] : 0) + (weights[i] >= currentWeight ? values[i] : 0);
    }
    for (int i = 0; i < m; i++) {
        yr += (weightsPrefixSum[r[i]] - (l[i] > 0 ? weightsPrefixSum[l[i] - 1] : 0)) * (valuesPrifixSum[r[i]] - (l[i] > 0 ? valuesPrifixSum[l[i] - 1] : 0));
    }
    //printf("gugugaga:%d %d\n", currentWeight, yr);

    while (weightR - weightL > 1) {
        currentWeight = (weightL + weightR) / 2;
        for (int i = 0; i < n; i++) {
            weightsPrefixSum[i] = (i > 0 ? weightsPrefixSum[i - 1] : 0) + (weights[i] >= currentWeight ? 1 : 0);
            valuesPrifixSum[i] = (i > 0 ? valuesPrifixSum[i - 1] : 0) + (weights[i] >= currentWeight ? values[i] : 0);
        }
        long long y = 0;
        for (int i = 0; i < m; i++) {
            y += (weightsPrefixSum[r[i]] - (l[i] > 0 ? weightsPrefixSum[l[i] - 1] : 0)) * (valuesPrifixSum[r[i]] - (l[i] > 0 ? valuesPrifixSum[l[i] - 1] : 0));
        }
        //printf("gugugaga:%d %d\n", currentWeight, y);
        if (y == standard) {
            printf("0");
            return 0;
        }
        if (y > standard) {
            weightL = currentWeight;
            yl = y;
        } else {
            weightR = currentWeight;
            yr = y;
        }
    }
    printf("%lld\n", abs(yl - standard) < abs(yr - standard) ? abs(yl - standard) : abs(yr - standard));
    return 0;
}
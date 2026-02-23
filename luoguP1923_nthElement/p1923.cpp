#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int find_nth_element(int *arr, int nth, int length) {
    if (nth == 0)
        return *arr;
    int pivot = arr[0];
    int i = 0, j = 0, k = length;
    while (i < k) {
        if (arr[i] < pivot) {
            swap(arr[i++], arr[j++]);
        } else if (arr[i] > pivot) {
            swap(arr[i], arr[--k]);
        } else {
            i++;
        }
    }//三路区间交换排序的前半部分

    if (j > nth)
        return find_nth_element(arr, nth, j);
    else if (j == nth)
        return arr[j];
    else
        return find_nth_element(arr + j + 1, nth - j - 1, length - j - 1);
}

int main() {
    int n, k;
    int *a;
    scanf("%d %d", &n, &k);
    a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int res = find_nth_element(a, k, n);
    free(a);
    printf("%d", res);
    return 0;
}
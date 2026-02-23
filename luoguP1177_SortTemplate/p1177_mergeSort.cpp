#include <iostream>

using namespace std;

void my_merge(int a[], int aLen, int b[], int bLen, int res[]) {
    int i = 0, j = 0, k = 0;
    while (i < aLen && j < bLen) {
        if (a[i] <= b[j]) {
            res[k] = a[i];
            i++;
        } else {
            res[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < aLen) {
        res[k++] = a[i++];
    }
    while (j < bLen) {
        res[k++] = b[j++];
    }
}

void merge_sort(int a[], int begin, int end) {
    if (end - begin <= 1)
        return;
    int mid = (begin + end) / 2;
    merge_sort(a, begin, mid);
    merge_sort(a, mid, end);
    int *temp = (int *)malloc(sizeof(int) * (end - begin));
    my_merge(a + begin, mid - begin, a + mid, end - mid, temp);
    for (int i = 0; i < end - begin; i++) {
        a[begin + i] = temp[i];
    }
    free(temp);
}

int main() {
    int *arr;
    int n;
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    merge_sort(arr, 0, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
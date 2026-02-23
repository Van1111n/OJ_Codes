#include <iostream>
#define N 100000

using namespace std;

void quick_sort(int arr[], int len) {
    if (len <= 1) return;
    int m = arr[rand() % len];
    int i = 0, j = 0, k = len;
    while (i < k) {
        if (arr[i] < m)
            swap(arr[i++], arr[j++]);
        else if (arr[i] > m)
            swap(arr[i], arr[--k]);
        else
            i++;
    }
    quick_sort(arr, j);
    quick_sort(arr + k, len - k);
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    quick_sort(a, n);
    for (int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}